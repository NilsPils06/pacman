#ifndef PACMAN_DEFEATSTATE_H
#define PACMAN_DEFEATSTATE_H
#include "State.h"

class DefeatState final : public State {
public:
    explicit DefeatState(const std::shared_ptr<StateManager>& manager) : State(manager) {}
    void onKeyPress(sf::Event::KeyEvent event) override;
    void render() override;
};

#endif // PACMAN_DEFEATSTATE_H
