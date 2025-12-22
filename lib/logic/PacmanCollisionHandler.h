#ifndef PACMAN_PACMANCOLLISIONHANDLER_H
#define PACMAN_PACMANCOLLISIONHANDLER_H
#include "Collision.h"
#include "subject/Pacman.h"

#include <functional>

class PacmanCollisionHandler final : public CollisionVisitor {
    std::shared_ptr<subjects::Pacman> pacman;

public:
    PacmanCollisionHandler() : pacman(nullptr) {}

    explicit PacmanCollisionHandler(const std::shared_ptr<subjects::Pacman>& pacman) : pacman(pacman) {}

    void visit(const std::shared_ptr<const subjects::Wall>& e) override {};

    [[nodiscard]] Coords getPacmanCoords() const;
    [[nodiscard]] bool isDead() const;
    [[nodiscard]] int getLives() const;
    [[nodiscard]] bool isDying() const;
    void tick() const;
    void visit(std::shared_ptr<subjects::Coin> e) override;
    void visit(std::shared_ptr<subjects::Fruit> e) override;
    void visit(std::shared_ptr<subjects::Ghost> e) override;
    void setWallValidator(const std::function<bool(const Coords&)>& function) const;
};

#endif // PACMAN_PACMANCOLLISIONHANDLER_H
