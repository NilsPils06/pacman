#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H
#include "../Collision.h"
#include "../Event.h"
#include "EntityModel.h"

namespace subjects {
class Wall final : public EntityModel, public CollisionComponent, public std::enable_shared_from_this<Wall> {
public:
    explicit Wall(const Coords& coords) : EntityModel(coords) {}
    void tick() override { notify(std::make_shared<RenderStaticEvent>(getCoords())); }
    void accept(const std::shared_ptr<CollisionVisitor> visitor) override { visitor->visit(shared_from_this()); }
};
} // namespace subjects

#endif // PACMAN_WALL_H
