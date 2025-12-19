#include "MenuState.h"
#include "../Game.h"
#include "LevelState.h"
#include "StateManager.h"
#include "json.hpp"

#include <SFML/Graphics/Text.hpp>
#include <fstream>
#include <iostream>

using nlohmann::json;

MenuState::MenuState(const std::shared_ptr<StateManager>& manager) : State(manager) {
    sf::Text text;

    text.setFont(Game::font);

    text.setString("Pac-Man");
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(128);

    const sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    const sf::Vector2u size = Game::window.getSize();
    text.setPosition(static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 2.f);

    loadScores();
}
MenuState::~MenuState() = default;
void MenuState::onKeyPress(sf::Event::KeyEvent event) {
    if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
        state_manager->push(std::make_unique<LevelState>(state_manager));
    }
}
void MenuState::render() {
    static sf::Text text;

    if (text.getString().isEmpty()) {
        text.setFont(Game::font);

        text.setString("Pac-Man");
        text.setFillColor(sf::Color::Yellow);
        text.setCharacterSize(128);

        const sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

        const sf::Vector2u size = Game::window.getSize();
        text.setPosition(static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 2.f);
    }
    Game::window.draw(text);

    renderScoreboard();
}
void MenuState::loadScores() {
    if (std::ifstream input{"../../assets/scores.json"}; input.is_open()) {
        try {
            json j;
            input >> j;
            scores = j.get<std::map<std::string, int>>();
        } catch (nlohmann::detail::parse_error& e) {
            std::cerr << e.what() << std::endl;
            scores = {};
        }
    }
}


void MenuState::renderScoreboard() {
    const sf::Vector2u size = Game::window.getSize();
    float y = static_cast<float>(size.y)*2 / 3.f;

    for (auto const& [name, score] : scores) {
        sf::Text t;
        t.setFont(Game::font);
        t.setString(name + ": " + std::to_string(score));
        t.setCharacterSize(32);
        t.setFillColor(sf::Color::White);

        const sf::FloatRect bounds = t.getLocalBounds();
        t.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
        t.setPosition(static_cast<float>(size.x) / 2.f, y);
        Game::window.draw(t);
        y += 40.f;
    }
}