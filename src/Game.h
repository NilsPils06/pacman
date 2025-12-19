#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H
#include "state/StateManager.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
    std::shared_ptr<StateManager> state_manager;

public:
    static sf::RenderWindow window;
    static inline sf::Font font;
    static inline sf::Font fontFront;
    static inline sf::Texture texture;

    Game();

    void render() const;
};

#endif // PACMAN_GAME_H