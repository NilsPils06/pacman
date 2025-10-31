#ifndef PACMAN_ENTITYUTIL_H
#define PACMAN_ENTITYUTIL_H

struct EntityCoords {
    int x;
    int y;

    EntityCoords(const int x, const int y) : x(x), y(y) {};
};

enum Movement { FIXED, CHASING, CUTTING };

enum Direction { UP, DOWN, LEFT, RIGHT };

#endif // PACMAN_ENTITYUTIL_H
