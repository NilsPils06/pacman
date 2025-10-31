#include "Observer.h"
#include "subject/Subject.h"

Observer::Observer(std::shared_ptr<subjects::Subject> subject) : subject(subject) {subject->attach(std::shared_ptr<Observer>(this));}