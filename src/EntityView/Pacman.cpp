#include "Pacman.h"

#include "../Camera.h"
#include "Event.h"
#include "Stopwatch.h"
view::Pacman::Pacman(const std::shared_ptr<subjects::Subject>& subject) : AnimatedView(subject) {
    animUp = {sprites::PACMAN_UP_1, sprites::PACMAN_UP_2, sprites::PACMAN_UP_3};
    animDown = {sprites::PACMAN_DOWN_1, sprites::PACMAN_DOWN_2, sprites::PACMAN_DOWN_3};
    animLeft = {sprites::PACMAN_LEFT_1, sprites::PACMAN_LEFT_2, sprites::PACMAN_LEFT_3};
    animRight = {sprites::PACMAN_RIGHT_1, sprites::PACMAN_RIGHT_2, sprites::PACMAN_RIGHT_3};
}
void view::Pacman::update(const std::shared_ptr<Event> e) {
    if (e->getType() == DIE) {
        const auto event = std::static_pointer_cast<DieEvent>(e);

        static const std::vector deathAnim = {
            sprites::PACMAN_DEATH_1, sprites::PACMAN_DEATH_2,  sprites::PACMAN_DEATH_3,  sprites::PACMAN_DEATH_4,
            sprites::PACMAN_DEATH_5, sprites::PACMAN_DEATH_6,  sprites::PACMAN_DEATH_7,  sprites::PACMAN_DEATH_8,
            sprites::PACMAN_DEATH_9, sprites::PACMAN_DEATH_10, sprites::PACMAN_DEATH_11, sprites::PACMAN_DEATH_12,
        };

        const float timePerFrame = event->getDuration() / static_cast<float>(deathAnim.size());

        auto frameIndex = static_cast<size_t>(event->getTimeElapsed() / timePerFrame);

        if (frameIndex >= deathAnim.size()) {
            frameIndex = static_cast<int>(deathAnim.size()) - 1;
        }

        setSprite(deathAnim[frameIndex]);
        Camera::project(sprite, event->getPosition());
        return;
    }
    if (e->getType() == TICK) {
        const std::shared_ptr<TickEvent> event = std::static_pointer_cast<TickEvent>(e);
        int spriteIndex = 0;

        if (event->getVariable()) { // Blocked?
            animTimer = 0;
            currentFrame = 0;
        } else {
            animTimer += Stopwatch::getInstance().getDeltaTime();
            static const std::vector frameSequence = {0, 1, 2, 1};

            if (animTimer >= FRAME_DUR) {
                animTimer -= FRAME_DUR;
                currentFrame = (currentFrame + 1) % frameSequence.size();
            }
            spriteIndex = frameSequence[currentFrame];
        }

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