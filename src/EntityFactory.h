#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H
#include "AbstractFactory.h"

class EntityFactory final : public AbstractFactory {
public:
    EntityFactory() = default;

    subjects::Ghost createGhost() override;
    subjects::Pacman createPacman() override;
    subjects::Fruit createFruit() override;
    subjects::Coin createCoin() override;
    subjects::Wall createWall() override;
    std::shared_ptr<subjects::Wall> createWall(float x, float y) override;
    subjects::Ghost createGhost(float x, float y) override;
};

#endif // PACMAN_ENTITYFACTORY_H
