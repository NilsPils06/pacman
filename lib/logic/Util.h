#ifndef PACMAN_ENTITYUTIL_H
#define PACMAN_ENTITYUTIL_H

struct Coords {
    float x;
    float y;

    // normalized width and height for calculation of cellsize for the camera
    // TODO try to remove this
    float width;
    float height;

    Coords(const float x, const float y, const float width, const float height)
        : x(x), y(y), width(width), height(height) {}
};

struct Hitbox {
    float width;
    float height;

    Hitbox(const float& w, const float& h) : width(w), height(h) {}
};

enum Movement { FIXED, CHASING, CUTTING };

enum Direction { UP, DOWN, LEFT, RIGHT };

#endif // PACMAN_ENTITYUTIL_H
