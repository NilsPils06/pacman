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
    EntityView(const std::shared_ptr<subjects::Subject>& subject, const std::shared_ptr<sf::RenderWindow>& window)
        : Observer(subject), window(window) {}

    void setSprite(const std::string& file);

    const sf::Sprite& getSprite() const;

    void setPosition(int x, int y);

    void update() override;
};

namespace Sprites {
// Afmetingen zijn altijd hetzelfde
const sf::Vector2i SIZE(50, 50);

// Hardcoded startposities (X, Y) gevonden via Paint
const sf::Vector2i GHOST_RED_RIGHT_1(0, 0);
const sf::Vector2i GHOST_RED_RIGHT_2(17, 0); // Aanname: 1px padding

const sf::Vector2i FRUIT_CHERRY(300, 20);    // Voorbeeldwaarde!
const sf::Vector2i FRUIT_STRAWBERRY(300, 40); // Voorbeeldwaarde!
}
} // namespace view

#endif // PACMAN_ENTITYVIEW_H
