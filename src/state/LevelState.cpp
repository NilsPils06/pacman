#include "LevelState.h"

#include "../Camera.h"
#include "../EntityFactory.h"
#include "DefeatState.h"
#include "MenuState.h"
#include "PausedState.h"
#include "StateManager.h"
#include "VictoryState.h"
#include <SFML/Graphics/Text.hpp>
#include <fstream>
#include <utility>
LevelState::LevelState(const std::shared_ptr<StateManager>& manager) : State(manager) {
    score = std::make_shared<Score>();
    factory = std::make_shared<EntityFactory>(score);
    world = std::make_shared<World>(factory);
}
LevelState::LevelState(const std::shared_ptr<StateManager>& manager, std::string playerName,
                       const std::shared_ptr<std::map<std::string, int>>& scores)
    : State(manager), playerName(std::move(playerName)), scores(scores) {
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
void LevelState::saveScore() const {
    if (scores->contains(playerName)) {
        if (scores->at(playerName) >= score->getScore())
            return;
    }
    (*scores)[playerName] = score->getScore();
}
void LevelState::render() {
    if (world->isOver()) {
        if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
            saveScore();

            state_manager->pop();
            state_manager->push(std::make_unique<DefeatState>(state_manager));
        }
        return;
    }

    if (world->isCompleted()) {
        if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
            // reset world/new level
            state_manager->push(std::make_unique<VictoryState>(state_manager));
        }
        return;
    }

    world->render();
    score->tick();
    Camera::showScore(score->getScore());
}
