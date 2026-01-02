#ifndef PACMAN_COLLECTABLE_H
#define PACMAN_COLLECTABLE_H
#include "../Collision.h"
#include "../Event.h"
#include "EntityModel.h"

namespace subjects {
class Collectable : public EntityModel, public CollisionComponent {
    int points;

public:
    /**
     * @brief Constructs a Collectable object.
     * @param coords the spawn of the Collectable.
     * @param points how many points the Collectable is worth.
     */
    explicit Collectable(const Coords& coords, const int points) : EntityModel(coords), points(points) {}

    /**
     * @brief Notifies the View observer of our coordinates via RenderStaticEvent
     * @note Function is called every tick.
     */
    void tick() override { notify(std::make_shared<RenderStaticEvent>(getCoords())); }

    /**
     *
     * @return the amount of points the collectable is worth.
     */
    [[nodiscard]] int getPoints() const { return points; }

    /**
     * @copydoc CollisionComponent::accept
     */
    void accept(std::shared_ptr<CollisionVisitor> visitor) override {};
};
} // namespace subjects

#endif // PACMAN_COLLECTABLE_H
