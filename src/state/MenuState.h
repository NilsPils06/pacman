#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "State.h"

#include <SFML/Graphics/Text.hpp>
#include <map>

class MenuState final : public State {
    std::map<std::string, int> scores;
public:
    explicit MenuState(const std::shared_ptr<StateManager>& manager);

    ~MenuState() override;

    void onKeyPress(sf::Event::KeyEvent event) override;

    void render() override;

    void loadScores();

    void renderScoreboard();
};

#endif // PACMAN_MENUSTATE_H
