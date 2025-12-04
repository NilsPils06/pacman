#include "Pacman.h"

#include "../Event.h"
#include "../Stopwatch.h"
#include "Wall.h"
#include <cmath>

constexpr float ASPECT_RATIO = 16.0f / 9.0f;

bool isOpposite(const Direction a, const Direction b) {
    if (a == UP && b == DOWN) return true;
    if (a == DOWN && b == UP) return true;
    if (a == LEFT && b == RIGHT) return true;
    if (a == RIGHT && b == LEFT) return true;
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

    speed = (facing == UP || facing == DOWN) ? 0.2f * ASPECT_RATIO : 0.2f;

    if (facing != queuedDirection) {
        float axisValue = (queuedDirection == UP || queuedDirection == DOWN) ? coords.x : coords.y;
        float gridSize = (queuedDirection == UP || queuedDirection == DOWN) ? coords.width : coords.height;

        float normalizedPos = (axisValue + 1.0f) / gridSize;
        float idealIndex = std::round(normalizedPos);
        float centerPos = (idealIndex * gridSize) - 1.0f;

        float distance = std::abs(axisValue - centerPos);

        float threshold = (speed * deltaTime) * 1.5f;

        if (blocked)
            threshold = gridSize * 0.5f;


        if (distance < threshold) {
            if (queuedDirection == UP || queuedDirection == DOWN) coords.x = centerPos;
            else coords.y = centerPos;

            facing = queuedDirection;
        }
    }

    blocked = false;
    float correctionSpeed = speed * 2.0f;

    auto alignToCenter = [&](const float& current, const float& step) -> float {
        const float norm = (current + 1.0f) / step;
        const float ideal = std::round(norm);
        const float target = (ideal * step) - 1.0f;
        const float diff = target - current;
        const float move = correctionSpeed * deltaTime;

         if (std::abs(diff) < move) return target;
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

void subjects::Pacman::visit(std::shared_ptr<const Wall> e) {
    speed = 0;
    blocked = true;

    const Coords wall = e->getCoords();

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