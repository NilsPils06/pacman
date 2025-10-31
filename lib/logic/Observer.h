#ifndef PACMAN_OBSERVER_H
#define PACMAN_OBSERVER_H
#include "subject/Subject.h"

class Observer {
    subjects::Subject& subject;

public:
    virtual ~Observer() = default;

    explicit Observer(subjects::Subject& subject);

    virtual void update() = 0;
};

#endif // PACMAN_OBSERVER_H
