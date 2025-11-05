#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H
#include "EntityFactory.h"
#include "state/StateManager.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Game {
    std::shared_ptr<StateManager> state_manager;
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<EntityFactory> factory;
public:
    Game();

    void render();
};


#endif //PACMAN_GAME_H