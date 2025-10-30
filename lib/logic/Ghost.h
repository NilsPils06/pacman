#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include "EntityModel.h"

enum Movement {
    FIXED,
    CHASING,
    CUTTING
};

class Ghost : public EntityModel {
    Movement movement;
    bool chasing = false;
public:
    explicit Ghost(const Movement movement) : movement(movement) {};
};

#endif // PACMAN_GHOST_H
