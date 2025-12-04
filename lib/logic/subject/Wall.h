#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H
#include "EntityModel.h"
#include "../Collision.h"

namespace subjects {
class Wall final : public EntityModel, public CollisionComponent, public std::enable_shared_from_this<Wall> {
public:
    explicit Wall(const Coords& coords) : EntityModel(coords) {}
    void tick() override;
    void accept(std::shared_ptr<CollisionVisitor> visitor) override;
};
} // namespace subjects

#endif // PACMAN_WALL_H
