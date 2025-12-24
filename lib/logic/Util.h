#ifndef PACMAN_ENTITYUTIL_H
#define PACMAN_ENTITYUTIL_H
#include <algorithm>

struct Coords {
    float x;
    float y;

    // normalized width and height for calculation of cellsize for the camera
    // TODO try to remove this
    float width;
    float height;

    Coords(const float x, const float y, const float width, const float height)
        : x(x), y(y), width(width), height(height) {}

    [[nodiscard]] bool overlaps(const Coords& a) const {
        const float x1 = a.x - (a.width / 2);
        const float y1 = a.y - (a.height / 2);
        const float x2 = a.x + (a.width / 2);
        const float y2 = a.y + (a.height / 2);

        // Bottom left and top right of B
        const float x3 = x - (width / 2);
        const float y3 = y - (height / 2);
        const float x4 = x + (width / 2);
        const float y4 = y + (height / 2);

        // Intersection bounds
        const float x5 = std::max(x1, x3);
        const float y5 = std::max(y1, y3);
        const float x6 = std::min(x2, x4);
        const float y6 = std::min(y2, y4);

        const float overlapX = x6 - x5;
        const float overlapY = y6 - y5;

        if (overlapX < 0.002f || overlapY < 0.002f) {
            return false;
        }
        return true;
    }
    bool operator==(const Coords& other) const {
        return x == other.x && y == other.y;
    }
};

struct Hitbox {
    float width;
    float height;

    Hitbox(const float& w, const float& h) : width(w), height(h) {}
};

enum Movement { FIXED, CHASING, CUTTING };

enum Direction { UP, DOWN, LEFT, RIGHT };

enum Color { RED, PINK, BLUE, ORANGE };

#endif // PACMAN_ENTITYUTIL_H
