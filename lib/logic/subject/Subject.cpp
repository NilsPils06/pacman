#include "Subject.h"

void subjects::Subject::attach(std::shared_ptr<Observer> observer) { observers.push_back(observer); }
void subjects::Subject::detach(std::shared_ptr<Observer> observer) {
    observers.remove(observer);
}