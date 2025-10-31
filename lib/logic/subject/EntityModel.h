#ifndef PACMAN_ENTITYMODEL_H
#define PACMAN_ENTITYMODEL_H
#include "../EntityUtil.h"
#include "Subject.h"

namespace subjects {
class EntityModel : public Subject {
    EntityCoords coords;

public:
    EntityModel() : coords(0, 0) {};
};
} // namespace subjects

#endif // PACMAN_ENTITYMODEL_H
