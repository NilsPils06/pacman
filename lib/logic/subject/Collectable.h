#ifndef PACMAN_COLLECTABLE_H
#define PACMAN_COLLECTABLE_H
#include "EntityModel.h"

namespace subjects {
class Collectable : public EntityModel {
public:
    explicit Collectable(const EntityCoords& coords) : EntityModel(coords) {}
    void tick() override;
};
} // namespace subjects

#endif // PACMAN_COLLECTABLE_H
