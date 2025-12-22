#include "Ghost.h"
#include "../Event.h"
#include "../Stopwatch.h"

#include <cmath>
constexpr float ASPECT_RATIO = 16.f / 9.f;

void subjects::Ghost::tick() {
    // copied from Pacman
    const float deltaTime = Stopwatch::getInstance().getDeltaTime();

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
void subjects::Ghost::block() {
    speed = 0;
    blocked = true;
}
void subjects::Ghost::snapPosition(const Coords& wall) {
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
void subjects::Ghost::accept(std::shared_ptr<CollisionVisitor> visitor) { visitor->visit(shared_from_this()); }