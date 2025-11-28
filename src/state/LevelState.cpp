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
    factory = std::make_shared<EntityFactory>();
    world = std::make_shared<World>(factory);
}

void LevelState::onKeyPress(sf::Event::KeyEvent event) {
    if (event.code == sf::Keyboard::Escape) {
        if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
            state_manager->push(std::make_unique<PausedState>(state_manager));
        }
    }
}
void LevelState::render() {
    world->render();
}
