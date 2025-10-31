#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#include "Direction.h"
#include "EntityModel.h"

class Pacman : public EntityModel {
    int lives = 3;
    Direction facing = LEFT;
};

#endif // PACMAN_PACMAN_H
