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

    frameSequence = {0, 1};
}
void view::Ghost::update(const std::shared_ptr<EatenEvent>& e) {
    switch (e->getFacing()) {
    case UP:
        setSprite(sprites::GHOST_EATEN_UP);
        break;
    case DOWN:
        setSprite(sprites::GHOST_EATEN_DOWN);
        break;
    case LEFT:
        setSprite(sprites::GHOST_EATEN_LEFT);
        break;
    case RIGHT:
        setSprite(sprites::GHOST_EATEN_RIGHT);
        break;
    }

    Camera::project(sprite, e->getPosition());
}
void view::Ghost::update(const std::shared_ptr<TickEvent>& e) {
    if (e->getVariable()) { // Fear mode?
        static const std::vector animFear = {sprites::GHOST_FEAR_1, sprites::GHOST_FEAR_2};
        animTimer += Stopwatch::getInstance().getDeltaTime();

        if (animTimer >= FRAME_DUR) {
            animTimer -= FRAME_DUR;
            currentFrame = (currentFrame + 1) % frameSequence.size();
        }
        setSprite(animFear[getSpriteIndex()]);
        Camera::project(sprite, e->getPosition());
    } else {
        AnimatedView::update(e);
    }
}