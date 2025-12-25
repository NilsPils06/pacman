#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include "../Collision.h"
#include "EntityModel.h"

#include <functional>

namespace subjects {
class Ghost final : public EntityModel, public CollisionComponent, public std::enable_shared_from_this<Ghost> {
    Movement movement = FIXED;
    Direction lockedIn = UP;
    bool chasing = false;
    bool fear = false;
    Direction facing = RIGHT;
    float speed = 0.1f;
    Coords spawn;
    std::function<bool(const Coords&)> wallValidator;
    std::function<std::pair<Coords, Direction>()> pacmanLocator;

public:
    explicit Ghost(const Coords& coords) : EntityModel(coords), spawn(coords) {}
    void tick() override;
    void accept(std::shared_ptr<CollisionVisitor> visitor) override;
    void setWallValidator(const std::function<bool(const Coords&)>& validator);
    void resetPosition();
    void setPacmanLocator(const std::function<std::pair<Coords, Direction>()>& locator);
    void setMovementType(Movement m);

    bool canMoveTo(Direction dir) const;
    Direction decideDirection(const std::vector<Direction>& candidates, bool wallAhead) const;
    Direction decideFixed(const std::vector<Direction>& candidates, bool wallAhead) const;
    Direction decideTargetBased(const std::vector<Direction>& candidates) const;
    Coords getTargetPosition() const;
    Direction getBestManhattanDirection(const Coords& target, const std::vector<Direction>& candidates, bool maximize) const;
};
} // namespace subjects

#endif // PACMAN_GHOST_H
