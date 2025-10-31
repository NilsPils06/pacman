#ifndef PACMAN_OBSERVER_H
#define PACMAN_OBSERVER_H
#include <memory>

namespace subjects {
class Subject;
}

class Observer : public std::enable_shared_from_this<Observer>{
    std::weak_ptr<subjects::Subject> subject;

public:
    virtual ~Observer() = default;

    explicit Observer(std::shared_ptr<subjects::Subject> subject);

    virtual void update() = 0;
};

#endif // PACMAN_OBSERVER_H
