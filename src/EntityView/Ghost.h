#ifndef VIEW_GHOST_H
#define VIEW_GHOST_H
#include "EntityView.h"

namespace view {
class Ghost final : public EntityView {
public:
    explicit Ghost(const std::shared_ptr<subjects::Subject>& subject) : EntityView(subject) {}
};
} // namespace view

#endif // VIEW_GHOST_H
