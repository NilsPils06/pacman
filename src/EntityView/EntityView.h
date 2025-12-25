#ifndef PACMAN_ENTITYVIEW_H
#define PACMAN_ENTITYVIEW_H

#include "Observer.h"
#include <SFML/Graphics/Sprite.hpp>

namespace view {
class EntityView : public Observer {
protected:
    sf::Sprite sprite;

public:
    explicit EntityView(const std::shared_ptr<subjects::Subject>& subject) : Observer(subject) {}

    void setSprite(const sf::IntRect& spriteRect);

    const sf::Sprite& getSprite() const;

    void update(std::shared_ptr<Event> e) override;
};
} // namespace view

namespace sprites {
const sf::IntRect GHOST_RED_RIGHT_1(-7, -4, 50, 50);
const sf::IntRect GHOST_RED_RIGHT_2(-7, 46, 50, 50);
const sf::IntRect GHOST_RED_DOWN_1(-7, 96, 50, 50);
const sf::IntRect GHOST_RED_DOWN_2(-7, 146, 50, 50);
const sf::IntRect GHOST_RED_LEFT_1(-7, 196, 50, 50);
const sf::IntRect GHOST_RED_LEFT_2(-7, 246, 50, 50);
const sf::IntRect GHOST_RED_UP_1(-7, 296, 50, 50);
const sf::IntRect GHOST_RED_UP_2(-7, 346, 50, 50);

const sf::IntRect GHOST_PINK_RIGHT_1(43, -4, 50, 50);
const sf::IntRect GHOST_PINK_RIGHT_2(43, 46, 50, 50);
const sf::IntRect GHOST_PINK_DOWN_1(43, 96, 50, 50);
const sf::IntRect GHOST_PINK_DOWN_2(43, 146, 50, 50);
const sf::IntRect GHOST_PINK_LEFT_1(43, 196, 50, 50);
const sf::IntRect GHOST_PINK_LEFT_2(43, 246, 50, 50);
const sf::IntRect GHOST_PINK_UP_1(43, 296, 50, 50);
const sf::IntRect GHOST_PINK_UP_2(43, 346, 50, 50);

const sf::IntRect GHOST_BLUE_RIGHT_1(93, -4, 50, 50);
const sf::IntRect GHOST_BLUE_RIGHT_2(93, 46, 50, 50);
const sf::IntRect GHOST_BLUE_DOWN_1(93, 96, 50, 50);
const sf::IntRect GHOST_BLUE_DOWN_2(93, 146, 50, 50);
const sf::IntRect GHOST_BLUE_LEFT_1(93, 196, 50, 50);
const sf::IntRect GHOST_BLUE_LEFT_2(93, 246, 50, 50);
const sf::IntRect GHOST_BLUE_UP_1(93, 296, 50, 50);
const sf::IntRect GHOST_BLUE_UP_2(93, 346, 50, 50);

const sf::IntRect GHOST_ORANGE_RIGHT_1(143, -4, 50, 50);
const sf::IntRect GHOST_ORANGE_RIGHT_2(143, 46, 50, 50);
const sf::IntRect GHOST_ORANGE_DOWN_1(143, 96, 50, 50);
const sf::IntRect GHOST_ORANGE_DOWN_2(143, 146, 50, 50);
const sf::IntRect GHOST_ORANGE_LEFT_1(143, 196, 50, 50);
const sf::IntRect GHOST_ORANGE_LEFT_2(143, 246, 50, 50);
const sf::IntRect GHOST_ORANGE_UP_1(143, 296, 50, 50);
const sf::IntRect GHOST_ORANGE_UP_2(143, 346, 50, 50);

const sf::IntRect GHOST_FEAR_1(-7, 546, 50, 50);
const sf::IntRect GHOST_FEAR_2(-7, 596, 50, 50);

const sf::IntRect COIN(393, 246, 50, 50);

const sf::IntRect FRUIT(593, -4, 50, 50);

const sf::IntRect PACMAN_DEATH_1(343, -4, 50, 50);
const sf::IntRect PACMAN_DEATH_2(343, 46, 50, 50);
const sf::IntRect PACMAN_DEATH_3(343, 96, 50, 50);
const sf::IntRect PACMAN_DEATH_4(343, 146, 50, 50);
const sf::IntRect PACMAN_DEATH_5(343, 196, 50, 50);
const sf::IntRect PACMAN_DEATH_6(343, 246, 50, 50);
const sf::IntRect PACMAN_DEATH_7(343, 296, 50, 50);
const sf::IntRect PACMAN_DEATH_8(343, 346, 50, 50);
const sf::IntRect PACMAN_DEATH_9(343, 396, 50, 50);
const sf::IntRect PACMAN_DEATH_10(343, 446, 50, 50);
const sf::IntRect PACMAN_DEATH_11(343, 496, 50, 50);
const sf::IntRect PACMAN_DEATH_12(343, 546, 50, 50);

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
