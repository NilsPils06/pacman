#include "Ghost.h"

#include "../Camera.h"
#include "Event.h"
#include "Stopwatch.h"
void view::Ghost::update(std::shared_ptr<Event> e) {
    if (e->getType() == TICK) {
        const std::shared_ptr<TickEvent> event = std::static_pointer_cast<TickEvent>(e);

        animTimer += Stopwatch::getInstance().getDeltaTime();
        static const std::vector frameSequence = {0, 1};

        if (animTimer >= FRAME_DUR) {
            animTimer -= FRAME_DUR;
            currentFrame = (currentFrame + 1) % frameSequence.size();
        }
        const int spriteIndex = frameSequence[currentFrame];

        static const std::vector animUp = {sprites::GHOST_RED_UP_1, sprites::GHOST_RED_UP_2};
        static const std::vector animDown = {sprites::GHOST_RED_DOWN_1, sprites::GHOST_RED_DOWN_2};
        static const std::vector animLeft = {sprites::GHOST_RED_LEFT_1, sprites::GHOST_RED_LEFT_2};
        static const std::vector animRight = {sprites::GHOST_RED_RIGHT_1, sprites::GHOST_RED_RIGHT_2};

        switch (event->getFacing()) {
        case UP:
            setSprite(animUp[spriteIndex]);
            break;
        case DOWN:
            setSprite(animDown[spriteIndex]);
            break;
        case LEFT:
            setSprite(animLeft[spriteIndex]);
            break;
        case RIGHT:
            setSprite(animRight[spriteIndex]);
            break;
        }

        Camera::project(sprite, event->getPosition());
    }
}