#include "Pacman.h"

#include "../Camera.h"
#include "Event.h"
#include "Stopwatch.h"
void view::Pacman::update(std::shared_ptr<Event> e) {
    if (e->getType() == DIE) {
        const auto event = std::static_pointer_cast<DieEvent>(e);

        static const std::vector deathAnim = {
            sprites::PACMAN_DEATH_1,
            sprites::PACMAN_DEATH_2,
            sprites::PACMAN_DEATH_3,
            sprites::PACMAN_DEATH_4,
            sprites::PACMAN_DEATH_5,
            sprites::PACMAN_DEATH_6,
            sprites::PACMAN_DEATH_7,
            sprites::PACMAN_DEATH_8,
            sprites::PACMAN_DEATH_9,
            sprites::PACMAN_DEATH_10,
            sprites::PACMAN_DEATH_11,
            sprites::PACMAN_DEATH_12,
        };

        const float timePerFrame = event->getDuration() / static_cast<float>(deathAnim.size());

        int frameIndex = static_cast<int>(event->getTimeElapsed() / timePerFrame);

        if (frameIndex >= deathAnim.size()) {
            frameIndex = static_cast<int>(deathAnim.size()) - 1;
        }

        setSprite(deathAnim[frameIndex]);
        Camera::project(sprite, event->getPosition());
        return;
    }
    if (e->getType() == TICK) {
        const std::shared_ptr<TickEvent> event = std::static_pointer_cast<TickEvent>(e);

        animTimer += Stopwatch::getInstance().getDeltaTime();
        static const std::vector frameSequence = {0, 1, 2, 1};

        if (animTimer >= FRAME_DUR) {
            animTimer -= FRAME_DUR;
            currentFrame = (currentFrame + 1) % frameSequence.size();
        }
        const int spriteIndex = frameSequence[currentFrame];

        static const std::vector animUp = {sprites::PACMAN_UP_1, sprites::PACMAN_UP_2, sprites::PACMAN_UP_3};
        static const std::vector animDown = {sprites::PACMAN_DOWN_1, sprites::PACMAN_DOWN_2, sprites::PACMAN_DOWN_3};
        static const std::vector animLeft = {sprites::PACMAN_LEFT_1, sprites::PACMAN_LEFT_2, sprites::PACMAN_LEFT_3};
        static const std::vector animRight = {sprites::PACMAN_RIGHT_1, sprites::PACMAN_RIGHT_2,
                                              sprites::PACMAN_RIGHT_3};

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