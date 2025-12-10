#ifndef PACMAN_VISITOR_H
#define PACMAN_VISITOR_H
#include <memory>

// Visitor pattern

// Forward declaration
namespace subjects {
class Ghost;
class Wall;
class Coin;
class Fruit;
} // namespace subjects

class CollisionVisitor {
public:
    virtual ~CollisionVisitor() = default;
    virtual void visit(const std::shared_ptr<const subjects::Wall>& e) = 0;
    virtual void visit(std::shared_ptr<subjects::Coin> e) = 0;
    virtual void visit(std::shared_ptr<subjects::Fruit> e) = 0;
};

class CollisionComponent {
public:
    virtual ~CollisionComponent() = default;
    virtual void accept(std::shared_ptr<CollisionVisitor> visitor) = 0;
};

#endif // PACMAN_VISITOR_H
