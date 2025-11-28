#include "Stopwatch.h"

std::unique_ptr<Stopwatch> Stopwatch::instance = nullptr;

Stopwatch& Stopwatch::getInstance() {
    if (instance == nullptr) {
        instance.reset(new Stopwatch());
    }
    return *instance;
}
