#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H
#include "AbstractFactory.h"
#include "Score.h"

class EntityFactory final : public AbstractFactory {
    std::shared_ptr<Score> score;

public:
    explicit EntityFactory(const std::shared_ptr<Score>& score) : score(score) {}
    std::shared_ptr<subjects::Wall> createWall(Coords coords) override;
    std::shared_ptr<subjects::Pacman> createPacman(Coords coords) override;
    std::shared_ptr<subjects::Coin> createCoin(Coords coords) override;
    std::shared_ptr<subjects::Fruit> createFruit(Coords coords) override;
    std::shared_ptr<subjects::Ghost> createGhost(Coords coords) override;
};

#endif // PACMAN_ENTITYFACTORY_H
