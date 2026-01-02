#ifndef PACMAN_STATE_H
#define PACMAN_STATE_H
#include <SFML/Window/Event.hpp>
#include <memory>

class StateManager;
class State {
protected:
    std::weak_ptr<StateManager> manager;

public:
    /**
     * @brief Constructs a State object.
     * @param manager the StateManager to manage this State.
     */
    explicit State(const std::shared_ptr<StateManager>& manager) : manager(manager) {}

    /**
     * @brief Destructs the State object.
     */
    virtual ~State() = default;

    /**
     * @brief Handles key presses.
     * @param event a SFML KeyEvent.
     */
    virtual void onKeyPress(sf::Event::KeyEvent event) = 0;

    /**
     * @brief Handles text input.
     * @param event a SFML TextEvent.
     */
    virtual void onTextEntered(sf::Event::TextEvent event) {}

    /**
     * @brief Handles mouse clicks.
     * @param event a SFML MouseButtonEvent.
     */
    virtual void onMouseClick(sf::Event::MouseButtonEvent event) {};

    /**
     * @brief Renders this State to the screen.
     */
    virtual void render() = 0;
};

#endif // PACMAN_STATE_H
