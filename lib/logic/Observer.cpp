#include "Observer.h"
#include "subject/Subject.h"

Observer::Observer(const std::shared_ptr<subjects::Subject>& subject) : subject(subject) {};