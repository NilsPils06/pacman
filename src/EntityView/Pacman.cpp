#include "Pacman.h"

#include "../Camera.h"
#include "Event.h"
void view::Pacman::update(std::shared_ptr<Event> e) {
    if (e->getType() == TICK) {
        const std::shared_ptr<TickEvent> event = std::static_pointer_cast<TickEvent>(e);
        switch (event->getFacing()) {
        case UP:
            setSprite(sprites::PACMAN_UP_2);
            break;
        case DOWN:
            setSprite(sprites::PACMAN_DOWN_2);
            break;
        case LEFT:
            setSprite(sprites::PACMAN_LEFT_2);
            break;
        case RIGHT:
            setSprite(sprites::PACMAN_RIGHT_2);
            break;
        }
        Camera::project(sprite, event->getPosition());
    }
}