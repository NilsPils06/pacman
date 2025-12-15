#include "Collectable.h"
#include "../Event.h"
void subjects::Collectable::tick() {
    notify(std::make_shared<PositonUpdateEvent>(getCoords()));
}
int subjects::Collectable::getScoreMultiplier() const { return multiplier; }