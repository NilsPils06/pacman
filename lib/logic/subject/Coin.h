#ifndef PACMAN_COIN_H
#define PACMAN_COIN_H
#include "../Collision.h"
#include "Collectable.h"

namespace subjects {
class Coin final : public Collectable, public std::enable_shared_from_this<Coin> {
public:
    /**
     * @brief Constructs a Coin model object.
     * @param coords the spawn of the Coin.
     */
    explicit Coin(const Coords& coords) : Collectable(coords, 10) {}

    /**
     * @copydoc CollisionComponent::accept
     */
    void accept(const std::shared_ptr<CollisionVisitor> visitor) override { visitor->visit(shared_from_this()); }
};
} // namespace subjects

#endif // PACMAN_COIN_H
