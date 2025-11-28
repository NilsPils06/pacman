#ifndef PACMAN_STOPWATCH_H
#define PACMAN_STOPWATCH_H
#include <memory>

class Stopwatch {
    int tick = 0;
    int deltaTime = 0;

    static std::unique_ptr<Stopwatch> instance;

    Stopwatch() = default;
public:
    static Stopwatch& getInstance();

    Stopwatch(const Stopwatch&) = delete;
    void operator=(const Stopwatch&) = delete;
};


#endif //PACMAN_STOPWATCH_H