#include "Ghost.h"
#include "../Event.h"
#include "../Random.h"
#include "../Stopwatch.h"

#include <cmath>
constexpr float ASPECT_RATIO = 16.f / 9.f;

void subjects::Ghost::tick() {
    float distanceToSpawn = std::abs(coords.x - spawn.x) + std::abs(coords.y - spawn.y);
    if (eaten && distanceToSpawn <= 0.1f) {
        eaten = false;
        coords = spawn;
        facing = UP;
    }

    const float deltaTime = Stopwatch::getInstance().getDeltaTime();
    speed = facing == UP || facing == DOWN ? 0.3f * ASPECT_RATIO : 0.3f;
    speed += 0.05f * static_cast<float>(level-1);
    if (fear) {
        fearTimer += deltaTime;
        if (fearTimer >= FEAR_DUR) {
            fear = false;
            fearTimer = 0.0f;
        } else
            speed *= 0.5f;
    }
    const bool wallAhead = !canMoveTo(facing);
    const float axisValue = (facing == UP || facing == DOWN) ? coords.y : coords.x;
    const float gridSize = (facing == UP || facing == DOWN) ? coords.height : coords.width;
    const float normalizedPos = (axisValue + 1.0f) / gridSize;
    const float idealIndex = std::round(normalizedPos);
    const float centerPos = (idealIndex * gridSize) - 1.0f;
    const bool atCenter = std::abs(axisValue - centerPos) < (speed * deltaTime * 1.5f);

    if (wallAhead || atCenter) {
        std::vector<Direction> candidates;
        const Direction reverseDir = (facing == UP) ? DOWN : (facing == DOWN) ? UP : (facing == LEFT) ? RIGHT : LEFT;

        for (const auto d : {UP, DOWN, LEFT, RIGHT})
            if (canMoveTo(d) && (fear || eaten || wallAhead || d != reverseDir))
                candidates.push_back(d);

        if (!candidates.empty()) {
            Direction newFacing = facing;
            newFacing = decideDirection(candidates, wallAhead);
            if (newFacing != facing) {
                facing = newFacing;
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

    if (eaten)
        notify(std::make_shared<EatenEvent>(getCoords(), facing));
    else
        notify(std::make_shared<TickEvent>(getCoords(), facing, fear));
}
Direction subjects::Ghost::decideDirection(const std::vector<Direction>& candidates, const bool wallAhead) const {
    if (fear || eaten)
        return decideTargetBased(candidates);

    switch (movement) {
    case FIXED:
        return decideFixed(candidates, wallAhead);
    case CHASING:
    case CUTTING:
        return decideTargetBased(candidates);
    default:
        return candidates[0];
    }
}

Direction subjects::Ghost::decideFixed(const std::vector<Direction>& candidates, const bool wallAhead) const {
    if (wallAhead || Random::getInstance().getInt(1)) {
        const int index = Random::getInstance().getInt(0, static_cast<int>(candidates.size() - 1));
        return candidates[index];
    }
    return facing;
}

Direction subjects::Ghost::decideTargetBased(const std::vector<Direction>& candidates) const {
    const Coords target = getTargetPosition();
    const bool maximizeDistance = fear;

    return getBestManhattanDirection(target, candidates, maximizeDistance);
}
Coords subjects::Ghost::getTargetPosition() const {
    if (eaten)
        return spawn;

    if (!pacmanLocator)
        return {0, 0, 0, 0};

    auto [pacCoords, pacDir] = pacmanLocator();

    if (movement == CUTTING && !fear) {
        const float lookAhead = 4.0f * coords.width;
        if (pacDir == UP)
            pacCoords.y -= lookAhead;
        if (pacDir == DOWN)
            pacCoords.y += lookAhead;
        if (pacDir == LEFT)
            pacCoords.x -= lookAhead;
        if (pacDir == RIGHT)
            pacCoords.x += lookAhead;
    }

    return pacCoords;
}

Direction subjects::Ghost::getBestManhattanDirection(const Coords& target, const std::vector<Direction>& candidates,
                                                     const bool maximize) const {
    float bestDist = maximize ? -1.0f : std::numeric_limits<float>::max();
    std::vector<Direction> bestCandidates;

    for (const auto& dir : candidates) {
        Coords next = coords;
        const float step = (dir == UP || dir == DOWN) ? coords.height : coords.width;

        if (dir == UP)
            next.y -= step;
        else if (dir == DOWN)
            next.y += step;
        else if (dir == LEFT)
            next.x -= step;
        else if (dir == RIGHT)
            next.x += step;

        if (const float dist = std::abs(next.x - target.x) + std::abs(next.y - target.y);
            maximize ? (dist > bestDist) : (dist < bestDist)) {
            bestDist = dist;
            bestCandidates.clear();
            bestCandidates.push_back(dir);
        } else if (std::abs(dist - bestDist) < 0.001f) {
            bestCandidates.push_back(dir);
        }
    }

    if (bestCandidates.empty())
        return candidates[0];

    const int index = Random::getInstance().getInt(static_cast<int>(bestCandidates.size() - 1));
    return bestCandidates[index];
}
bool subjects::Ghost::canMoveTo(const Direction dir) const {
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
}
void subjects::Ghost::accept(std::shared_ptr<CollisionVisitor> visitor) { visitor->visit(shared_from_this()); }
void subjects::Ghost::setWallValidator(const std::function<bool(const Coords&)>& validator) {
    wallValidator = validator;
}
void subjects::Ghost::resetPosition() {
    if (coords == spawn)
        return;
    coords = spawn;
}
void subjects::Ghost::setPacmanLocator(const std::function<std::pair<Coords, Direction>()>& locator) {
    pacmanLocator = locator;
}
void subjects::Ghost::setMovementType(const Movement m) { movement = m; }
void subjects::Ghost::setFear(const bool f) { fear = f; }
void subjects::Ghost::setEaten(const bool e) {
    eaten = e;
    fear = false;
    fearTimer = 0.0f;
}
void subjects::Ghost::setLevel(const int i) {
    level = i;
    FEAR_DUR -= 0.5f * static_cast<float>(level-1);
}
bool subjects::Ghost::inFear() const { return fear; }
bool subjects::Ghost::isEaten() const { return eaten; }
