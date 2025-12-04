#include "Pacman.h"

#include "../Camera.h"
#include "Event.h"
void view::Pacman::update(std::shared_ptr<Event> e) {
    if (e->getType() == POSITION_UPDATE) {
        std::shared_ptr<PositonUpdateEvent> event = std::static_pointer_cast<PositonUpdateEvent>(e);

        Camera::project(sprite, event->getPosition());
    }
    if (e->getType() == DIRECTION_UPDATE) {
        std::shared_ptr<DirectionChangeEvent> event = std::static_pointer_cast<DirectionChangeEvent>(e);
        switch (event->getDirection()) {
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
    }
}