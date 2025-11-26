#ifndef PACMAN_OBSERVER_H
#define PACMAN_OBSERVER_H
#include <memory>

class Event;
namespace subjects {
class Subject;
}

class Observer : public std::enable_shared_from_this<Observer>{
    std::weak_ptr<subjects::Subject> subject;

public:
    virtual ~Observer() = default;

    explicit Observer(std::shared_ptr<subjects::Subject> subject);

    virtual void update(std::shared_ptr<Event> e) = 0;
};

#endif // PACMAN_OBSERVER_H
