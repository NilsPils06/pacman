#include "Fruit.h"
void subjects::Fruit::accept(std::shared_ptr<CollisionVisitor> visitor) { visitor->visit(shared_from_this()); }