#include "Ghost.h"

#include "../Camera.h"
#include "Event.h"
#include "Stopwatch.h"
view::Ghost::Ghost(const std::shared_ptr<subjects::Subject>& subject, const Color color) : AnimatedView(subject) {
    switch (color) {
    case RED:
        animUp = {sprites::GHOST_RED_UP_1, sprites::GHOST_RED_UP_2};
        animDown = {sprites::GHOST_RED_DOWN_1, sprites::GHOST_RED_DOWN_2};
        animLeft = {sprites::GHOST_RED_LEFT_1, sprites::GHOST_RED_LEFT_2};
        animRight = {sprites::GHOST_RED_RIGHT_1, sprites::GHOST_RED_RIGHT_2};
        break;
    case PINK:
        animUp = {sprites::GHOST_PINK_UP_1, sprites::GHOST_PINK_UP_2};
        animDown = {sprites::GHOST_PINK_DOWN_1, sprites::GHOST_PINK_DOWN_2};
        animLeft = {sprites::GHOST_PINK_LEFT_1, sprites::GHOST_PINK_LEFT_2};
        animRight = {sprites::GHOST_PINK_RIGHT_1, sprites::GHOST_PINK_RIGHT_2};
        break;
    case BLUE:
        animUp = {sprites::GHOST_BLUE_UP_1, sprites::GHOST_BLUE_UP_2};
        animDown = {sprites::GHOST_BLUE_DOWN_1, sprites::GHOST_BLUE_DOWN_2};
        animLeft = {sprites::GHOST_BLUE_LEFT_1, sprites::GHOST_BLUE_LEFT_2};
        animRight = {sprites::GHOST_BLUE_RIGHT_1, sprites::GHOST_BLUE_RIGHT_2};
        break;
    case ORANGE:
        animUp = {sprites::GHOST_ORANGE_UP_1, sprites::GHOST_ORANGE_UP_2};
        animDown = {sprites::GHOST_ORANGE_DOWN_1, sprites::GHOST_ORANGE_DOWN_2};
        animLeft = {sprites::GHOST_ORANGE_LEFT_1, sprites::GHOST_ORANGE_LEFT_2};
        animRight = {sprites::GHOST_ORANGE_RIGHT_1, sprites::GHOST_ORANGE_RIGHT_2};
        break;
    }
}
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