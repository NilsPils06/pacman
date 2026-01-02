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
    /**
     * @brief Destructs the object.
     */
    virtual ~CollisionVisitor() = default;

    /**
     * @brief Executes Coin collision behaviour.
     * @param e a coin pointer.
     */
    virtual void visit(std::shared_ptr<subjects::Coin> e) = 0;

    /**
     * @brief Executes Fruit collision behaviour.
     * @param e a fruit pointer.
     */
    virtual void visit(std::shared_ptr<subjects::Fruit> e) = 0;

    /**
     * @brief Executes Ghost collision behaviour.
     * @param e a ghost pointer.
     */
    virtual void visit(std::shared_ptr<subjects::Ghost> e) = 0;
};

class CollisionComponent {
public:
    /**
     * @brief Constructs a CollisionComponent object.
     */
    virtual ~CollisionComponent() = default;

    /**
     * @brief Calls the visit function of the visitor.
     * @param visitor the CollisionVisitor who collides with this object.
     */
    virtual void accept(std::shared_ptr<CollisionVisitor> visitor) = 0;
};

#endif // PACMAN_VISITOR_H
