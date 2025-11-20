#ifndef PACMAN_VIEW_WALL_H
#define PACMAN_VIEW_WALL_H
#include "EntityView.h"

namespace view {
class Wall : public EntityView {
public:
    Wall(const std::shared_ptr<subjects::Subject>& subject, const std::shared_ptr<sf::RenderWindow>& window);
};
}

#endif // PACMAN_VIEW_WALL_H
