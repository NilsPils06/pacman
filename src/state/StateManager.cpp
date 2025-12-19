#include "StateManager.h"

#include <utility>

void StateManager::update(const sf::Event& event) {
    if (states.empty())
        return;
    if (event.type == sf::Event::KeyPressed) {
        states.top()->onKeyPress(event.key);
    }
    if (event.type == sf::Event::TextEntered) {
        states.top()->onTextEntered(event.text);
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        states.top()->onMouseClick(event.mouseButton);
    }
}
void StateManager::render() {
    if (states.empty())
        return;
    states.top()->render();
}

void StateManager::push(std::unique_ptr<State> s) { states.push(std::move(s)); }
void StateManager::pop() { states.pop(); }