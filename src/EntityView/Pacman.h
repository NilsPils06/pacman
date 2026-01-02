#ifndef VIEW_PACMAN_H
#define VIEW_PACMAN_H
#include "AnimatedView.h"
#include "EntityView.h"

namespace view {
class Pacman final : public AnimatedView {
public:
    /**
     * @brief Constructs a Pacman View object.
     * @param subject the model to be observed.
     */
    explicit Pacman(const std::shared_ptr<subjects::Subject>& subject);

    /**
     * @brief Handles a DieEvent and plays the death animation.
     * @param e the DieEvent to handle.
     */
    void update(const std::shared_ptr<DieEvent>& e) override;

    /**
     * @brief Handles a TickEvent and plays the correct animation.
     * @param e the TickEvent to handle.
     */
    void update(const std::shared_ptr<TickEvent>& e) override;
};
} // namespace view

#endif // VIEW_PACMAN_H
