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
    /**
     * @brief Constructs an EntityModel object at (0,0)
     */
    EntityModel() : coords(0, 0, 0, 0) {};

    /**
     * @brief Constructs an EntityModel object at the specified coordinates.
     * @param coords
     */
    explicit EntityModel(const Coords& coords) : coords(coords) {}

    /**
     * @brief Updates the current coordinates.
     * @param c the new coordinates.
     */
    void setCoords(const Coords c) { coords = c; }

    /**
     *
     * @return current coordinates.
     */
    [[nodiscard]] Coords getCoords() const { return coords; }

    /**
     * @brief Do tick behaviour.
     */
    virtual void tick() = 0;

    /**
     * @brief Notify all observers of the Event.
     * @param e an Event.
     */
    void notify(const std::shared_ptr<Event>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }

    /**
     *
     * @return if the object needs to be deleted.
     */
    [[nodiscard]] bool isExpired() const { return expired; }

    /**
     * @brief Mark the object as expired.
     * @note An expired object is deleted.
     */
    void setExpired() { expired = true; }

    /**
     * @brief Notify all observers of the Event.
     * @param e a TickEvent.
     */
    void notify(const std::shared_ptr<TickEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }

    /**
     * @brief Notify all observers of the Event.
     * @param e an EatenEvent.
     */
    void notify(const std::shared_ptr<EatenEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }

    /**
     * @brief Notify all observers of the Event.
     * @param e a RenderStaticEvent.
     */
    void notify(const std::shared_ptr<RenderStaticEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }

    /**
     * @brief Notify all observers of the Event.
     * @param e a DirectionChangeEvent.
     */
    void notify(const std::shared_ptr<DirectionChangeEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }

    /**
     * @brief Notify all observers of the Event.
     * @param e a CollectEvent.
     */
    void notify(const std::shared_ptr<CollectEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }

    /**
     * @brief Notify all observers of the Event.
     * @param e a DieEvent.
     */
    void notify(const std::shared_ptr<DieEvent>& e) override {
        for (const auto& observer : observers)
            observer->update(e);
    }
};
} // namespace subjects

#endif // PACMAN_ENTITYMODEL_H
