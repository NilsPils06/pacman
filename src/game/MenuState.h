#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "State.h"

class MenuState : public State {
public:
    void handle1() override;
    void handle2() override;
};

#endif // PACMAN_MENUSTATE_H
