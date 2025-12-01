#include "Wall.h"

class CollisionVisitor;
void subjects::Wall::tick() {}
void subjects::Wall::accept(std::shared_ptr<CollisionVisitor> visitor) const {
    visitor->visit(shared_from_this());
}
