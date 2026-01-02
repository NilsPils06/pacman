#ifndef PACMAN_OBSERVER_H
#define PACMAN_OBSERVER_H
#include "Event.h"
#include <memory>

namespace subjects {
class Subject;
}

class Observer {
    std::weak_ptr<subjects::Subject> subject;

public:
    /**
     * @brief Destructs the Observer.
     */
    virtual ~Observer() = default;

    /**
     * @brief Constructs an empty Observer object.
     */
    Observer() = default;

    /**
     * @brief Constructs an Observer object.
     * @param subject the subject to observe.
     */
    explicit Observer(const std::shared_ptr<subjects::Subject>& subject) : subject(subject) {}

    /**
     * @brief Handles event e.
     * @param e
     */
    virtual void update(const std::shared_ptr<Event>& e) {}

    /**
     * @brief Handles event e.
     * @param e
     */
    virtual void update(const std::shared_ptr<TickEvent>& e) = 0;

    /**
     * @brief Handles event e.
     * @param e
     */
    virtual void update(const std::shared_ptr<EatenEvent>& e) = 0;

    /**
     * @brief Handles event e.
     * @param e
     */
    virtual void update(const std::shared_ptr<RenderStaticEvent>& e) = 0;

    /**
     * @brief Handles event e.
     * @param e
     */
    virtual void update(const std::shared_ptr<DirectionChangeEvent>& e) = 0;

    /**
     * @brief Handles event e.
     * @param e
     */
    virtual void update(const std::shared_ptr<CollectEvent>& e) = 0;

    /**
     * @brief Handles event e.
     * @param e
     */
    virtual void update(const std::shared_ptr<DieEvent>& e) = 0;

    /**
     * @brief Updates the subject to be observed.
     * @param s the new subject.
     */
    void setSubject(const std::weak_ptr<subjects::Subject>& s) { this->subject = s; }
};

#endif // PACMAN_OBSERVER_H
