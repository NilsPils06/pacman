#ifndef PACMAN_SUBJECT_H
#define PACMAN_SUBJECT_H
#include "../Observer.h"

#include <list>
#include <memory>

namespace subjects {
class Subject {
protected:
    std::list<std::weak_ptr<Observer>> observers;

public:
    virtual ~Subject() = default;

    virtual void attach(std::shared_ptr<Observer> observer);

    virtual void detach(std::weak_ptr<Observer> observer);

    virtual void notify(std::shared_ptr<Event> e) = 0;
};
} // namespace subjects

#endif // PACMAN_SUBJECT_H