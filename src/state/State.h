#ifndef PACMAN_STATE_H
#define PACMAN_STATE_H
#include <SFML/Window/Event.hpp>
#include <memory>

class StateManager;
class State {
protected:
    std::weak_ptr<StateManager> manager;

public:
    explicit State(const std::shared_ptr<StateManager>& manager) : manager(manager) {}

    virtual ~State() = default;

    virtual void onKeyPress(sf::Event::KeyEvent event) = 0;
    virtual void onTextEntered(sf::Event::TextEvent event) {}
    virtual void onMouseClick(sf::Event::MouseButtonEvent event) {};

    virtual void render() = 0;
};

#endif // PACMAN_STATE_H
