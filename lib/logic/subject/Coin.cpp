#include "Coin.h"
void subjects::Coin::accept(std::shared_ptr<CollisionVisitor> visitor) { visitor->visit(shared_from_this()); }