#include "Score.h"

#include "Event.h"
#include "Stopwatch.h"
void Score::tick() {
    const float deltaTime = Stopwatch::getInstance().getDeltaTime();
    pendingLoss += deltaTime;
    timeSinceCollection += deltaTime;
    if (pendingLoss >= 1 && pendingLoss < 2) {
        score--;
        pendingLoss--;
    }
}
int Score::getScore() const { return score; }
void Score::completeLevel(const int level) {
    score += level*1000;
}
void Score::update(const std::shared_ptr<CollectEvent>& e) {
    const auto base = static_cast<float>(e->getPoints());
    const int bonus = std::min(static_cast<int>(base / (timeSinceCollection + 0.1f)), static_cast<int>(base));

    score += static_cast<int>(base) + bonus;
    timeSinceCollection = 0.0f;
}