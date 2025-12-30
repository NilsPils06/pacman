#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H
#include "Util.h"

class Event {
public:
    virtual ~Event() = default;
};

class TickEvent final : public Event {
    Coords pos;
    Direction facing;
    bool variable; // used for fear in Ghosts and blocked in Pacman

public:
    TickEvent(const Coords& pos, const Direction& facing, const bool b) : pos(pos), facing(facing), variable(b) {}
    [[nodiscard]] Coords getPosition() const { return pos; }
    [[nodiscard]] Direction getFacing() const { return facing; }
    [[nodiscard]] bool getVariable() const { return variable; }
};

class EatenEvent final : public Event {
    Coords pos;
    Direction facing;

public:
    EatenEvent(const Coords& pos, const Direction& facing) : pos(pos), facing(facing) {}
    [[nodiscard]] Coords getPosition() const { return pos; }
    [[nodiscard]] Direction getFacing() const { return facing; }
};

class RenderStaticEvent final : public Event {
    Coords position;

public:
    explicit RenderStaticEvent(const Coords& position) : position(position) {}

    [[nodiscard]] Coords getPosition() const { return position; }
};

class DirectionChangeEvent final : public Event {
    Direction direction;

public:
    explicit DirectionChangeEvent(const Direction& direction) : direction(direction) {}

    [[nodiscard]] Direction getDirection() const { return direction; }
};

class CollectEvent final : public Event {
    int points;

public:
    explicit CollectEvent(const int points) : points(points) {}
    [[nodiscard]] int getPoints() const { return points; }
};

class DieEvent final : public Event {
    Coords position;
    float timeElapsed;
    float duration;

public:
    DieEvent(const Coords& position, const float time_elapsed, const float duration)
        : position(position), timeElapsed(time_elapsed), duration(duration) {}
    [[nodiscard]] Coords getPosition() const { return position; }
    [[nodiscard]] float getTimeElapsed() const { return timeElapsed; }
    [[nodiscard]] float getDuration() const { return duration; }
};

#endif // PACMAN_EVENT_H
