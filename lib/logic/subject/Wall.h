#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H
#include "EntityModel.h"

namespace subjects {
class Wall final : public EntityModel {
public:
    explicit Wall(const EntityCoords& coords) : EntityModel(coords) {}
};
} // namespace subjects

#endif // PACMAN_WALL_H
