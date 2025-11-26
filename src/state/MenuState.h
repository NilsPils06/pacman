#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "State.h"

#include <utility>

class MenuState : public State {
public:
    explicit MenuState(const std::shared_ptr<StateManager>& manager) : State(manager) {}

    ~MenuState() override;

    void onKeyPress(sf::Event::KeyEvent event) override;

    void render() override;
};

#endif // PACMAN_MENUSTATE_H
