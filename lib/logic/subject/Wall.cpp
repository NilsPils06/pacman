#include "Wall.h"

class CollisionVisitor;
void subjects::Wall::tick() {}
void subjects::Wall::accept(std::shared_ptr<CollisionVisitor> visitor) {
    visitor->visit(shared_from_this());
}
