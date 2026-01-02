#ifndef PACMAN_EVENT_H
#define PACMAN_EVENT_H
#include "Util.h"

class Event {
public:
    /**
     * @brief Destructs the event.
     */
    virtual ~Event() = default;
};

class TickEvent final : public Event {
    Coords pos;
    Direction facing;
    bool variable; // used for fear in Ghosts and blocked in Pacman

public:
    /**
     * @brief Constructs TickEvent object.
     * @param pos
     * @param facing
     * @param b
     */
    TickEvent(const Coords& pos, const Direction& facing, const bool b) : pos(pos), facing(facing), variable(b) {}

    /**
     *
     * @return the position of the event's entity.
     */
    [[nodiscard]] Coords getPosition() const { return pos; }

    /**
     *
     * @return the direction the event's entity is facing.
     */
    [[nodiscard]] Direction getFacing() const { return facing; }

    /**
     *
     * @return if ghost is in fear or if pacman is not moving.
     */
    [[nodiscard]] bool getVariable() const { return variable; }
};

class EatenEvent final : public Event {
    Coords pos;
    Direction facing;

public:
    /**
     * @brief Construct an EatenEvent object.
     * @param pos
     * @param facing
     */
    EatenEvent(const Coords& pos, const Direction& facing) : pos(pos), facing(facing) {}

    /**
     *
     * @return the position of the eaten ghost.
     */
    [[nodiscard]] Coords getPosition() const { return pos; }

    /**
     *
     * @return the direction the eaten ghost is facing.
     */
    [[nodiscard]] Direction getFacing() const { return facing; }
};

class RenderStaticEvent final : public Event {
    Coords position;

public:
    /**
     * @brief Constructs a RenderStaticEvent object.
     * @param position
     */
    explicit RenderStaticEvent(const Coords& position) : position(position) {}

    /**
     *
     * @return the position of the entity which needs static rendering.
     */
    [[nodiscard]] Coords getPosition() const { return position; }
};

class DirectionChangeEvent final : public Event {
    Direction direction;

public:
    /**
     * @brief Constructs a DirectionChangeEvent object.
     * @param direction the new direction.
     */
    explicit DirectionChangeEvent(const Direction& direction) : direction(direction) {}

    /**
     *
     * @return the new direction.
     */
    [[nodiscard]] Direction getDirection() const { return direction; }
};

class CollectEvent final : public Event {
    int points;

public:
    /**
     * @brief Constructs a CollectEvent object.
     * @param points
     */
    explicit CollectEvent(const int points) : points(points) {}

    /**
     *
     * @return the amount of points gained from collection.
     */
    [[nodiscard]] int getPoints() const { return points; }
};

class DieEvent final : public Event {
    Coords position;
    float timeElapsed;
    float duration;

public:
    /**
     * @brief Construct a DieEvent object.
     * @param position
     * @param time_elapsed
     * @param duration
     */
    DieEvent(const Coords& position, const float time_elapsed, const float duration)
        : position(position), timeElapsed(time_elapsed), duration(duration) {}

    /**
     *
     * @return the position where Pacman died.
     */
    [[nodiscard]] Coords getPosition() const { return position; }

    /**
     *
     * @return how much time has elapsed since death.
     */
    [[nodiscard]] float getTimeElapsed() const { return timeElapsed; }

    /**
     *
     * @return the duration of the death animation.
     */
    [[nodiscard]] float getDuration() const { return duration; }
};

#endif // PACMAN_EVENT_H
