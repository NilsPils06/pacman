#ifndef PACMAN_COIN_H
#define PACMAN_COIN_H
#include "Collectable.h"

namespace subjects {
class Coin final : public Collectable {
public:
    explicit Coin(const Coords& coords) : Collectable(coords) {}
};
} // namespace subjects

#endif // PACMAN_COIN_H
