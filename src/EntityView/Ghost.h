#ifndef VIEW_GHOST_H
#define VIEW_GHOST_H
#include "AnimatedView.h"

namespace view {
class Ghost final : public AnimatedView {
public:
    /**
     * @brief Constructs a Ghost View object.
     * @param subject the model to observe.
     * @param color
     */
    explicit Ghost(const std::shared_ptr<subjects::Subject>& subject, Color color);

    /**
     * @brief Handles an EatenEvent and updates the sprite.
     * @param e the EatenEvent to handle.
     */
    void update(const std::shared_ptr<EatenEvent>& e) override;

    /**
     * @brief Handles a TickEvent and plays the correct animation.
     * @param e the TickEvent to handle.
     */
    void update(const std::shared_ptr<TickEvent>& e) override;
};
} // namespace view

#endif // VIEW_GHOST_H
