#ifndef PACMAN_WALL_H
#define PACMAN_WALL_H
#include "../Collision.h"
#include "../Event.h"
#include "EntityModel.h"

namespace subjects {
class Wall final : public EntityModel {
public:
    /**
     * @brief Constructs a Wall model object.
     * @param coords the location of the object.
     */
    explicit Wall(const Coords& coords) : EntityModel(coords) {}

    /**
     * @brief Notifies the View observer of our coordinates via RenderStaticEvent
     * @note Function is called every tick.
     */
    void tick() override { notify(std::make_shared<RenderStaticEvent>(getCoords())); }
};
} // namespace subjects

#endif // PACMAN_WALL_H
