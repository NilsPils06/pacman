#ifndef PACMAN_WORLD_H
#define PACMAN_WORLD_H
#include "AbstractFactory.h"
#include "subject/EntityModel.h"

#include <map>
#include <memory>
#include <vector>

class World {
    std::vector<std::shared_ptr<subjects::EntityModel>> entities;
    std::map<std::shared_ptr<subjects::EntityModel>, std::shared_ptr<CollisionVisitor>> visitors;
    std::map<std::shared_ptr<subjects::EntityModel>, std::shared_ptr<CollisionComponent>> components;
    std::shared_ptr<AbstractFactory> factory;

public:
    explicit World(std::shared_ptr<AbstractFactory> factory);

    void moveLeft() const;
    void moveUp() const;
    void moveDown() const;
    void moveRight() const;

    void checkCollisions() const;
    void render() const;
};

#endif // PACMAN_WORLD_H
