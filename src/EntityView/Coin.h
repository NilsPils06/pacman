#ifndef VIEW_COIN_H
#define VIEW_COIN_H
#include "EntityView.h"
namespace view {
class Coin final : public EntityView {
public:
    explicit Coin(const std::shared_ptr<subjects::Subject>& subject) : EntityView(subject) {}
};
} // namespace view

#endif // VIEW_COIN_H
