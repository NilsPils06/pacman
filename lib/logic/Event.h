#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H
#include "EntityUtil.h"
enum EventType { POSITION_UPDATE };

class Event {
public:
    virtual ~Event() = default;

    [[nodiscard]] virtual EventType getType() const = 0;
};

class PositonUpdateEvent final : public Event {
    EntityCoords position;

public:
    explicit PositonUpdateEvent(const EntityCoords& position) : position(position) {}

    [[nodiscard]] EntityCoords getPosition() const;

    [[nodiscard]] EventType getType() const override;
};

#endif // PACMAN_EVENT_H
