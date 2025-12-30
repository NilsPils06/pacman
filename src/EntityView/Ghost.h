#ifndef VIEW_GHOST_H
#define VIEW_GHOST_H
#include "AnimatedView.h"

namespace view {
class Ghost final : public AnimatedView {
public:
    explicit Ghost(const std::shared_ptr<subjects::Subject>& subject, Color color);
    void update(const std::shared_ptr<EatenEvent>& e) override;
    void update(const std::shared_ptr<TickEvent>& e) override;
};
} // namespace view

#endif // VIEW_GHOST_H
