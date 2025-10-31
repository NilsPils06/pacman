#include "Subject.h"

void subjects::Subject::attach(std::shared_ptr<Observer> observer) { observers.push_back(observer); }
void subjects::Subject::detach(std::weak_ptr<Observer> observer) {
    observers.remove_if([&observer](const std::weak_ptr<Observer>& weak) {
        // Check if either pointer has expired. If so, they are "equal" if both are expired.
        return weak.expired() || observer.expired()
                   ? weak.expired() == observer.expired()
                   : weak.lock() == observer.lock(); // Compare the underlying raw pointers
    });
}