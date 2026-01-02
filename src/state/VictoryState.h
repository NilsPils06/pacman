#ifndef PACMAN_VICTORYSTATE_H
#define PACMAN_VICTORYSTATE_H
#include "State.h"

class VictoryState final : public State {
    int level = 0;

public:
    /**
     * @brief Constructs a VictoryState object.
     * @param manager the StateManager to manage this State.
     * @param level the level you beat.
     */
    explicit VictoryState(const std::shared_ptr<StateManager>& manager, const int level) : State(manager), level(level) {}

    /**
     * @brief Handles key presses.
     * @param event a SFML KeyEvent.
     */
    void onKeyPress(sf::Event::KeyEvent event) override;

    /**
     * @brief Renders the state to the screen.
     */
    void render() override;
};

#endif // PACMAN_VICTORYSTATE_H
