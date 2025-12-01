#include "Pacman.h"

#include "../Event.h"
#include "../Stopwatch.h"
void subjects::Pacman::notify(std::shared_ptr<Event> e) {
    if (e->getType() == DIRECTION_UPDATE) {
        const std::shared_ptr<DirectionChangeEvent> event = std::static_pointer_cast<DirectionChangeEvent>(e);
        facing = event->getDirection();
    }
    EntityModel::notify(e);
}
void subjects::Pacman::tick() {
    constexpr float speed = 0.1f;
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