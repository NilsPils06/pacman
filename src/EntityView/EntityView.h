#ifndef PACMAN_ENTITYVIEW_H
#define PACMAN_ENTITYVIEW_H

#include "Observer.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace view {
class EntityView : public Observer {
protected:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    explicit EntityView(const std::shared_ptr<subjects::Subject>& subject) : Observer(subject) {}

    void setSprite(const sf::IntRect& spriteRect);

    // virtual void updateSprite(int i) = 0;

    const sf::Sprite& getSprite() const;

    void update(std::shared_ptr<Event> e) override;
};
} // namespace view

namespace sprites {
const sf::IntRect GHOST_RED_RIGHT_1(-7, -4, 50, 50);
} // namespace sprites

#endif // PACMAN_ENTITYVIEW_H
