#include "Score.h"

#include "Event.h"
#include "Stopwatch.h"
void Score::update(std::shared_ptr<Event> e) {
    if (e->getType() == COLLECT) {
        const std::shared_ptr<CollectEvent> event = std::static_pointer_cast<CollectEvent>(e);
        score += event->getCollectable()->getScoreMultiplier();
    }
}
void Score::tick() {
    pendingLoss += Stopwatch::getInstance().getDeltaTime();
    if (pendingLoss >= 1 && pendingLoss < 2) {
        score--;
        pendingLoss--;
    }
}
int Score::getScore() const { return score; }