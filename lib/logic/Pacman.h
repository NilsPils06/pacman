#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#include "EntityModel.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Pacman : public EntityModel {
    int lives = 3;
    Direction facing;
};

#endif // PACMAN_PACMAN_H
