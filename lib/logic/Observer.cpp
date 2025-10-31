#include "Observer.h"

Observer::Observer(subjects::Subject& subject) : subject(subject) { this->subject.attach(subject); }