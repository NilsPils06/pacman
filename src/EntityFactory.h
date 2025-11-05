#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H
#include "AbstractFactory.h"

class EntityFactory final : public AbstractFactory {
public:
    subjects::Ghost createGhost() override;
    subjects::Pacman createPacman() override;
    subjects::Fruit createFruit() override;
    subjects::Coin createCoin() override;
    subjects::Wall createWall() override;
};

#endif // PACMAN_ENTITYFACTORY_H
