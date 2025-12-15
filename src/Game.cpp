#include "Game.h"

#include "Camera.h"
#include "Stopwatch.h"
#include "state/MenuState.h"

#include <SFML/Graphics.hpp>

sf::RenderWindow Game::window{sf::VideoMode::getDesktopMode(), "Pacman"};

Game::Game() {
    state_manager = std::make_shared<StateManager>();
    state_manager->push(std::make_unique<MenuState>(state_manager));
    if (!texture.loadFromFile("../../assets/sprite.png"))
        throw std::runtime_error("Failed to load texture!");

    if (!font.loadFromFile("../../assets/crackman/Crackman.otf"))
        throw std::runtime_error("Failed to load font!");
}

void Game::render() const {
    // Start the game loop
    while (window.isOpen()) {
        Stopwatch::getInstance().tick();

        // Process events
        sf::Event event{};
        while (window.pollEvent(event)) {
            state_manager->update(event);
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();
        state_manager->render();

        // Update the window
        window.display();
    }
}