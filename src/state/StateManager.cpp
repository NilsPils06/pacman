#include "StateManager.h"

#include <utility>

void StateManager::update(const sf::Event& event) {
    if (states.empty())
        return;
    if (event.type == sf::Event::KeyPressed) {
        states.top()->onKeyPress(event.key);
    }
}
void StateManager::render() {
    if (states.empty()) return;
    states.top()->render();
}

void StateManager::push(std::unique_ptr<State> s) { states.push(std::move(s)); }
void StateManager::pop() { states.pop(); }