#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "State.h"

class MenuState : public State {
public:
    MenuState() = default;

    ~MenuState() override;

    void handle1() override;
    void handle2() override;
};

#endif // PACMAN_MENUSTATE_H
