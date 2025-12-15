#include "Ghost.h"
#include "../Event.h"
void subjects::Ghost::tick() {
    notify(std::make_shared<PositonUpdateEvent>(getCoords()));
}