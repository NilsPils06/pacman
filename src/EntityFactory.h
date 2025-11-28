#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H
#include "AbstractFactory.h"

class EntityFactory final : public AbstractFactory {
public:
    EntityFactory() = default;
    std::shared_ptr<subjects::Wall> createWall(EntityCoords coords) override;
    std::shared_ptr<subjects::Pacman> createPacman(EntityCoords coords) override;
    std::shared_ptr<subjects::Coin> createCoin(EntityCoords coords) override;
};

#endif // PACMAN_ENTITYFACTORY_H
