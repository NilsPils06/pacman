#ifndef PACMAN_OBSERVER_H
#define PACMAN_OBSERVER_H
#include <memory>

class Event;
namespace subjects {
class Subject;
}

class Observer {
    std::weak_ptr<subjects::Subject> subject;

public:
    virtual ~Observer() = default;

    Observer() = default;

    explicit Observer(const std::shared_ptr<subjects::Subject>& subject) : subject(subject) {}

    virtual void update(std::shared_ptr<Event> e) = 0;

    void setSubject(const std::weak_ptr<subjects::Subject>& s) { this->subject = s; }
};

#endif // PACMAN_OBSERVER_H
