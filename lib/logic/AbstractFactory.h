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
    virtual std::shared_ptr<subjects::Wall> createWall(Coords coords) = 0;
    virtual std::shared_ptr<subjects::Pacman> createPacman(Coords coords) = 0;
    virtual std::shared_ptr<subjects::Coin> createCoin(Coords coords) = 0;
    virtual std::shared_ptr<subjects::Fruit> createFruit(Coords coords) = 0;
    virtual std::shared_ptr<subjects::Ghost> createGhost(Coords coords) = 0;
};

#endif // PACMAN_ABSTRACTFACTORY_H
