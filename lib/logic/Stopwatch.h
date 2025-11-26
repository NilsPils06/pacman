#ifndef PACMAN_STOPWATCH_H
#define PACMAN_STOPWATCH_H

// TODO update pattern (see Camera)

class Stopwatch {
    int tick = 0;
    int deltaTime = 0;

    static Stopwatch stopwatch;

    Stopwatch() = default;

    ~Stopwatch() = default;
public:
    static Stopwatch& getInstance();
};


#endif //PACMAN_STOPWATCH_H