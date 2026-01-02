#ifndef PACMAN_LEVELSTATE_H
#define PACMAN_LEVELSTATE_H
#include "../EntityFactory.h"
#include "State.h"
#include "World.h"

#include <map>

class LevelState final : public State {
    std::shared_ptr<World> world;
    std::shared_ptr<EntityFactory> factory;
    std::shared_ptr<Score> score;
    std::string playerName;
    std::shared_ptr<std::map<std::string, int>> scores;
    int level = 1;

public:
    /**
     * @brief Constructs a LevelState object.
     * @param manager the StateManager to manage this State.
     * @param playerName the name of the current player.
     * @param scores a pointer to all previous scores.
     */
    LevelState(const std::shared_ptr<StateManager>& manager, std::string playerName,
               const std::shared_ptr<std::map<std::string, int>>& scores);

    /**
     * @brief Handles key presses.
     * @param event a SFML KeyEvent.
     */
    void onKeyPress(sf::Event::KeyEvent event) override;

    /**
     * @brief Saves the current players top score.
     */
    void saveScore() const;

    /**
     * @brief Renders this State to the screen.
     */
    void render() override;
};

#endif // PACMAN_LEVELSTATE_H
