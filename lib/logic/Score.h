#ifndef PACMAN_SCORE_H
#define PACMAN_SCORE_H
#include "Observer.h"

class Score final : public Observer {
    int score = 0;
    float pendingLoss = 0;
    float timeSinceCollection = 0;

public:
    /**
     * @brief Constructs an empty Score object.
     */
    Score() = default;

    /**
     * @brief Constructs a Score object.
     * @param subject the subject to be observed.
     */
    explicit Score(const std::shared_ptr<subjects::Subject>& subject) : Observer(subject) {}

    /**
     * @brief Update timeSinceCollection and decrease score every second.
     * @note Called every tick.
     */
    void tick();

    /**
     *
     * @return the current score.
     */
    [[nodiscard]] int getScore() const;

    /**
     * @brief Handles event e.
     * @param e
     */
    void update(const std::shared_ptr<TickEvent>& e) override {}

    /**
     * @brief Handles event e.
     * @param e
     */
    void update(const std::shared_ptr<EatenEvent>& e) override {}

    /**
     * @brief Handles event e.
     * @param e
     */
    void update(const std::shared_ptr<RenderStaticEvent>& e) override {}

    /**
     * @brief Handles event e.
     * @param e
     */
    void update(const std::shared_ptr<DirectionChangeEvent>& e) override {}

    /**
     * @brief Updates score based on the collection and timeSinceCollection.
     * @param e a CollectEvent.
     */
    void update(const std::shared_ptr<CollectEvent>& e) override;

    /**
     * @brief Handles event e.
     * @param e
     */
    void update(const std::shared_ptr<DieEvent>& e) override {}
};

#endif // PACMAN_SCORE_H
