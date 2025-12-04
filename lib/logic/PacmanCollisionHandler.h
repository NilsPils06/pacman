#ifndef PACMAN_PACMANCOLLISIONHANDLER_H
#define PACMAN_PACMANCOLLISIONHANDLER_H
#include "Collision.h"
#include "subject/Pacman.h"

class PacmanCollisionHandler : public CollisionVisitor {
    std::shared_ptr<subjects::Pacman> pacman;
public:
    PacmanCollisionHandler() : pacman(nullptr) {}

    explicit PacmanCollisionHandler(const std::shared_ptr<subjects::Pacman>& pacman) : pacman(pacman) {}

    void visit(const std::shared_ptr<const subjects::Wall>& e) override;

    Coords getPacmanCoords() const;
};

#endif // PACMAN_PACMANCOLLISIONHANDLER_H
