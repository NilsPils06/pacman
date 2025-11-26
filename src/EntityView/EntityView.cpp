#include "EntityView.h"

#include "../Camera.h"
#include "Event.h"

#include <SFML/Graphics/Texture.hpp>

void view::EntityView::setSprite(const sf::IntRect& spriteRect) {
    if (sprite.getTexture() == nullptr) {
        sf::Texture texture;
        if (!texture.loadFromFile("../../assets/sprite.png")) {
            return;
        }
        sprite.setTexture(texture);
    }

    sprite.setTextureRect(spriteRect);
}

const sf::Sprite& view::EntityView::getSprite() const { return sprite; }

void view::EntityView::update(std::shared_ptr<Event> e) {
    if (e->getType() == POSITION_UPDATE) {
        std::shared_ptr<PositonUpdateEvent> event = std::static_pointer_cast<PositonUpdateEvent>(e);

        Camera::getInstance().project(sprite, event->getPosition());
    }
}
