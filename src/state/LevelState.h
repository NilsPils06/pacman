#ifndef PACMAN_LEVELSTATE_H
#define PACMAN_LEVELSTATE_H
#include "State.h"
#include "World.h"

class LevelState : public State {
    std::shared_ptr<World> world;

public:
    explicit LevelState(const std::shared_ptr<StateManager>& manager);

    void onKeyPress(sf::Event::KeyEvent event) override;

    void render(std::shared_ptr<sf::RenderWindow> window) override;
};

#endif // PACMAN_LEVELSTATE_H
