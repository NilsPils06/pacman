#ifndef PACMAN_SCORE_H
#define PACMAN_SCORE_H
#include "Observer.h"

class Score final : public Observer {
    int score = 0;

public:
    Score() = default;
    explicit Score(const std::shared_ptr<subjects::Subject>& subject) : Observer(subject) {}
    void update(std::shared_ptr<Event> e) override;
    [[nodiscard]] int getScore() const;
};

#endif // PACMAN_SCORE_H
