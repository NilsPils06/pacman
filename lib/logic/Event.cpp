#include "Event.h"
Coords PositonUpdateEvent::getPosition() const { return position; }

EventType PositonUpdateEvent::getType() const { return POSITION_UPDATE; }
Direction DirectionChangeEvent::getDirection() const { return direction; }
EventType DirectionChangeEvent::getType() const { return DIRECTION_UPDATE; }
EventType CollectEvent::getType() const { return COLLECT; }
std::shared_ptr<subjects::Collectable> CollectEvent::getCollectable() const { return collectable; }