#include "Ghost.h"
#include "../Event.h"
void subjects::Ghost::tick() { notify(std::make_shared<PositonUpdateEvent>(getCoords())); }
void subjects::Ghost::accept(std::shared_ptr<CollisionVisitor> visitor) {
    visitor->visit(shared_from_this());
}