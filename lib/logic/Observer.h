#ifndef PACMAN_OBSERVER_H
#define PACMAN_OBSERVER_H
#include <memory>
#include "Event.h"

namespace subjects {
class Subject;
}

class Observer {
    std::weak_ptr<subjects::Subject> subject;

public:
    virtual ~Observer() = default;

    Observer() = default;

    explicit Observer(const std::shared_ptr<subjects::Subject>& subject) : subject(subject) {}

    virtual void update(const std::shared_ptr<Event>& e) {}
    virtual void update(const std::shared_ptr<TickEvent>& e) = 0;
    virtual void update(const std::shared_ptr<EatenEvent>& e) = 0;
    virtual void update(const std::shared_ptr<RenderStaticEvent>& e) = 0;
    virtual void update(const std::shared_ptr<DirectionChangeEvent>& e) = 0;
    virtual void update(const std::shared_ptr<CollectEvent>& e) = 0;
    virtual void update(const std::shared_ptr<DieEvent>& e) = 0;

    void setSubject(const std::weak_ptr<subjects::Subject>& s) { this->subject = s; }
};

#endif // PACMAN_OBSERVER_H
