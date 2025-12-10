#include "Score.h"

#include "Event.h"
void Score::update(std::shared_ptr<Event> e) {
    if (e->getType() == COLLECT) {
        const std::shared_ptr<CollectEvent> event = std::static_pointer_cast<CollectEvent>(e);
        score += event->getCollectable()->getScoreMultiplier();
    }
}
int Score::getScore() const { return score; }