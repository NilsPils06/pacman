#ifndef PACMAN_STATE_H
#define PACMAN_STATE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

class StateManager;
class State {
protected:
    std::weak_ptr<StateManager> manager;

public:
    explicit State(std::shared_ptr<StateManager> manager) : manager(manager) {};

    virtual ~State() = default;

    virtual void onKeyPress(sf::Event::KeyEvent event) = 0;

    virtual void render(std::shared_ptr<sf::RenderWindow> window) = 0;
};

#endif // PACMAN_STATE_H
