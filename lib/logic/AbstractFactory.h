#ifndef PACMAN_ABSTRACTFACTORY_H
#define PACMAN_ABSTRACTFACTORY_H
#include "subject/Coin.h"
#include "subject/Fruit.h"
#include "subject/Ghost.h"
#include "subject/Pacman.h"
#include "subject/Wall.h"

class AbstractFactory {
public:
    AbstractFactory() = default;

    virtual ~AbstractFactory() = default;
    virtual std::shared_ptr<subjects::Wall> createWall(EntityCoords coords) = 0;
    virtual std::shared_ptr<subjects::Pacman> createPacman(EntityCoords coords) = 0;
    virtual std::shared_ptr<subjects::Coin> createCoin(EntityCoords coords) = 0;
    virtual std::shared_ptr<subjects::Fruit> createFruit(EntityCoords coords) = 0;
    virtual std::shared_ptr<subjects::Ghost> createGhost(EntityCoords coords) = 0;
};

#endif // PACMAN_ABSTRACTFACTORY_H
