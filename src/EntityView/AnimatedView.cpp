#include "AnimatedView.h"

#include "../Camera.h"
#include "Stopwatch.h"
void AnimatedView::update(const std::shared_ptr<TickEvent>& e) {
    animTimer += Stopwatch::getInstance().getDeltaTime();

    if (animTimer >= FRAME_DUR) {
        animTimer -= FRAME_DUR;
        currentFrame = (currentFrame + 1) % frameSequence.size();
    }

    setAnimSprite(e->getFacing());
    Camera::project(sprite, e->getPosition());
}
void AnimatedView::setAnimSprite(const Direction facing) {
    const int spriteIndex = getSpriteIndex();
    switch (facing) {
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
}
int AnimatedView::getSpriteIndex() const { return frameSequence[currentFrame]; }