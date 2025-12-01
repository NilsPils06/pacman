#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#include "EntityModel.h"

namespace subjects {
class Pacman final : public EntityModel {
    int lives = 3;
    Direction facing = RIGHT;
public:
    explicit Pacman(const EntityCoords& coords) : EntityModel(coords) {}
    void notify(std::shared_ptr<Event> e) override;
    void tick() override;
};
} // namespace subjects

#endif // PACMAN_PACMAN_H
