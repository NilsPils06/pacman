#ifndef VIEW_FRUIT_H
#define VIEW_FRUIT_H
#include "EntityView.h"

// TODO add randomized fruit texture maybe?

namespace view {
class Fruit final : public EntityView {
public:
    explicit Fruit(const std::shared_ptr<subjects::Subject>& subject) : EntityView(subject) {}
};
}

#endif // VIEW_FRUIT_H
