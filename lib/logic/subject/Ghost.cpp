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

    auto canMoveTo = [&](const Direction dir) -> bool {
        if (!wallValidator)
            return true;
        Coords p = coords;
        float offset = (dir == UP || dir == DOWN) ? coords.height : coords.width;
        offset *= 0.2f;

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

    auto isAtCenter = [&]() -> bool {
        const float axisValue = (facing == UP || facing == DOWN) ? coords.y : coords.x;
        const float gridSize = (facing == UP || facing == DOWN) ? coords.height : coords.width;
        const float normalizedPos = (axisValue + 1.0f) / gridSize;
        const float idealIndex = std::round(normalizedPos);
        const float centerPos = (idealIndex * gridSize) - 1.0f;
        return std::abs(axisValue - centerPos) < (speed * deltaTime * 1.5f);
    };

    const bool wallAhead = !canMoveTo(facing);
    bool turnDecision = false;

    if (wallAhead) {
        turnDecision = true;
    } else if (isAtCenter()) {
        if (Random::getInstance().getInt(1)) {
            turnDecision = true;
        }
    }
    if (turnDecision) {
        std::vector<Direction> candidates;
        Direction reverseDir;
        if (facing == UP)
            reverseDir = DOWN;
        else if (facing == DOWN)
            reverseDir = UP;
        else if (facing == LEFT)
            reverseDir = RIGHT;
        else
            reverseDir = LEFT;

        if (canMoveTo(UP) && (wallAhead || UP != reverseDir))
            candidates.push_back(UP);
        if (canMoveTo(DOWN) && (wallAhead || DOWN != reverseDir))
            candidates.push_back(DOWN);
        if (canMoveTo(LEFT) && (wallAhead || LEFT != reverseDir))
            candidates.push_back(LEFT);
        if (canMoveTo(RIGHT) && (wallAhead || RIGHT != reverseDir))
            candidates.push_back(RIGHT);

        if (!candidates.empty()) {
            const int index = Random::getInstance().getInt(0, static_cast<int>(candidates.size() - 1));
            Direction newFacing = candidates[index];
            if (newFacing != facing) {
                facing = newFacing;
                const float gridSize = (facing == UP || facing == DOWN) ? coords.height : coords.width;

                if (facing == UP || facing == DOWN)
                    coords.x = std::round((coords.x + 1.0f) / gridSize) * gridSize - 1.0f;
                else
                    coords.y = std::round((coords.y + 1.0f) / gridSize) * gridSize - 1.0f;
            }
        } else if (wallAhead) {
            facing = reverseDir;
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

    if (canMoveTo(facing)) {
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

    notify(std::make_shared<TickEvent>(getCoords(), facing));
}
void subjects::Ghost::accept(std::shared_ptr<CollisionVisitor> visitor) { visitor->visit(shared_from_this()); }
void subjects::Ghost::setWallValidator(const std::function<bool(const Coords&)>& validator) {
    wallValidator = validator;
}