#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include "EntityModel.h"

namespace subjects {
class Ghost : public EntityModel {
    Movement movement = FIXED;
    Direction lockedIn = UP;
    bool chasing = false;
    bool fear = false;

public:
    explicit Ghost(const Coords& coords) : EntityModel(coords) {}
    void tick() override;
};
} // namespace subjects

#endif // PACMAN_GHOST_H
