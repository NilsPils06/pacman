#ifndef PACMAN_FRUIT_H
#define PACMAN_FRUIT_H
#include "../Collision.h"
#include "Collectable.h"
namespace subjects {
class Fruit final : public Collectable, public std::enable_shared_from_this<Fruit> {
public:
    explicit Fruit(const Coords& coords) : Collectable(coords, 100) {}
    void accept(std::shared_ptr<CollisionVisitor> visitor) override;
};
} // namespace subjects

#endif // PACMAN_FRUIT_H
