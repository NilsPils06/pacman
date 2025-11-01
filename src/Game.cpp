#include "Game.h"

#include "state/MenuState.h"

#include <SFML/Graphics.hpp>

Game::Game() {
    state_manager = std::make_shared<StateManager>();
    state_manager->push(std::make_unique<MenuState>(state_manager));
    window.create(sf::VideoMode(800, 600), "Pacman");
}

void Game::render() {
    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            state_manager->update(event);
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();
        state_manager->render(window);

        // Update the window
        window.display();
    }
}