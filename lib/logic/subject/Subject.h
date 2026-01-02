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
    /**
     * @brief Destructs the subject.
     */
    virtual ~Subject() = default;

    /**
     * @brief Attaches an observer to the subject.
     * @param observer
     */
    virtual void attach(const std::shared_ptr<Observer>& observer) { observers.push_back(observer); }

    /**
     * @brief Detaches an observer from the subject.
     * @param observer
     */
    virtual void detach(const std::shared_ptr<Observer>& observer) { observers.remove(observer); }

    /**
     * @brief Detaches all observers.
     */
    virtual void detachAll() { observers.clear(); }

    /**
     * @brief Notifies observers of e and handles it.
     * @param e an Event
     */
    virtual void notify(const std::shared_ptr<Event>& e) = 0;

    /**
     * @brief Notifies observers of e and handles it.
     * @param e a TickEvent
     */
    virtual void notify(const std::shared_ptr<TickEvent>& e) = 0;

    /**
     * @brief Notifies observers of e and handles it.
     * @param e a EatenEvent
     */
    virtual void notify(const std::shared_ptr<EatenEvent>& e) = 0;

    /**
     * @brief Notifies observers of e and handles it.
     * @param e a RenderStaticEvent
     */
    virtual void notify(const std::shared_ptr<RenderStaticEvent>& e) = 0;

    /**
     * @brief Notifies observers of e and handles it.
     * @param e a DirectionChangeEvent
     */
    virtual void notify(const std::shared_ptr<DirectionChangeEvent>& e) = 0;

    /**
     * @brief Notifies observers of e and handles it.
     * @param e a CollectEvent
     */
    virtual void notify(const std::shared_ptr<CollectEvent>& e) = 0;

    /**
     * @brief Notifies observers of e and handles it.
     * @param e a DieEvent
     */
    virtual void notify(const std::shared_ptr<DieEvent>& e) = 0;
};
} // namespace subjects

#endif // PACMAN_SUBJECT_H