#ifndef PACMAN_PACMANCOLLISIONHANDLER_H
#define PACMAN_PACMANCOLLISIONHANDLER_H
#include "Collision.h"
#include "subject/Pacman.h"

class PacmanCollisionHandler final : public CollisionVisitor {
    std::shared_ptr<subjects::Pacman> pacman;

public:
    PacmanCollisionHandler() : pacman(nullptr) {}

    explicit PacmanCollisionHandler(const std::shared_ptr<subjects::Pacman>& pacman) : pacman(pacman) {}

    void visit(const std::shared_ptr<const subjects::Wall>& e) override;

    [[nodiscard]] Coords getPacmanCoords() const;
    void visit(std::shared_ptr<subjects::Coin> e) override;
    void visit(std::shared_ptr<subjects::Fruit> e) override;
};

#endif // PACMAN_PACMANCOLLISIONHANDLER_H
