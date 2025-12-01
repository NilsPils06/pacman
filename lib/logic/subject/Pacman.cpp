#include "Pacman.h"

#include "../Event.h"
#include "../Stopwatch.h"
void subjects::Pacman::notify(std::shared_ptr<Event> e) {
    if (e->getType() == DIRECTION_UPDATE) {
        const std::shared_ptr<DirectionChangeEvent> event = std::static_pointer_cast<DirectionChangeEvent>(e);
        facing = event->getDirection();
        speed = 0.1f;
    }
    EntityModel::notify(e);
}
void subjects::Pacman::tick() {
    previousPosition = coords;
    const float deltaTime = Stopwatch::getInstance().getDeltaTime();
    switch (facing) {
        case RIGHT:
            coords.x += speed*deltaTime;
            break;
        case UP:
            coords.y -= speed*deltaTime;
            break;
        case DOWN:
            coords.y += speed*deltaTime;
            break;
        case LEFT:
            coords.x -= speed*deltaTime;
            break;
        default:
            break;
    }
}
void subjects::Pacman::visit(std::shared_ptr<const subjects::Wall> e) {
    speed = 0;
    coords = previousPosition;
}