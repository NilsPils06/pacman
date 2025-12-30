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
    bool expired = false;

public:
    EntityModel() : coords(0, 0, 0, 0) {};

    explicit EntityModel(const Coords& coords) : coords(coords) {}

    void setCoords(const Coords c) { coords = c; }

    [[nodiscard]] Coords getCoords() const { return coords; }

    virtual void tick() = 0;

    void notify(const std::shared_ptr<Event>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }

    [[nodiscard]] bool isExpired() const { return expired; }

    void setExpired() { expired = true; }
    void notify(const std::shared_ptr<TickEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }
    void notify(const std::shared_ptr<EatenEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }
    void notify(const std::shared_ptr<RenderStaticEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }
    void notify(const std::shared_ptr<DirectionChangeEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }
    void notify(const std::shared_ptr<CollectEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }
    void notify(const std::shared_ptr<DieEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }
};
} // namespace subjects

#endif // PACMAN_ENTITYMODEL_H
