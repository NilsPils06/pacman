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
    virtual subjects::Ghost createGhost() = 0;
    virtual subjects::Ghost createGhost(float x, float y) = 0;
    virtual subjects::Pacman createPacman() = 0;
    virtual subjects::Fruit createFruit() = 0;
    virtual subjects::Coin createCoin() = 0;
    virtual subjects::Wall createWall() = 0;
    virtual std::shared_ptr<subjects::Wall> createWall(float x, float y) = 0;
};

#endif // PACMAN_ABSTRACTFACTORY_H
