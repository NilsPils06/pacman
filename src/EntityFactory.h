#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H
#include "AbstractFactory.h"
#include "Score.h"

#include <stack>

class EntityFactory final : public AbstractFactory {
    std::shared_ptr<Score> score;
    std::stack<std::pair<Color, Movement>> ghostTypes;

public:
    explicit EntityFactory(const std::shared_ptr<Score>& score) : score(score) {
        resetStack();
    }
    std::shared_ptr<subjects::Wall> createWall(Coords coords) override;
    std::shared_ptr<subjects::Pacman> createPacman(Coords coords) override;
    std::shared_ptr<subjects::Coin> createCoin(Coords coords) override;
    std::shared_ptr<subjects::Fruit> createFruit(Coords coords) override;
    std::shared_ptr<subjects::Ghost> createGhost(Coords coords) override;

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
