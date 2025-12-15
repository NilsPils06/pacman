#ifndef PACMAN_SUBJECT_H
#define PACMAN_SUBJECT_H
#include "../Observer.h"

#include <list>
#include <memory>

namespace subjects {
class Subject {
protected:
    std::list<std::shared_ptr<Observer>> observers;

public:
    virtual ~Subject() = default;

    virtual void attach(const std::shared_ptr<Observer>& observer);

    virtual void detach(const std::shared_ptr<Observer>& observer);

    virtual void detachAll();

    virtual void notify(std::shared_ptr<Event> e) = 0;
};
} // namespace subjects

#endif // PACMAN_SUBJECT_H