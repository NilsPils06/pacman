#ifndef PACMAN_COIN_H
#define PACMAN_COIN_H
#include "Collectable.h"

namespace subjects {
class Coin : public Collectable {
public:
    void notify() override;
};
} // namespace subjects

#endif // PACMAN_COIN_H
