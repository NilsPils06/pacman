#ifndef VIEW_PACMAN_H
#define VIEW_PACMAN_H
#include "AnimatedView.h"
#include "EntityView.h"

namespace view {
class Pacman final : public AnimatedView {
public:
    explicit Pacman(const std::shared_ptr<subjects::Subject>& subject);
    void update(const std::shared_ptr<DieEvent>& e) override;
    void update(const std::shared_ptr<TickEvent>& e) override;
};
} // namespace view

#endif // VIEW_PACMAN_H
