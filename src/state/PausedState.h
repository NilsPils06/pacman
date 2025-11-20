#ifndef PACMAN_PAUSEDSTATE_H
#define PACMAN_PAUSEDSTATE_H
#include "State.h"

#include <utility>

class PausedState : public State {
public:
    explicit PausedState(const std::shared_ptr<StateManager>& manager, std::shared_ptr<sf::RenderWindow> window) : State(manager, std::move(window)) {}

    void onKeyPress(sf::Event::KeyEvent event) override;

    void render() override;
};

#endif // PACMAN_PAUSEDSTATE_H
