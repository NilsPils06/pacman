#include "Wall.h"
view::Wall::Wall(const std::shared_ptr<subjects::Subject>& subject, const std::shared_ptr<sf::RenderWindow>& window)
    : EntityView(subject, window) {}
