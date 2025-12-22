#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#include "EntityModel.h"

#include <functional>

namespace subjects {
class Pacman final : public EntityModel {
    int lives = 3;
    Direction facing = RIGHT;
    Direction queuedDirection = RIGHT;
    float speed = 0.1f;
    Coords spawn;
    bool dying = false;
    float deathTimer = 0.0f;
    const float DEATH_DURATION = 1.5f;
    std::function<bool(const Coords&)> wallValidator;

public:
    explicit Pacman(const Coords& coords) : EntityModel(coords), spawn(coords) {}
    void notify(std::shared_ptr<Event> e) override;
    void tick() override;
    [[nodiscard]] int getLives() const;
    void hurt();
    [[nodiscard]] bool isDying() const;
    void setWallValidator(const std::function<bool(const Coords&)>& validator);
};
} // namespace subjects

#endif // PACMAN_PACMAN_H