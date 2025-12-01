#ifndef PACMAN_ENTITYMODEL_H
#define PACMAN_ENTITYMODEL_H
#include "../Util.h"
#include "Subject.h"

namespace subjects {
class Pacman;
class Wall;

class EntityModel : public Subject {
protected:
    Coords coords;

public:
    EntityModel() : coords(0, 0, 0, 0) {};

    explicit EntityModel(const Coords& coords);

    void setCoords(Coords coords);

    [[nodiscard]] Coords getCoords() const;

    virtual void tick() = 0;

    void notify(std::shared_ptr<Event> e) override;
};
} // namespace subjects

#endif // PACMAN_ENTITYMODEL_H
