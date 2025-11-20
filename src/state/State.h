#ifndef PACMAN_STATE_H
#define PACMAN_STATE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

class StateManager;
class State {
protected:
    std::weak_ptr<StateManager> manager;
    std::shared_ptr<sf::RenderWindow> window;

public:
    explicit State(std::shared_ptr<StateManager> manager, std::shared_ptr<sf::RenderWindow> window) : manager(manager), window(std::move(window)) {}

    virtual ~State() = default;

    virtual void onKeyPress(sf::Event::KeyEvent event) = 0;

    virtual void render() = 0;
};

#endif // PACMAN_STATE_H
