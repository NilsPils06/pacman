#ifndef PACMAN_WORLD_H
#define PACMAN_WORLD_H
#include "AbstractFactory.h"
#include "subject/EntityModel.h"

#include <memory>
#include <vector>

class World {
    std::vector<std::shared_ptr<subjects::EntityModel>> entities;
    std::shared_ptr<AbstractFactory> factory;
public:
    explicit World(std::shared_ptr<AbstractFactory> factory);

    void checkCollisions();
    void render() const;
};

#endif // PACMAN_WORLD_H
