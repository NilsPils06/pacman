#ifndef VIEW_WALL_H
#define VIEW_WALL_H
#include "EntityView.h"

namespace view {
class Wall final : public EntityView {
public:
    explicit Wall(const std::shared_ptr<subjects::Subject>& subject);

    void update(std::shared_ptr<Event> e) override;
};
} // namespace view

#endif // VIEW_WALL_H
