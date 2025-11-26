#include "EntityView.h"

#include <SFML/Graphics/Texture.hpp>

void view::EntityView::setSprite(const std::string& file) {
    sf::Texture texture;
    if (!texture.loadFromFile(file)) {
        return;
    }
    sprite.setTexture(texture);
}
void view::EntityView::update() {}

const sf::Sprite& view::EntityView::getSprite() const { return sprite; }

void view::EntityView::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}
