#include "EntityView.h"

#include <SFML/Graphics/Texture.hpp>

void view::EntityView::setSprite(const std::string& file) {
    sf::Texture texture;
    if (!texture.loadFromFile(file)) {
        return;
    }
    this->sprite.setTexture(texture);
    sf::Vector2u size = texture.getSize();
    float scaleX = 100.0f / size.x;
    float scaleY = 100.0f / size.y;
    this->sprite.setScale(scaleX, scaleY);
}
void view::EntityView::render(EntityCoords coords) {
    sprite.setPosition(coords.x, coords.y);
    window->draw(sprite);
}