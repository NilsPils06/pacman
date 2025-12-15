#ifndef PACMAN_PAUSEDSTATE_H
#define PACMAN_PAUSEDSTATE_H
#include "State.h"

class PausedState final : public State {
public:
    explicit PausedState(const std::shared_ptr<StateManager>& manager) : State(manager) {}

    void onKeyPress(sf::Event::KeyEvent event) override;

    void render() override;
};

#endif // PACMAN_PAUSEDSTATE_H
