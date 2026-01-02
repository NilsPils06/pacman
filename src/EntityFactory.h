#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H
#include "AbstractFactory.h"
#include "Score.h"

#include <stack>

class EntityFactory final : public AbstractFactory {
    std::shared_ptr<Score> score;
    std::stack<std::pair<Color, Movement>> ghostTypes;

public:
    /**
     * @brief Sets up the EntityFactory.
     * @param score a pointer to a score observer.
     */
    explicit EntityFactory(const std::shared_ptr<Score>& score) : score(score) { resetStack(); }

    /**
     * @brief Creates a Wall model and view and attaches the view to the model.
     * @param coords the coordinates of where to create the wall.
     * @return
     */
    std::shared_ptr<subjects::Wall> createWall(Coords coords) override;

    /**
     * @brief Creates a Pacman model and view and attaches the view to the model.
     * @param coords the spawn coordinates of where to create Pacman.
     * @return
     */
    std::shared_ptr<subjects::Pacman> createPacman(Coords coords) override;

    /**
     * @brief Creates a Coin model and view and attaches the view to the model.
     * @param coords the coordinates of where to create the coin.
     * @return
     */
    std::shared_ptr<subjects::Coin> createCoin(Coords coords) override;

    /**
     * @brief Creates a Fruit model and view and attaches the view to the model.
     * @param coords the coordinates of where to create the fruit.
     * @return
     */
    std::shared_ptr<subjects::Fruit> createFruit(Coords coords) override;

    /**
     * @brief Creates a Ghost model and view and attaches the view to the model.
     * @param coords the spawn coordinates of where to create the ghost.
     * @return
     */
    std::shared_ptr<subjects::Ghost> createGhost(Coords coords) override;

    /**
     * @brief Emplaces all "ghost types" on the stack.
     */
    void resetStack() {
        while (!ghostTypes.empty())
            ghostTypes.pop();
        ghostTypes.emplace(ORANGE, FIXED);
        ghostTypes.emplace(BLUE, CUTTING);
        ghostTypes.emplace(PINK, CUTTING);
        ghostTypes.emplace(RED, CHASING);
    }
};

#endif // PACMAN_ENTITYFACTORY_H
