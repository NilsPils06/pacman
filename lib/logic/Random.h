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
    /**
     *
     * @return the Random instance.
     */
    static Random& getInstance();

    Random(const Random&) = delete;
    void operator=(const Random&) = delete;

    /**
     *
     * @param min minimum value (inclusive)
     * @param max maximum value (inclusive)
     * @return a value between min and max with probability p=0.5
     */
    int getInt(int min, int max);

    /**
     *
     * @param min minimum value (inclusive)
     * @param max maximum value (inclusive)
     * @return a value between min and max with probability p=0.5
     */
    float getFloat(float min, float max);

    /**
     *
     * @param max maximum value (inclusive)
     * @return a value between 0 and max with probability p=0.5
     */
    int getInt(int max);

    /**
     *
     * @param max maximum value (inclusive)
     * @return a value between 0 and max with probability p=0.5
     */
    float getFloat(float max);
};

#endif // PACMAN_RANDOM_H