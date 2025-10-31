#ifndef PACMAN_WORLD_H
#define PACMAN_WORLD_H
#include "subject/EntityModel.h"

#include <memory>
#include <vector>

class World {
    std::vector<std::unique_ptr<subjects::EntityModel>> entities;
public:
    void checkCollisions();
};

#endif // PACMAN_WORLD_H
