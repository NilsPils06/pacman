#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H
#include "Util.h"
#include "subject/Collectable.h"

#include <memory>

// TODO maybe update this so that it's the command pattern????

enum EventType { POSITION_UPDATE, DIRECTION_UPDATE, COLLECT, TICK };

class Event {
public:
    virtual ~Event() = default;

    [[nodiscard]] virtual EventType getType() const = 0;
};

class TickEvent final : public Event {
    Coords pos;
    Direction facing;

public:
    TickEvent(const Coords& pos, const Direction& facing) : pos(pos), facing(facing) {}
    [[nodiscard]] Coords getPosition() const;
    [[nodiscard]] Direction getFacing() const;
    [[nodiscard]] EventType getType() const override;
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

class CollectEvent final : public Event {
    std::shared_ptr<subjects::Collectable> collectable;

public:
    explicit CollectEvent(const std::shared_ptr<subjects::Collectable>& collectable) : collectable(collectable) {}

    [[nodiscard]] EventType getType() const override;
    [[nodiscard]] std::shared_ptr<subjects::Collectable> getCollectable() const;
};

#endif // PACMAN_EVENT_H
