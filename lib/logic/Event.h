#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H
#include "Util.h"
#include "subject/Collectable.h"

#include <memory>

enum EventType { POSITION_UPDATE, DIRECTION_UPDATE, COLLECT, TICK, DIE };

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

class DieEvent final : public Event {
    Coords position;
    float timeElapsed;
    float duration;

public:
    DieEvent(const Coords& position, const float time_elapsed, const float duration) : position(position), timeElapsed(time_elapsed), duration(duration) {}
    [[nodiscard]] EventType getType() const override;
    [[nodiscard]] Coords getPosition() const;
    [[nodiscard]] float getTimeElapsed() const;
    [[nodiscard]] float getDuration() const;
};

#endif // PACMAN_EVENT_H
