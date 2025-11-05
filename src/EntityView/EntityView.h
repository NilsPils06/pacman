#ifndef PACMAN_ENTITYVIEW_H
#define PACMAN_ENTITYVIEW_H
#include "EntityUtil.h"
#include "Observer.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <utility>

namespace view {
class EntityView : public Observer {
protected:
    sf::Sprite sprite;
    std::shared_ptr<sf::RenderWindow> window;

public:
    EntityView(const std::shared_ptr<subjects::Subject>& subject, sf::Sprite sprite,
               const std::shared_ptr<sf::RenderWindow>& window)
        : Observer(subject), sprite(std::move(sprite)), window(window) {}

    void setSprite(const std::string& file);

    void render(EntityCoords coords);
};
} // namespace view

#endif // PACMAN_ENTITYVIEW_H
