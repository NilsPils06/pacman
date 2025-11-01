#ifndef PACMAN_PAUSEDSTATE_H
#define PACMAN_PAUSEDSTATE_H
#include "State.h"

class PausedState : public State {
public:
    explicit PausedState(const std::shared_ptr<StateManager>& manager) : State(manager) {}

    void onKeyPress(sf::Event::KeyEvent event) override;

    void render(sf::RenderWindow& window) override;
};

#endif // PACMAN_PAUSEDSTATE_H
