#ifndef PACMAN_VICTORYSTATE_H
#define PACMAN_VICTORYSTATE_H
#include "State.h"

class VictoryState final : public State {
public:
    explicit VictoryState(const std::shared_ptr<StateManager>& manager) : State(manager) {}
    void onKeyPress(sf::Event::KeyEvent event) override;
    void render() override;
};

#endif // PACMAN_VICTORYSTATE_H
