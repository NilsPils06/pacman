#ifndef VIEW_GHOST_H
#define VIEW_GHOST_H
#include "AnimatedView.h"
#include "Util.h"

namespace view {
class Ghost final : public AnimatedView {
public:
    explicit Ghost(const std::shared_ptr<subjects::Subject>& subject, Color color);
    void update(std::shared_ptr<Event> e) override;
};
} // namespace view

#endif // VIEW_GHOST_H
