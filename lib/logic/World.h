#ifndef PACMAN_WORLD_H
#define PACMAN_WORLD_H
#include "subject/EntityModel.h"

#include <memory>
#include <vector>

class World {
    std::vector<std::unique_ptr<subjects::EntityModel>> entities;
    int gridWidth;
    int gridHeight;
public:
    [[nodiscard]] int get_grid_width() const;
    [[nodiscard]] int get_grid_height() const;

    void checkCollisions();
};

#endif // PACMAN_WORLD_H
