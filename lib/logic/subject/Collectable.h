#ifndef PACMAN_COLLECTABLE_H
#define PACMAN_COLLECTABLE_H
#include "EntityModel.h"

namespace subjects {
class Collectable : public EntityModel {
    int multiplier;
public:
    explicit Collectable(const Coords& coords, const int multiplier) : EntityModel(coords), multiplier(multiplier) {}
    void tick() override;
    [[nodiscard]] int getScoreMultiplier() const;
};
} // namespace subjects

#endif // PACMAN_COLLECTABLE_H
