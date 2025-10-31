#ifndef PACMAN_ABSTRACTFACTORY_H
#define PACMAN_ABSTRACTFACTORY_H
#include "subject/Coin.h"
#include "subject/Fruit.h"
#include "subject/Ghost.h"
#include "subject/Pacman.h"
#include "subject/Wall.h"

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;

protected:
    virtual Ghost createGhost() = 0;
    virtual Pacman createPacman() = 0;
    virtual Fruit createFruit() = 0;
    virtual Coin createCoin() = 0;
    virtual Wall createWall() = 0;
};

#endif // PACMAN_ABSTRACTFACTORY_H
