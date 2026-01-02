#ifndef PACMAN_MENUSTATE_H
#define PACMAN_MENUSTATE_H

#include "State.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <map>

class MenuState final : public State {
    std::shared_ptr<std::map<std::string, int>> scores;
    std::string playerName;
    sf::RectangleShape playButton;

public:
    /**
     * @brief Constructs a MenuState object.
     * @param manager the StateManager to manage this State.
     */
    explicit MenuState(const std::shared_ptr<StateManager>& manager);

    /**
     * @brief Destroys this object and saves the scores to a json file.
     */
    ~MenuState() override;

    /**
     * @brief Handles key presses.
     * @param event a SFML KeyEvent.
     */
    void onKeyPress(sf::Event::KeyEvent event) override;

    /**
     * @brief Renders this State to the screen.
     */
    void render() override;

    /**
     * @brief Loads the scores from a json file.
     */
    void loadScores();

    /**
     * @brief Displays the top 5 scores on the screen.
     */
    void renderScoreboard() const;

    /**
     * @brief Handles text input.
     * @param event a SFML TextEvent.
     */
    void onTextEntered(sf::Event::TextEvent event) override;

    /**
     * @brief Handles mouse clicks.
     * @param event a SFML MouseButtonEvent.
     */
    void onMouseClick(sf::Event::MouseButtonEvent event) override;
};

#endif // PACMAN_MENUSTATE_H
