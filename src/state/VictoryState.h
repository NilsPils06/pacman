#ifndef PACMAN_VICTORYSTATE_H
#define PACMAN_VICTORYSTATE_H
#include "State.h"

class VictoryState final : public State {
    int level = 0;
public:
    explicit VictoryState(const std::shared_ptr<StateManager>& manager, int level) : State(manager), level(level) {}
    void onKeyPress(sf::Event::KeyEvent event) override;
    void render() override;
};

#endif // PACMAN_VICTORYSTATE_H
