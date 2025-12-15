#include "EntityView.h"
#include "../Camera.h"
#include "../Game.h"
#include "Event.h"

void view::EntityView::setSprite(const sf::IntRect& spriteRect) {
    if (sprite.getTexture() == nullptr) {
        sprite.setTexture(Game::texture);
    }

    sprite.setTextureRect(spriteRect);
}

const sf::Sprite& view::EntityView::getSprite() const { return sprite; }

void view::EntityView::update(std::shared_ptr<Event> e) {
    if (e->getType() == POSITION_UPDATE) {
        const std::shared_ptr<PositonUpdateEvent> event = std::static_pointer_cast<PositonUpdateEvent>(e);

        Camera::project(sprite, event->getPosition());
    }
}
