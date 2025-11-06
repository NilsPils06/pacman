#include "EntityView.h"

#include <SFML/Graphics/Texture.hpp>

void view::EntityView::setSprite(const std::string& file) {
    sf::Texture texture;
    if (!texture.loadFromFile(file)) {
        return;
    }
    this->sprite.setTexture(texture);
}