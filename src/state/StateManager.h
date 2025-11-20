#ifndef PACMAN_STATEMANAGER_H
#define PACMAN_STATEMANAGER_H
#include "State.h"

#include <memory>
#include <stack>

class StateManager {
    std::stack<std::unique_ptr<State>> states;
public:
    explicit StateManager() = default;

    void update(const sf::Event& event);

    void render();

    void push(std::unique_ptr<State> s);

    void pop();
};

#endif // PACMAN_STATEMANAGER_H
