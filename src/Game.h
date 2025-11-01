#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H
#include "state/StateManager.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class Game {
    std::shared_ptr<StateManager> state_manager;
    sf::RenderWindow window;
public:
    Game();

    void render();
};


#endif //PACMAN_GAME_H