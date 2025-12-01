#include "Event.h"
EntityCoords PositonUpdateEvent::getPosition() const { return position; }

EventType PositonUpdateEvent::getType() const {
    return POSITION_UPDATE;
}
Direction DirectionChangeEvent::getDirection() const {
    return direction;
}
EventType DirectionChangeEvent::getType() const {
    return DIRECTION_UPDATE;
}