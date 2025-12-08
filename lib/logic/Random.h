#ifndef PACMAN_RANDOM_H
#define PACMAN_RANDOM_H
#include <random>

class Random {
    std::random_device rd;
    std::mt19937 gen;

    static Random random;

    Random() : gen(rd()) {}

public:
    static Random& getInstance();

    int generateInt();
};

#endif // PACMAN_RANDOM_H