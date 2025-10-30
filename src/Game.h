#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H
#include "state/StateManager.h"

#include <memory>

class Game {
    std::unique_ptr<StateManager> state_manager;
public:
    Game();

    void renderWindow();
};


#endif //PACMAN_GAME_H