#ifndef PACMAN_STATE_H
#define PACMAN_STATE_H

class State {
public:
    virtual ~State() = default;

    virtual void handle1() = 0;

    virtual void handle2() = 0;
};

#endif // PACMAN_STATE_H
