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

    virtual void attach(const std::shared_ptr<Observer>& observer) { observers.push_back(observer); }

    virtual void detach(const std::shared_ptr<Observer>& observer) { observers.remove(observer); }

    virtual void detachAll() { observers.clear(); }

    virtual void notify(const std::shared_ptr<Event>& e) = 0;
    virtual void notify(const std::shared_ptr<TickEvent>& e) = 0;
    virtual void notify(const std::shared_ptr<EatenEvent>& e) = 0;
    virtual void notify(const std::shared_ptr<RenderStaticEvent>& e) = 0;
    virtual void notify(const std::shared_ptr<DirectionChangeEvent>& e) = 0;
    virtual void notify(const std::shared_ptr<CollectEvent>& e) = 0;
    virtual void notify(const std::shared_ptr<DieEvent>& e) = 0;
};
} // namespace subjects

#endif // PACMAN_SUBJECT_H