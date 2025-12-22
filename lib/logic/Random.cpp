#include "Random.h"

std::unique_ptr<Random> Random::instance = nullptr;

Random::Random() : gen(rd()) {}

Random& Random::getInstance() {
    if (instance == nullptr) {
        instance.reset(new Random());
    }
    return *instance;
}

int Random::getInt(const int min, const int max) {
    std::uniform_int_distribution dis(min, max);
    return dis(gen);
}

float Random::getFloat(const float min, const float max) {
    std::uniform_real_distribution dis(min, max);
    return dis(gen);
}
int Random::getInt(const int max) {
    return getInt(0, max);
}
float Random::getFloat(const float max) {
    return getFloat(0.f,max);
}
