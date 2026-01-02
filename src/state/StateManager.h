#ifndef PACMAN_STATEMANAGER_H
#define PACMAN_STATEMANAGER_H
#include "State.h"

#include <memory>
#include <stack>

class StateManager {
    std::stack<std::unique_ptr<State>> states;

public:
    /**
     * @brief Constructs a StateManager object.
     */
    explicit StateManager() = default;

    /**
     * @brief Makes the top state handle an event (text input, key press and mouse click).
     * @param event a SFML Event.
     */
    void update(const sf::Event& event);

    /**
     * @brief Renders the top state.
     */
    void render();

    /**
     * @brief Pushes a State onto the stack.
     * @param s the State to push.
     */
    void push(std::unique_ptr<State> s);

    /**
     * @brief Pops a State off the stack.
     */
    void pop();
};

#endif // PACMAN_STATEMANAGER_H
