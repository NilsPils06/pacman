#ifndef PACMAN_COLLECTABLE_H
#define PACMAN_COLLECTABLE_H
#include "../Collision.h"
#include "../Event.h"
#include "EntityModel.h"

namespace subjects {
class Collectable : public EntityModel, public CollisionComponent {
    int multiplier;

public:
    explicit Collectable(const Coords& coords, const int multiplier) : EntityModel(coords), multiplier(multiplier) {}
    void tick() override { notify(std::make_shared<PositonUpdateEvent>(getCoords())); }
    [[nodiscard]] int getScoreMultiplier() const { return multiplier; }
    void accept(std::shared_ptr<CollisionVisitor> visitor) override {};
};
} // namespace subjects

#endif // PACMAN_COLLECTABLE_H
