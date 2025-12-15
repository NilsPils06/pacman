#ifndef PACMAN_ENTITYVIEW_H
#define PACMAN_ENTITYVIEW_H

#include "Observer.h"
#include <SFML/Graphics/Sprite.hpp>

// TODO update EntityView so that it contains the animation sequence

namespace view {
class EntityView : public Observer {
protected:
    sf::Sprite sprite;

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
const sf::IntRect GHOST_RED_RIGHT_2(-7, 46, 50, 50);
const sf::IntRect COIN(393, 246, 50, 50);
const sf::IntRect FRUIT(593, -4, 50, 50);
const sf::IntRect PACMAN_RIGHT_1(843, -4, 50, 50);
const sf::IntRect PACMAN_RIGHT_2(843, 46, 50, 50);
const sf::IntRect PACMAN_RIGHT_3(843, 96, 50, 50);
const sf::IntRect PACMAN_DOWN_1(843, 146, 50, 50);
const sf::IntRect PACMAN_DOWN_2(843, 196, 50, 50);
const sf::IntRect PACMAN_DOWN_3(843, 246, 50, 50);
const sf::IntRect PACMAN_LEFT_1(843, 296, 50, 50);
const sf::IntRect PACMAN_LEFT_2(843, 346, 50, 50);
const sf::IntRect PACMAN_LEFT_3(843, 396, 50, 50);
const sf::IntRect PACMAN_UP_1(843, 446, 50, 50);
const sf::IntRect PACMAN_UP_2(843, 496, 50, 50);
const sf::IntRect PACMAN_UP_3(843, 546, 50, 50);
const sf::IntRect WALL(516, 173, 1, 1);
} // namespace sprites

#endif // PACMAN_ENTITYVIEW_H
