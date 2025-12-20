#ifndef PACMAN_LEVELSTATE_H
#define PACMAN_LEVELSTATE_H
#include "../EntityFactory.h"
#include "State.h"
#include "World.h"

class LevelState final : public State {
    std::shared_ptr<World> world;
    std::shared_ptr<EntityFactory> factory;
    std::shared_ptr<Score> score;
    std::string playerName;
    std::shared_ptr<std::map<std::string, int>> scores;

public:
    explicit LevelState(const std::shared_ptr<StateManager>& manager);

    LevelState(const std::shared_ptr<StateManager>& manager, std::string playerName,
               const std::shared_ptr<std::map<std::string, int>>& scores);

    void onKeyPress(sf::Event::KeyEvent event) override;

    void saveScore() const;

    void render() override;
};

#endif // PACMAN_LEVELSTATE_H
