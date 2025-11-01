#ifndef PACMAN_LEVELSTATE_H
#define PACMAN_LEVELSTATE_H
#include "State.h"

class LevelState : public State {
public:
    explicit LevelState(const std::shared_ptr<StateManager>& manager) : State(manager) {}

    void onKeyPress(sf::Event::KeyEvent event) override;

    void render(sf::RenderWindow& window) override;
};

#endif // PACMAN_LEVELSTATE_H
