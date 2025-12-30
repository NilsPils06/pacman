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
void view::EntityView::update(const std::shared_ptr<RenderStaticEvent>& e) { Camera::project(sprite, e->getPosition()); }
