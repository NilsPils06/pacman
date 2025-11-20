#include "LevelState.h"

#include "PausedState.h"
#include "StateManager.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <fstream>
void LevelState::onKeyPress(sf::Event::KeyEvent event) {
    if (event.code == sf::Keyboard::Escape) {
        if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
            state_manager->push(std::make_unique<PausedState>(state_manager));
        }
    }
}
void LevelState::render(std::shared_ptr<sf::RenderWindow> window) {
    sf::Texture texture;
    if (!texture.loadFromFile("../../assets/sprite.png"))
        return;
    sf::Sprite sprite(texture);

    // Draw the sprite
    window->draw(sprite);
}
LevelState::LevelState(const std::shared_ptr<StateManager>& manager) : State(manager) {
    std::ifstream file;
    file.open("../../assets/maps/1.txt");

    std::string line;
    int height = 0;
    int width = 0;
    while (std::getline(file, line)) {
        ++height;
        width = std::max(width, static_cast<int>(line.length()));
    }

    float max_x = static_cast<float>(width - 1);
    float max_y = static_cast<float>(height - 1);

    char token;
    int x = 0;
    int y = 0;

    while (file.get(token)) {
        float normalized_x = 2.0f * ((float)x / max_x) - 1.0f;
        float normalized_y = 2.0f * ((float)y / max_y) - 1.0f;

        switch (token) {
        case 'W':
            break;
        case '_':
            break;
        case 'F':
            break;
        case 'C':
            break;
        case 'P':
            break;
        case 'G':
            break;
        default:
            x = 0;
            y += 1;
            continue;
        }

        // voeg entitymodel toe aan world

        x += 1;
    }
}
