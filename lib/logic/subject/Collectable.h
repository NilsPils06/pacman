#ifndef PACMAN_COLLECTABLE_H
#define PACMAN_COLLECTABLE_H
#include "../Collision.h"
#include "../Event.h"
#include "EntityModel.h"

namespace subjects {
class Collectable : public EntityModel, public CollisionComponent {
    int points;

public:
    explicit Collectable(const Coords& coords, const int points) : EntityModel(coords), points(points) {}
    void tick() override { notify(std::make_shared<RenderStaticEvent>(getCoords())); }
    [[nodiscard]] int getPoints() const { return points; }
    void accept(std::shared_ptr<CollisionVisitor> visitor) override {};
};
} // namespace subjects

#endif // PACMAN_COLLECTABLE_H
