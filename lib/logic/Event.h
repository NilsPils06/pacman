#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H
#include "Util.h"

#include <memory>

enum EventType { POSITION_UPDATE, DIRECTION_UPDATE, COLLECT, TICK, DIE, EATEN };

class Event {
public:
    virtual ~Event() = default;

    [[nodiscard]] virtual EventType getType() const = 0;
};

class TickEvent final : public Event {
    Coords pos;
    Direction facing;
    bool variable; // used for fear in Ghosts and blocked in Pacman

public:
    TickEvent(const Coords& pos, const Direction& facing, bool b) : pos(pos), facing(facing), variable(b) {}
    [[nodiscard]] Coords getPosition() const { return pos; }
    [[nodiscard]] Direction getFacing() const { return facing; }
    [[nodiscard]] EventType getType() const override { return TICK; }
    [[nodiscard]] bool getVariable() const { return variable; }
};

class EatenEvent final : public Event {
    Coords pos;
    Direction facing;

public:
    EatenEvent(const Coords& pos, const Direction& facing) : pos(pos), facing(facing) {}
    [[nodiscard]] Coords getPosition() const { return pos; }
    [[nodiscard]] Direction getFacing() const { return facing; }
    [[nodiscard]] EventType getType() const override { return EATEN; }
};

class PositonUpdateEvent final : public Event {
    Coords position;

public:
    explicit PositonUpdateEvent(const Coords& position) : position(position) {}

    [[nodiscard]] Coords getPosition() const { return position; }

    [[nodiscard]] EventType getType() const override { return POSITION_UPDATE; }
};

class DirectionChangeEvent final : public Event {
    Direction direction;

public:
    explicit DirectionChangeEvent(const Direction& direction) : direction(direction) {}

    [[nodiscard]] Direction getDirection() const { return direction; }
    [[nodiscard]] EventType getType() const override { return DIRECTION_UPDATE; }
};

class CollectEvent final : public Event {
    int multiplier;

public:
    explicit CollectEvent(const int multiplier) : multiplier(multiplier) {}

    [[nodiscard]] EventType getType() const override { return COLLECT; }
    [[nodiscard]] int getMultiplier() const { return multiplier; }
};

class DieEvent final : public Event {
    Coords position;
    float timeElapsed;
    float duration;

public:
    DieEvent(const Coords& position, const float time_elapsed, const float duration)
        : position(position), timeElapsed(time_elapsed), duration(duration) {}
    [[nodiscard]] EventType getType() const override { return DIE; }
    [[nodiscard]] Coords getPosition() const { return position; }
    [[nodiscard]] float getTimeElapsed() const { return timeElapsed; }
    [[nodiscard]] float getDuration() const { return duration; }
};

#endif // PACMAN_EVENT_H
