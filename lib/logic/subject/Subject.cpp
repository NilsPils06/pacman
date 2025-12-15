#include "Subject.h"

void subjects::Subject::attach(const std::shared_ptr<Observer>& observer) { observers.push_back(observer); }
void subjects::Subject::detach(const std::shared_ptr<Observer>& observer) { observers.remove(observer); }
void subjects::Subject::detachAll() { observers.clear(); }