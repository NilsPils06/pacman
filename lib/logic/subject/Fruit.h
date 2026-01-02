#ifndef PACMAN_FRUIT_H
#define PACMAN_FRUIT_H
#include "../Collision.h"
#include "Collectable.h"
namespace subjects {
class Fruit final : public Collectable, public std::enable_shared_from_this<Fruit> {
public:
    /**
     * @brief Constructs a Fruit model object.
     * @param coords the spawn of the object.
     */
    explicit Fruit(const Coords& coords) : Collectable(coords, 100) {}

    /**
     * @copydoc CollisionComponent::accept
     */
    void accept(const std::shared_ptr<CollisionVisitor> visitor) override { visitor->visit(shared_from_this()); }
};
} // namespace subjects

#endif // PACMAN_FRUIT_H
