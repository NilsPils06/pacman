#ifndef PACMAN_ENTITYUTIL_H
#define PACMAN_ENTITYUTIL_H

struct EntityCoords {
    float x;
    float y;

    EntityCoords(const float x, const float y) : x(x), y(y) {};
};

enum Movement { FIXED, CHASING, CUTTING };

enum Direction { UP, DOWN, LEFT, RIGHT };

#endif // PACMAN_ENTITYUTIL_H
