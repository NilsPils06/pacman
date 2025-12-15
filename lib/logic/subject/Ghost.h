#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include "../Collision.h"
#include "EntityModel.h"

namespace subjects {
class Ghost final : public EntityModel, public CollisionComponent, public std::enable_shared_from_this<Ghost> {
    Movement movement = FIXED;
    Direction lockedIn = UP;
    bool chasing = false;
    bool fear = false;

public:
    explicit Ghost(const Coords& coords) : EntityModel(coords) {}
    void tick() override;
    void accept(std::shared_ptr<CollisionVisitor> visitor) override;
};
} // namespace subjects

#endif // PACMAN_GHOST_H
