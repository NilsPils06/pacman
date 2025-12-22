#ifndef PACMAN_WORLD_H
#define PACMAN_WORLD_H
#include "AbstractFactory.h"
#include "PacmanCollisionHandler.h"
#include "subject/EntityModel.h"
#include <memory>
#include <vector>

class PacmanCollisionHandler;
class World {
    // TODO remove entities
    std::vector<std::shared_ptr<subjects::EntityModel>> entities;
    std::vector<std::shared_ptr<subjects::Wall>> walls;
    std::vector<std::shared_ptr<subjects::Ghost>> ghosts;
    std::vector<std::shared_ptr<subjects::Collectable>> collectables;
    std::shared_ptr<PacmanCollisionHandler> pacmanHandler{};
    std::shared_ptr<AbstractFactory> factory;

public:
    explicit World(std::shared_ptr<AbstractFactory> factory);

    void moveLeft() const;
    void moveUp() const;
    void moveDown() const;
    void moveRight() const;

    void checkCollisions() const;
    [[nodiscard]] bool isWalkable(const Coords& target) const;
    void render();
    [[nodiscard]] bool isOver() const;
    [[nodiscard]] bool isCompleted() const;
    [[nodiscard]] int getLives() const;
};

#endif // PACMAN_WORLD_H
