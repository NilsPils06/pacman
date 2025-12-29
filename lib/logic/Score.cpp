#include "Score.h"

#include "Event.h"
#include "Stopwatch.h"
void Score::update(const std::shared_ptr<Event> e) {
    if (e->getType() == COLLECT) {
        const std::shared_ptr<CollectEvent> event = std::static_pointer_cast<CollectEvent>(e);

        const auto base = static_cast<float>(event->getPoints());
        const int bonus = static_cast<int>(base / (timeSinceCollection + 0.1f));

        score += static_cast<int>(base) + bonus;
        timeSinceCollection = 0.0f;
    }
}
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