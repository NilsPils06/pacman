#ifndef PACMAN_GHOSTCOLLISIONHANDLER_H
#define PACMAN_GHOSTCOLLISIONHANDLER_H
#include "Collision.h"
#include "Util.h"

class GhostCollisionHandler final : public CollisionVisitor {
    std::shared_ptr<subjects::Ghost> ghost;
public:
    GhostCollisionHandler() : ghost(nullptr) {}

    explicit GhostCollisionHandler(const std::shared_ptr<subjects::Ghost>& ghost) : ghost(ghost) {}

    [[nodiscard]] Coords getGhostCoords() const;
    
    void visit(const std::shared_ptr<const subjects::Wall>& e) override;
    void visit(std::shared_ptr<subjects::Coin> e) override {}
    void visit(std::shared_ptr<subjects::Fruit> e) override {}
    void visit(std::shared_ptr<subjects::Ghost> e) override {}

};

#endif // PACMAN_GHOSTCOLLISIONHANDLER_H
