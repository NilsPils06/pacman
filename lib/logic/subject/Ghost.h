#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include "EntityModel.h"


namespace subjects {
class Ghost : public EntityModel {
    Movement movement;
    Direction lockedIn = UP;
    bool chasing = false;
    bool fear = false;
public:
    explicit Ghost(const Movement movement) : movement(movement) {};
};
}

#endif // PACMAN_GHOST_H
