#include "Event.h"
Coords TickEvent::getPosition() const { return pos; }
Direction TickEvent::getFacing() const { return facing; }
EventType TickEvent::getType() const { return TICK; }
Coords PositonUpdateEvent::getPosition() const { return position; }

EventType PositonUpdateEvent::getType() const { return POSITION_UPDATE; }
Direction DirectionChangeEvent::getDirection() const { return direction; }
EventType DirectionChangeEvent::getType() const { return DIRECTION_UPDATE; }
EventType CollectEvent::getType() const { return COLLECT; }
std::shared_ptr<subjects::Collectable> CollectEvent::getCollectable() const { return collectable; }
EventType DieEvent::getType() const {return DIE;}
Coords DieEvent::getPosition() const { return position; }
float DieEvent::getTimeElapsed() const { return timeElapsed; }
float DieEvent::getDuration() const {return duration;}