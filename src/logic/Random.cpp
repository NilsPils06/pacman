#include "Random.h"

Random & Random::getInstance() {
    return random;
}

int Random::generateInt() {
    std::uniform_int_distribution<> dis(1, 2);
    return dis(gen);
}
