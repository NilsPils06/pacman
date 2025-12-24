#ifndef VIEW_PACMAN_H
#define VIEW_PACMAN_H
#include "AnimatedView.h"
#include "EntityView.h"

namespace view {
class Pacman final : public AnimatedView {
public:
    explicit Pacman(const std::shared_ptr<subjects::Subject>& subject);
    void update(std::shared_ptr<Event> e) override;
};
} // namespace view

#endif // VIEW_PACMAN_H
