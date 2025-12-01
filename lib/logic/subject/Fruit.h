#ifndef PACMAN_FRUIT_H
#define PACMAN_FRUIT_H
#include "Collectable.h"
namespace subjects {
class Fruit final : public Collectable {
public:
    explicit Fruit(const Coords& coords) : Collectable(coords) {}
};
} // namespace subjects

#endif // PACMAN_FRUIT_H
