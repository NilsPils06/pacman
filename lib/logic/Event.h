#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H
#include "Util.h"

// TODO maybe update this so that it's the command pattern????

enum EventType {
    POSITION_UPDATE,
    DIRECTION_UPDATE
};

class Event {
public:
    virtual ~Event() = default;

    [[nodiscard]] virtual EventType getType() const = 0;
};

class PositonUpdateEvent final : public Event {
    Coords position;

public:
    explicit PositonUpdateEvent(const Coords& position) : position(position) {}

    [[nodiscard]] Coords getPosition() const;

    [[nodiscard]] EventType getType() const override;
};

class DirectionChangeEvent final : public Event {
    Direction direction;

public:
    explicit DirectionChangeEvent(const Direction& direction) : direction(direction) {}

    [[nodiscard]] Direction getDirection() const;
    [[nodiscard]] EventType getType() const override;
};

#endif // PACMAN_EVENT_H
