#include "Pacman.h"

#include "../Event.h"
#include "../Stopwatch.h"
#include "Wall.h"
#include <cmath>

constexpr float ASPECT_RATIO = 16.0f / 9.0f;

bool isOpposite(const Direction a, const Direction b) {
    if (a == UP && b == DOWN)
        return true;
    if (a == DOWN && b == UP)
        return true;
    if (a == LEFT && b == RIGHT)
        return true;
    if (a == RIGHT && b == LEFT)
        return true;
    return false;
}

void subjects::Pacman::notify(const std::shared_ptr<Event> e) {
    if (e->getType() == DIRECTION_UPDATE) {
        const std::shared_ptr<DirectionChangeEvent> event = std::static_pointer_cast<DirectionChangeEvent>(e);
        queuedDirection = event->getDirection();
    }
    EntityModel::notify(e);
}

void subjects::Pacman::tick() {
    const float deltaTime = Stopwatch::getInstance().getDeltaTime();
    if (dying) {
        deathTimer += Stopwatch::getInstance().getDeltaTime();
        notify(std::make_shared<DieEvent>(getCoords(), deathTimer, DEATH_DURATION));

        if (deathTimer >= 1.5f) {
            lives--;
            setCoords(spawn);
            dying = false;
            deathTimer = 0.0f;
        }
        return;
    }

    speed = (facing == UP || facing == DOWN) ? 0.3f * ASPECT_RATIO : 0.3f;

    if (facing != queuedDirection) {
        const float axisValue = (queuedDirection == UP || queuedDirection == DOWN) ? coords.x : coords.y;
        const float gridSize = (queuedDirection == UP || queuedDirection == DOWN) ? coords.width : coords.height;

        const float normalizedPos = (axisValue + 1.0f) / gridSize;
        const float idealIndex = std::round(normalizedPos);
        const float centerPos = (idealIndex * gridSize) - 1.0f;

        const float distance = std::abs(axisValue - centerPos);

        float threshold = (speed * deltaTime);

        if (blocked)
            threshold = gridSize * 0.5f;

        if (distance < threshold) {
            if (queuedDirection == UP || queuedDirection == DOWN)
                coords.x = centerPos;
            else
                coords.y = centerPos;

            facing = queuedDirection;
        }
    }

    blocked = false;
    const float correctionSpeed = speed * 2.0f;

    auto alignToCenter = [&](const float& current, const float& step) -> float {
        const float norm = (current + 1.0f) / step;
        const float ideal = std::round(norm);
        const float target = (ideal * step) - 1.0f;
        const float diff = target - current;
        const float move = correctionSpeed * deltaTime;

        if (std::abs(diff) < move)
            return target;
        return current + (diff > 0 ? move : -move);
    };

    switch (facing) {
    case RIGHT:
        coords.x += speed * deltaTime;
        coords.y = alignToCenter(coords.y, coords.height);
        break;
    case UP:
        coords.y -= speed * deltaTime;
        coords.x = alignToCenter(coords.x, coords.width);
        break;
    case DOWN:
        coords.y += speed * deltaTime;
        coords.x = alignToCenter(coords.x, coords.width);
        break;
    case LEFT:
        coords.x -= speed * deltaTime;
        coords.y = alignToCenter(coords.y, coords.height);
        break;
    }

    notify(std::make_shared<TickEvent>(getCoords(), facing));
}
void subjects::Pacman::block() {
    speed = 0;
    blocked = true;
}
void subjects::Pacman::snapPosition(const Coords& wall) {
    switch (facing) {
    case RIGHT:
        coords.x = wall.x - (wall.width / 2.0f) - (coords.width / 2.0f);
        break;
    case LEFT:
        coords.x = wall.x + (wall.width / 2.0f) + (coords.width / 2.0f);
        break;
    case DOWN:
        coords.y = wall.y - (wall.height / 2.0f) - (coords.height / 2.0f);
        break;
    case UP:
        coords.y = wall.y + (wall.height / 2.0f) + (coords.height / 2.0f);
        break;
    }
}
int subjects::Pacman::getLives() const { return lives; }
void subjects::Pacman::hurt() {
    if (dying)
        return;
    dying = true;
    deathTimer = 0.0f;
}
bool subjects::Pacman::isDying() const { return dying; }