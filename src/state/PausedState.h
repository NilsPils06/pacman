#ifndef PACMAN_PAUSEDSTATE_H
#define PACMAN_PAUSEDSTATE_H
#include "State.h"

class PausedState final : public State {
public:
    /**
     * @brief Constructs a PausedState object.
     * @param manager the StateManager to manage this State.
     */
    explicit PausedState(const std::shared_ptr<StateManager>& manager) : State(manager) {}

    /**
     * @brief Handles key presses.
     * @param event a SFML KeyEvent.
     */
    void onKeyPress(sf::Event::KeyEvent event) override;

    /**
     * @brief Renders this State to the screen.
     */
    void render() override;
};

#endif // PACMAN_PAUSEDSTATE_H
