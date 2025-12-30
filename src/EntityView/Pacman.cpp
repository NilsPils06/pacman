#include "Pacman.h"

#include "../Camera.h"
#include "Event.h"
#include "Stopwatch.h"
view::Pacman::Pacman(const std::shared_ptr<subjects::Subject>& subject) : AnimatedView(subject) {
    animUp = {sprites::PACMAN_UP_1, sprites::PACMAN_UP_2, sprites::PACMAN_UP_3};
    animDown = {sprites::PACMAN_DOWN_1, sprites::PACMAN_DOWN_2, sprites::PACMAN_DOWN_3};
    animLeft = {sprites::PACMAN_LEFT_1, sprites::PACMAN_LEFT_2, sprites::PACMAN_LEFT_3};
    animRight = {sprites::PACMAN_RIGHT_1, sprites::PACMAN_RIGHT_2, sprites::PACMAN_RIGHT_3};
    frameSequence = {0, 1, 2, 1};
}
void view::Pacman::update(const std::shared_ptr<DieEvent>& e) {
    static const std::vector deathAnim = {
        sprites::PACMAN_DEATH_1, sprites::PACMAN_DEATH_2,  sprites::PACMAN_DEATH_3,  sprites::PACMAN_DEATH_4,
        sprites::PACMAN_DEATH_5, sprites::PACMAN_DEATH_6,  sprites::PACMAN_DEATH_7,  sprites::PACMAN_DEATH_8,
        sprites::PACMAN_DEATH_9, sprites::PACMAN_DEATH_10, sprites::PACMAN_DEATH_11, sprites::PACMAN_DEATH_12,
    };

    const float timePerFrame = e->getDuration() / static_cast<float>(deathAnim.size());

    auto frameIndex = static_cast<size_t>(e->getTimeElapsed() / timePerFrame);

    if (frameIndex >= deathAnim.size()) {
        frameIndex = static_cast<int>(deathAnim.size()) - 1;
    }

    setSprite(deathAnim[frameIndex]);
    Camera::project(sprite, e->getPosition());
}
void view::Pacman::update(const std::shared_ptr<TickEvent>& e) {
    if (e->getVariable()) { // blocked?
        animTimer = 0;
        currentFrame = 0;

        setAnimSprite(e->getFacing());

        Camera::project(sprite, e->getPosition());
    } else {
        AnimatedView::update(e);
    }
}