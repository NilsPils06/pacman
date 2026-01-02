#ifndef PACMAN_DEFEATSTATE_H
#define PACMAN_DEFEATSTATE_H
#include "State.h"

class DefeatState final : public State {
public:
    /**
     * @brief Constructs a DefeatState object.
     * @param manager the StateManager to manage this State.
     */
    explicit DefeatState(const std::shared_ptr<StateManager>& manager) : State(manager) {}

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

#endif // PACMAN_DEFEATSTATE_H
