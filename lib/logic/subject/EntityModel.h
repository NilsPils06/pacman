#ifndef PACMAN_ENTITYMODEL_H
#define PACMAN_ENTITYMODEL_H
#include "Subject.h"

struct EntityCoords {
    int x;
    int y;

    EntityCoords(const int x, const int y) : x(x), y(y) {};
};

class EntityModel : public Subject {
    EntityCoords coords;

public:
    EntityModel() : coords(0, 0) {};
};

#endif // PACMAN_ENTITYMODEL_H
