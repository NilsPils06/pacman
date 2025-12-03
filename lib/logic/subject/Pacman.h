#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#include "../Collision.h"
#include "EntityModel.h"

namespace subjects {
class Pacman final : public EntityModel, public CollisionVisitor {
    int lives = 3;
    Direction facing = RIGHT;
    Direction queuedDirection = RIGHT;
    float speed = 0.1f;
    bool blocked = false;

public:
    explicit Pacman(const Coords& coords) : EntityModel(coords) {}
    void notify(std::shared_ptr<Event> e) override;
    void tick() override;
    void visit(std::shared_ptr<const subjects::Wall> e) override;
};
} // namespace subjects

#endif // PACMAN_PACMAN_H