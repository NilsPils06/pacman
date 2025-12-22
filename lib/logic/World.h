#ifndef PACMAN_WORLD_H
#define PACMAN_WORLD_H
#include "AbstractFactory.h"
#include "GhostCollisionHandler.h"
#include "PacmanCollisionHandler.h"
#include "subject/EntityModel.h"

#include <map>
#include <memory>
#include <vector>

class PacmanCollisionHandler;
class World {
    std::vector<std::shared_ptr<subjects::EntityModel>> entities;
    std::shared_ptr<PacmanCollisionHandler> pacmanHandler{};
    std::vector<std::shared_ptr<GhostCollisionHandler>> ghostHandlers{};
    std::map<std::shared_ptr<subjects::EntityModel>, std::shared_ptr<CollisionComponent>> components;
    std::shared_ptr<AbstractFactory> factory;
    int collectables = 0;

public:
    explicit World(std::shared_ptr<AbstractFactory> factory);

    void moveLeft() const;
    void moveUp() const;
    void moveDown() const;
    void moveRight() const;

    void checkCollisions() const;
    void render();
    [[nodiscard]] bool isOver() const;
    [[nodiscard]] bool isCompleted() const;
    [[nodiscard]] int getLives() const;
};

#endif // PACMAN_WORLD_H
