#ifndef PACMAN_RANDOM_H
#define PACMAN_RANDOM_H
#include <memory>
#include <random>

class Random {
    std::random_device rd;
    std::mt19937 gen;
    static std::unique_ptr<Random> instance;

    Random();

public:
    static Random& getInstance();

    Random(const Random&) = delete;
    void operator=(const Random&) = delete;

    int getInt(int min, int max);
    float getFloat(float min, float max);

    int getInt(int max);
    float getFloat(float max);
};

#endif // PACMAN_RANDOM_H