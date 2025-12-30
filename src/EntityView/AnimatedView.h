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
    explicit AnimatedView(const std::shared_ptr<subjects::Subject>& subject) : EntityView(subject) {}
    void update(const std::shared_ptr<TickEvent>& e) override;
    void setAnimSprite(Direction facing);
    [[nodiscard]] int getSpriteIndex() const;
};

#endif // PACMAN_ANIMATEDVIEW_H
