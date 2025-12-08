#include "Random.h"

Random& Random::getInstance() { return random; }

int Random::generateInt() {
    std::binomial_distribution<> dis(1, 0.5);
    return dis(gen);
}
