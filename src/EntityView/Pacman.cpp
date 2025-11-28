#include "Pacman.h"

#include "../Camera.h"
#include "Event.h"
void view::Pacman::update(std::shared_ptr<Event> e) {
    if (e->getType() == POSITION_UPDATE) {
        std::shared_ptr<PositonUpdateEvent> event = std::static_pointer_cast<PositonUpdateEvent>(e);

        Camera::project(sprite, event->getPosition());
    }
}