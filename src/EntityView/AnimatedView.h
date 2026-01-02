#ifndef PACMAN_ANIMATEDVIEW_H
#define PACMAN_ANIMATEDVIEW_H
#include "EntityView.h"

#include <vector>

class AnimatedView : public view::EntityView {
protected:
    std::vector<sf::IntRect> animUp;
    std::vector<sf::IntRect> animDown;
    std::vector<sf::IntRect> animLeft;
    std::vector<sf::IntRect> animRight;
    float animTimer = 0.0f;
    size_t currentFrame = 0;
    const float FRAME_DUR = 0.25f;
    std::vector<int> frameSequence;

public:
    /**
     * @brief Constructs an AnimatedView object.
     * @param subject the model to observe.
     */
    explicit AnimatedView(const std::shared_ptr<subjects::Subject>& subject) : EntityView(subject) {}

    /**
     * @brief Updates the sprite to the correct animation frame of the correct animation.
     * @param e the TickEvent to handle.
     */
    void update(const std::shared_ptr<TickEvent>& e) override;

    /**
     * @brief Sets the sprite based on direction.
     * @param facing the direction the model is facing.
     */
    void setAnimSprite(Direction facing);

    /**
     *
     * @return the index of the current animation frame.
     */
    [[nodiscard]] int getSpriteIndex() const;
};

#endif // PACMAN_ANIMATEDVIEW_H
