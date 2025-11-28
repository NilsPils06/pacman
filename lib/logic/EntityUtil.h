#ifndef PACMAN_ENTITYUTIL_H
#define PACMAN_ENTITYUTIL_H

struct EntityCoords {
    float x;
    float y;

    float width;
    float height;

    EntityCoords(const float x, const float y, const float width, const float height)
        : x(x), y(y), width(width), height(height) {};
};

enum Movement { FIXED, CHASING, CUTTING };

enum Direction { UP, DOWN, LEFT, RIGHT };

#endif // PACMAN_ENTITYUTIL_H
