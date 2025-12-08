#ifndef PACMAN_STOPWATCH_H
#define PACMAN_STOPWATCH_H
#include <chrono>
#include <memory>

class Stopwatch {
    std::chrono::steady_clock::time_point lastTime;
    float deltaTime;

    static std::unique_ptr<Stopwatch> instance;

    Stopwatch() = default;

public:
    static Stopwatch& getInstance();

    float tick();

    [[nodiscard]] float getDeltaTime() const;

    void reset();

    Stopwatch(const Stopwatch&) = delete;
    void operator=(const Stopwatch&) = delete;
};

#endif // PACMAN_STOPWATCH_H