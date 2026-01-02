#ifndef PACMAN_STOPWATCH_H
#define PACMAN_STOPWATCH_H
#include <chrono>
#include <memory>

class Stopwatch {
    std::chrono::steady_clock::time_point lastTime;
    float deltaTime = 0;

    static std::unique_ptr<Stopwatch> instance;

    Stopwatch() = default;

public:
    /**
     *
     * @return the Stopwatch instance.
     */
    static Stopwatch& getInstance();

    /**
     * @brief Updates lastTime and deltaTime.
     * @return deltaTime
     */
    float tick();

    /**
     *
     * @return deltaTime.
     */
    [[nodiscard]] float getDeltaTime() const;

    /**
     * @brief Resets the Stopwatch.
     */
    void reset();

    Stopwatch(const Stopwatch&) = delete;
    void operator=(const Stopwatch&) = delete;
};

#endif // PACMAN_STOPWATCH_H