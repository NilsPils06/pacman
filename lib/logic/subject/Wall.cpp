#include "Wall.h"

#include "../Event.h"

class CollisionVisitor;
void subjects::Wall::tick() {
    notify(std::make_shared<PositonUpdateEvent>(getCoords()));
}
void subjects::Wall::accept(const std::shared_ptr<CollisionVisitor> visitor) { visitor->visit(shared_from_this()); }
