#include "StateManager.h"

void StateManager::update(sf::Event event) {
    if (states.empty())
        return;
    if (event.type == sf::Event::KeyPressed) {
        states.top()->onKeyPress(event.key);
    }
}
void StateManager::render(sf::RenderWindow& window) {
    if (states.empty()) return;
    states.top()->render(window);
}

void StateManager::push(std::unique_ptr<State> s) { states.push(std::move(s)); }
void StateManager::pop() { states.pop(); }