#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#include "EntityModel.h"

#include <functional>

namespace subjects {
class Pacman final : public EntityModel {
    int lives = 3;
    Direction facing = RIGHT;
    Direction queuedDirection = RIGHT;
    float speed = 0.1f;
    Coords spawn;
    bool dying = false;
    float deathTimer = 0.0f;
    const float DEATH_DURATION = 1.5f;
    std::function<bool(const Coords&)> wallValidator;

public:
    /**
     * @brief Constructs a Pacman model object.
     * @param coords the spawn coordinates of Pacman.
     */
    explicit Pacman(const Coords& coords) : EntityModel(coords), spawn(coords) {}

    /**
     * @brief Queues the next direction to go to.
     * @param e a DirectionChangeEvent.
     */
    void notify(const std::shared_ptr<DirectionChangeEvent>& e) override;

    /**
     * @brief Executes movement and death behaviour of Pacman.
     */
    void tick() override;

    /**
     *
     * @return the amount of lives Pacman currently has.
     */
    [[nodiscard]] int getLives() const;

    /**
     * @brief Puts Pacman in its dying state.
     */
    void hurt();

    /**
     *
     * @return is Pacman dying.
     */
    [[nodiscard]] bool isDying() const;

    /**
     * @brief Sets the WallValidator.
     * @param validator a function which returns true, if there is a wall at the provided coordinates.
     */
    void setWallValidator(const std::function<bool(const Coords&)>& validator);

    /**
     *
     * @return the currently facing direction.
     */
    [[nodiscard]] Direction getFacing() const;
};
} // namespace subjects

#endif // PACMAN_PACMAN_H