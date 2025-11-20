#ifndef PACMAN_ENTITYMODEL_H
#define PACMAN_ENTITYMODEL_H
#include "../EntityUtil.h"
#include "Subject.h"

namespace subjects {
class EntityModel : public Subject {
protected:
    EntityCoords coords;

public:
    EntityModel() : coords(0, 0) {};

    explicit EntityModel(const EntityCoords& coords);

    EntityModel(float x, float y) : coords(x,y) {};

    void setCoords(float x, float y);

    void setCoords(EntityCoords coords);

    void notify() override;
};
} // namespace subjects

#endif // PACMAN_ENTITYMODEL_H
