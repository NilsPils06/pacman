#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#include "EntityModel.h"

namespace subjects {
class Pacman final : public EntityModel {
    int lives = 3;
    Direction facing = LEFT;
};
} // namespace subjects

#endif // PACMAN_PACMAN_H
