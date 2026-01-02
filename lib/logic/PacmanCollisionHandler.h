#ifndef PACMAN_PACMANCOLLISIONHANDLER_H
#define PACMAN_PACMANCOLLISIONHANDLER_H
#include "Collision.h"
#include "subject/Pacman.h"

#include <functional>

class PacmanCollisionHandler final : public CollisionVisitor {
    std::shared_ptr<subjects::Pacman> pacman;
    std::function<void()> ghostFearer;

public:
    /**
     * @brief Constructs a PacmanCollisionHandler with no Pacman.
     */
    PacmanCollisionHandler() : pacman(nullptr) {}

    /**
     * @brief Constructs a PacmanCollisionHandler object.
     * @param pacman
     */
    explicit PacmanCollisionHandler(const std::shared_ptr<subjects::Pacman>& pacman) : pacman(pacman) {}

    /**
     *
     * @return a pointer to Pacman.
     */
    [[nodiscard]] std::shared_ptr<subjects::Pacman> getPacman() const;

    /**
     *
     * @return if Pacman has no lives left.
     */
    [[nodiscard]] bool isDead() const;

    /**
     * @brief Executes coin collision behaviour.
     * @param e a pointer to a coin.
     */
    void visit(std::shared_ptr<subjects::Coin> e) override;

    /**
     * @brief Executes fruit collision behaviour.
     * @param e a pointer to a coin.
     */
    void visit(std::shared_ptr<subjects::Fruit> e) override;

    /**
     * @brief Executes ghost collision behaviour.
     * @param e a pointer to a coin.
     */
    void visit(std::shared_ptr<subjects::Ghost> e) override;

    /**
     * @brief Sets the WallValidator.
     * @param function a function which returns true, if there is a wall at the provided coordinates.
     */
    void setWallValidator(const std::function<bool(const Coords&)>& function) const;

    /**
     * @brief Sets the GhostFearer.
     * @param ghost_fearer a function which sets the ghosts in fear mode.
     */
    void setGhostFearer(const std::function<void()>& ghost_fearer);
};

#endif // PACMAN_PACMANCOLLISIONHANDLER_H
