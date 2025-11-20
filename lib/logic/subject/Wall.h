#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H
#include "EntityModel.h"

namespace subjects {
class Wall : public EntityModel {
public:
    Wall(float x, float y) : EntityModel(x, y) {}

    void notify() override;
};
} // namespace subjects

#endif // PACMAN_WALL_H
