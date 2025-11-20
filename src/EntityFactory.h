#ifndef PACMAN_ENTITYFACTORY_H
#define PACMAN_ENTITYFACTORY_H
#include "AbstractFactory.h"
#include <SFML/Graphics/RenderWindow.hpp>

class EntityFactory final : public AbstractFactory {
    std::shared_ptr<sf::RenderWindow> window;

public:
    explicit EntityFactory(const std::shared_ptr<sf::RenderWindow>& window);

    subjects::Ghost createGhost() override;
    subjects::Pacman createPacman() override;
    subjects::Fruit createFruit() override;
    subjects::Coin createCoin() override;
    subjects::Wall createWall() override;
    subjects::Wall createWall(float x, float y) override;
    subjects::Ghost createGhost(float x, float y) override;
};

#endif // PACMAN_ENTITYFACTORY_H
