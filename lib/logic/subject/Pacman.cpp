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

        if (deathTimer >= DEATH_DURATION) {
            lives--;
            setCoords(spawn);
            dying = false;
            deathTimer = 0.0f;
            facing = RIGHT;
            queuedDirection = RIGHT;
        }
        return;
    }
    speed = (facing == UP || facing == DOWN) ? 0.4f * ASPECT_RATIO : 0.4f;

    auto canMoveTo = [&](const Direction dir) -> bool {
        if (!wallValidator)
            return true;

        Coords p = coords;
        float offset = (dir == UP || dir == DOWN) ? coords.height : coords.width;
        offset *= 0.1f;

        if (dir == UP || dir == DOWN)
            p.x = std::round((p.x + 1.0f) / coords.width) * coords.width - 1.0f;
        else
            p.y = std::round((p.y + 1.0f) / coords.height) * coords.height - 1.0f;
        if (dir == UP)
            p.y -= offset;
        if (dir == DOWN)
            p.y += offset;
        if (dir == LEFT)
            p.x -= offset;
        if (dir == RIGHT)
            p.x += offset;

        return wallValidator(p);
    };

    if (facing != queuedDirection) {
        const float axisValue = (queuedDirection == UP || queuedDirection == DOWN) ? coords.x : coords.y;
        const float gridSize = (queuedDirection == UP || queuedDirection == DOWN) ? coords.width : coords.height;

        const float normalizedPos = (axisValue + 1.0f) / gridSize;
        const float idealIndex = std::round(normalizedPos);
        const float centerPos = (idealIndex * gridSize) - 1.0f;
        const float distance = std::abs(axisValue - centerPos);

        if (distance < (speed * deltaTime * 1.5f) && canMoveTo(queuedDirection)) {
            if (queuedDirection == UP || queuedDirection == DOWN)
                coords.x = centerPos;
            else
                coords.y = centerPos;

            facing = queuedDirection;
        }
    }

    if (!canMoveTo(facing)) {
        const float gridSize = (facing == UP || facing == DOWN) ? coords.height : coords.width;

        const float axisValue = (queuedDirection == UP || queuedDirection == DOWN) ? coords.x : coords.y;

        const float normalizedPos = (axisValue + 1.0f) / gridSize;
        const float idealIndex = std::round(normalizedPos);
        const float centerPos = (idealIndex * gridSize) - 1.0f;

        float currentPos = (facing == UP || facing == DOWN) ? coords.y : coords.x;

        if (std::abs(currentPos - centerPos) < (gridSize * 0.5f)) {
            if (facing == UP || facing == DOWN)
                coords.y = centerPos;
            else
                coords.x = centerPos;
        }
    } else {
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
    }

    notify(std::make_shared<TickEvent>(getCoords(), facing, !canMoveTo(facing)));
}
int subjects::Pacman::getLives() const { return lives; }
void subjects::Pacman::hurt() {
    return;
    if (dying)
        return;
    dying = true;
    deathTimer = 0.0f;
}
bool subjects::Pacman::isDying() const { return dying; }
void subjects::Pacman::setWallValidator(const std::function<bool(const Coords&)>& validator) {
    wallValidator = validator;
}
Direction subjects::Pacman::getFacing() const { return facing; }