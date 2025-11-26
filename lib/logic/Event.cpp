#include "Event.h"
EntityCoords PositonUpdateEvent::getPosition() const { return position; }

EventType PositonUpdateEvent::getType() const {
    return POSITION_UPDATE;
}