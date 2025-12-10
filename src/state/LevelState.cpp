#include "LevelState.h"

#include "../Camera.h"
#include "../EntityFactory.h"
#include "../Game.h"
#include "PausedState.h"
#include "StateManager.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <fstream>
LevelState::LevelState(const std::shared_ptr<StateManager>& manager) : State(manager) {
    score = std::make_shared<Score>();
    factory = std::make_shared<EntityFactory>(score);
    world = std::make_shared<World>(factory);
}

void LevelState::onKeyPress(sf::Event::KeyEvent event) {
    if (event.code == sf::Keyboard::Escape) {
        if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
            state_manager->push(std::make_unique<PausedState>(state_manager));
        }
    }
    if (event.code == sf::Keyboard::Right) {
        world->moveRight();
    }
    if (event.code == sf::Keyboard::Left) {
        world->moveLeft();
    }
    if (event.code == sf::Keyboard::Up) {
        world->moveUp();
    }
    if (event.code == sf::Keyboard::Down) {
        world->moveDown();
    }
}
void LevelState::render() {
    world->render();
    Camera::showScore(score->getScore());
}
