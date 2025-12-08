#include "Stopwatch.h"

std::unique_ptr<Stopwatch> Stopwatch::instance = nullptr;

Stopwatch& Stopwatch::getInstance() {
    if (instance == nullptr) {
        instance.reset(new Stopwatch());
        // own reset function
        instance->reset();
    }
    return *instance;
}
float Stopwatch::tick() {
    const auto currentTime = std::chrono::steady_clock::now();
    const std::chrono::duration<float> elapsed = currentTime - lastTime;

    deltaTime = elapsed.count();
    lastTime = currentTime;

    return deltaTime;
}
float Stopwatch::getDeltaTime() const { return deltaTime; }
void Stopwatch::reset() {
    lastTime = std::chrono::steady_clock::now();
    deltaTime = 0.0f;
}
