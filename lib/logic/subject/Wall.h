#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H
#include "EntityModel.h"

namespace subjects {
class Wall final : public EntityModel {
public:
    Wall(float x, float y) : EntityModel(x, y) {}
};
} // namespace subjects

#endif // PACMAN_WALL_H
