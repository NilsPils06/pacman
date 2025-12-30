#ifndef PACMAN_SCORE_H
#define PACMAN_SCORE_H
#include "Observer.h"

class Score final : public Observer {
    int score = 0;
    float pendingLoss = 0;
    float timeSinceCollection = 0;

public:
    Score() = default;
    explicit Score(const std::shared_ptr<subjects::Subject>& subject) : Observer(subject) {}
    void tick();
    [[nodiscard]] int getScore() const;
    void update(const std::shared_ptr<TickEvent>& e) override {}
    void update(const std::shared_ptr<EatenEvent>& e) override {}
    void update(const std::shared_ptr<RenderStaticEvent>& e) override {}
    void update(const std::shared_ptr<DirectionChangeEvent>& e) override {}
    void update(const std::shared_ptr<CollectEvent>& e) override;
    void update(const std::shared_ptr<DieEvent>& e) override {}
};

#endif // PACMAN_SCORE_H
