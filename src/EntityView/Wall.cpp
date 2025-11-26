#include "Wall.h"

#include "../Camera.h"
#include "Event.h"
view::Wall::Wall(const std::shared_ptr<subjects::Subject>& subject)
    : EntityView(subject) {}
void view::Wall::update(std::shared_ptr<Event> e) {
    if (e->getType() == POSITION_UPDATE) {
        std::shared_ptr<PositonUpdateEvent> event = std::static_pointer_cast<PositonUpdateEvent>(e);

        Camera::getInstance().project(sprite, event->getPosition());
    }
}
