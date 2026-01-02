#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include "../Collision.h"
#include "EntityModel.h"

#include <functional>
#include <vector>

namespace subjects {
class Ghost final : public EntityModel, public CollisionComponent, public std::enable_shared_from_this<Ghost> {
    Movement movement = FIXED;
    Direction lockedIn = UP;
    bool fear = false;
    bool eaten = false;
    bool chasing = false;
    float nonChasingTime = 0.f;
    float chaseTimer = 0.f;
    float FEAR_DUR = 5.f;
    float fearTimer = 0;
    Direction facing = RIGHT;
    float speed = 0.1f;
    Coords spawn;
    std::function<bool(const Coords&)> wallValidator;
    std::function<std::pair<Coords, Direction>()> pacmanLocator;
    int level = 1;

    std::vector<std::vector<bool>> gridMap;
    int mapWidth = 0;
    int mapHeight = 0;

public:
    /**
     * @brief Constructs a Ghost model object.
     * @param coords the spawn coordinates of the Ghost.
     * @param count the Ghost number, used for nonChasingTime.
     */
    Ghost(const Coords& coords, int count);

    /**
     * @brief Executes movement behaviour.
     * @note Called every tick.
     */
    void tick() override;

    /**
     * @copydoc CollisionComponent::accept
     */
    void accept(std::shared_ptr<CollisionVisitor> visitor) override;

    /**
     * @brief Sets the WallValidator.
     * @param validator a function which returns true, if there is a wall at the provided coordinates.
     */
    void setWallValidator(const std::function<bool(const Coords&)>& validator);

    /**
     * @brief Resets the current position to the spawn position.
     */
    void resetPosition();

    /**
     * @brief Sets the PacmanLocator.
     * @param locator a function which returns the coordinates of Pacman.
     */
    void setPacmanLocator(const std::function<std::pair<Coords, Direction>()>& locator);

    /**
     * @brief Updates the movement type.
     * @param m a movement type.
     */
    void setMovementType(Movement m);

    /**
     * @brief Sets fear equal to f.
     * @param f
     */
    void setFear(bool f);

    /**
     * @brief Executes collect/eat behaviour.
     * @note Called when Pacman collides with a Ghost in fear mode.
     * @return the amount of points that a Ghost is worth.
     */
    int collect();

    /**
     * @brief Sets the difficulty level of the Ghost equal to i.
     * @param i a positive non-zero integer.
     */
    void setLevel(int i);

    /**
     * @brief Sets the navigation map used for BFS.
     * @param map a gridmap of the walls.
     * @param width the width in tiles.
     * @param height the height in tiles.
     */
    void setNavigationMap(const std::vector<std::vector<bool>>& map, int width, int height);

    /**
     *
     * @return if the ghost is in fear mode.
     */
    [[nodiscard]] bool inFear() const;

    /**
     *
     * @return if the ghost has been eaten.
     */
    [[nodiscard]] bool isEaten() const;

    /**
     *
     * @param dir
     * @return if the Ghost can move to the direction dir.
     */
    bool canMoveTo(Direction dir) const;

    /**
     * @brief Decides on a direction to go to based on a list of candidates, current state of the ghost and its movement
     * type.
     * @param candidates
     * @param wallAhead if a wall is ahead or not.
     * @return the chosen direction.
     */
    Direction decideDirection(const std::vector<Direction>& candidates, bool wallAhead) const;

    /**
     *
     * @param candidates
     * @param wallAhead
     * @return a random direction out of the candidates that are viable.
     */
    Direction decideFixed(const std::vector<Direction>& candidates, bool wallAhead) const;

    /**
     * @note Uses Manhattan distance.
     * @param candidates
     * @return a direction that brings the ghost closer to its target.
     */
    Direction decideTargetBased(const std::vector<Direction>& candidates) const;

    /**
     *
     * @return the position of the Ghosts target.
     */
    Coords getTargetPosition() const;

    /**
     * @note Uses BFS.
     * @param target
     * @return a direction that brings the ghost closer to its target.
     */
    Direction getBFSDirection(const Coords& target) const;

    /**
     *
     * @param c
     * @return the grid coordinates correlating to c.
     */
    std::pair<int, int> toGridCoords(const Coords& c) const;

    /**
     *
     * @param target position of target.
     * @param candidates
     * @param maximize if the distance should be maximized.
     * @return the best direction to decrease/increase Manhattan distance from target.
     */
    Direction getBestManhattanDirection(const Coords& target, const std::vector<Direction>& candidates,
                                        bool maximize) const;
};
} // namespace subjects

#endif // PACMAN_GHOST_H