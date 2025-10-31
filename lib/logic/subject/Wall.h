#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H
#include "EntityModel.h"

namespace subjects {
class Wall : EntityModel {
public:
    void notify() override;
};
} // namespace subjects

#endif // PACMAN_WALL_H
