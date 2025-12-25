#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H
#include "AbstractFactory.h"
#include "Score.h"

#include <stack>

class EntityFactory final : public AbstractFactory {
    std::shared_ptr<Score> score;
    std::stack<Color> colors;
    std::stack<Movement> types;

public:
    explicit EntityFactory(const std::shared_ptr<Score>& score) : score(score) {
        for (const auto color : {ORANGE, BLUE, PINK, RED})
            colors.push(color);
        for (const auto movement : {FIXED, CUTTING, CUTTING, CHASING})
            types.push(movement);
    }
    std::shared_ptr<subjects::Wall> createWall(Coords coords) override;
    std::shared_ptr<subjects::Pacman> createPacman(Coords coords) override;
    std::shared_ptr<subjects::Coin> createCoin(Coords coords) override;
    std::shared_ptr<subjects::Fruit> createFruit(Coords coords) override;
    std::shared_ptr<subjects::Ghost> createGhost(Coords coords) override;
};

#endif // PACMAN_ENTITYFACTORY_H
