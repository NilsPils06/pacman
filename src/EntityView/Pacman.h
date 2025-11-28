#ifndef VIEW_PACMAN_H
#define VIEW_PACMAN_H
#include "EntityView.h"

namespace view {
class Pacman final : public EntityView {
public:
    explicit Pacman(const std::shared_ptr<subjects::Subject>& subject) : EntityView(subject) {}
    void update(std::shared_ptr<Event> e) override;
};
} // namespace view

#endif // VIEW_PACMAN_H
