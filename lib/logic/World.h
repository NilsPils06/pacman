#ifndef PACMAN_WORLD_H
#define PACMAN_WORLD_H
#include "AbstractFactory.h"
#include "PacmanCollisionHandler.h"
#include "subject/EntityModel.h"
#include <memory>
#include <vector>

class PacmanCollisionHandler;
class World {
    std::vector<std::shared_ptr<subjects::Wall>> walls;
    std::vector<std::shared_ptr<subjects::Ghost>> ghosts;
    std::vector<std::shared_ptr<subjects::Collectable>> collectables;
    std::shared_ptr<PacmanCollisionHandler> pacmanHandler{};

public:
    /**
     * @brief Constructs the World object and loads the map corresponding to this level.
     * @param factory the EntityFactory.
     * @param level
     */
    World(const std::shared_ptr<AbstractFactory>& factory, int level);

    /**
     * @brief Notifies Pacman to move left.
     */
    void moveLeft() const;

    /**
     * @brief Notifies Pacman to move up.
     */
    void moveUp() const;

    /**
     * @brief Notifies Pacman to move down.
     */
    void moveDown() const;

    /**
     * @brief Notifies Pacman to move right.
     */
    void moveRight() const;

    /**
     * @brief Check for collisions and execute collision behaviour.
     */
    void checkCollisions() const;

    /**
     * @note A position is walkable if it's inside the map and there is no wall.
     * @param target
     * @return if the target position is walkable.
     */
    [[nodiscard]] bool isWalkable(const Coords& target) const;

    /**
     * @brief Execute tick behaviour of all entities and world.
     * @note Removes expired entities, executes dying behaviour and calls checkCollisions
     */
    void tick();

    /**
     *
     * @return if Pacman has no lives left.
     */
    [[nodiscard]] bool isOver() const;

    /**
     *
     * @return if level has been completed by collecting all collectables.
     */
    [[nodiscard]] bool isCompleted() const;

    /**
     *
     * @return the amount of lives Pacman has.
     */
    [[nodiscard]] int getLives() const;
};

#endif // PACMAN_WORLD_H
