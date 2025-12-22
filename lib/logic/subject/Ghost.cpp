#include "Ghost.h"
#include "../Event.h"
#include "../Random.h"
#include "../Stopwatch.h"

#include <cmath>
constexpr float ASPECT_RATIO = 16.f / 9.f;

// TODO return to spawn after pacman dies

void subjects::Ghost::tick() {
    const float deltaTime = Stopwatch::getInstance().getDeltaTime();

    speed = (facing == UP || facing == DOWN) ? 0.3f * ASPECT_RATIO : 0.3f;

    auto isAtCenter = [&](float tolerance = 0.05f) -> bool {
        const float axisValue = (facing == UP || facing == DOWN) ? coords.y : coords.x;
        const float gridSize = (facing == UP || facing == DOWN) ? coords.height : coords.width;

        const float normalizedPos = (axisValue + 1.0f) / gridSize;
        const float idealIndex = std::round(normalizedPos);
        const float centerPos = (idealIndex * gridSize) - 1.0f;

        return std::abs(axisValue - centerPos) < (speed * deltaTime * 2.0f);
    };
    if (blocked) {
        std::vector directions = {UP, DOWN, LEFT, RIGHT};
        std::erase(directions, facing);

        const int randIndex = Random::getInstance().getInt(0, static_cast<int>(directions.size() - 1));
        facing = directions[randIndex];

        blocked = false;
    } else if (isAtCenter()) {
        if (Random::getInstance().getInt(0, 1)) {
            const std::vector directions = {UP, DOWN, LEFT, RIGHT};
            const int randIndex = Random::getInstance().getInt(0, static_cast<int>(directions.size() - 1));
            facing = directions[randIndex];
        }
    }

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