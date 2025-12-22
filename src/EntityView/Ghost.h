#ifndef VIEW_GHOST_H
#define VIEW_GHOST_H
#include "EntityView.h"

namespace view {
class Ghost final : public EntityView {
    float animTimer = 0.0f;
    size_t currentFrame = 0;
    const float FRAME_DUR = 0.25f;

public:
    explicit Ghost(const std::shared_ptr<subjects::Subject>& subject) : EntityView(subject) {}
    void update(std::shared_ptr<Event> e) override;
};
} // namespace view

#endif // VIEW_GHOST_H
