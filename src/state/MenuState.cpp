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
    const sf::Vector2u size = Game::window.getSize();
    playButton.setSize(sf::Vector2f(200.f, 60.f));
    playButton.setFillColor(sf::Color::Green);
    playButton.setOrigin(100.f, 30.f);
    playButton.setPosition(static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 2.f);

    loadScores();
}
MenuState::~MenuState() {
    if (std::ofstream out{"../../assets/scores.json"}; out.is_open()) {
        json j;
        for (auto& [name, score] : (*scores))
            j[name] = score;

        out << j;
    }
};
void MenuState::onKeyPress(sf::Event::KeyEvent event) {
    if (event.code != sf::Keyboard::Enter)
        return;
    if (playerName.empty())
        return;
    if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
        state_manager->push(std::make_unique<LevelState>(state_manager));
    }
}
void MenuState::render() {
    static sf::Text title;

    if (title.getString().isEmpty()) {
        title.setFont(Game::font);

        title.setString("Pac-Man");
        title.setFillColor(sf::Color::Yellow);
        title.setCharacterSize(128);

        const sf::FloatRect bounds = title.getLocalBounds();
        title.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

        const sf::Vector2u size = Game::window.getSize();
        title.setPosition(static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 4.f);
    }

    static sf::Text playText;
    if (playText.getString().isEmpty()) {
        playText.setFont(Game::fontFront);
        playText.setString("PLAY");
        playText.setCharacterSize(60);
        playText.setFillColor(sf::Color::Black);
        const sf::FloatRect bounds = playText.getLocalBounds();
        playText.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
        playText.setPosition(playButton.getPosition());
    }

    static sf::Text inputText;
    inputText.setFont(Game::font);
    inputText.setString("Enter Name: " + playerName + "_");
    inputText.setCharacterSize(40);
    inputText.setFillColor(sf::Color::Cyan);

    const sf::FloatRect bounds = inputText.getLocalBounds();
    inputText.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    const sf::Vector2u size = Game::window.getSize();
    inputText.setPosition(static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 4.f + 80.f);

    Game::window.draw(title);
    Game::window.draw(inputText);
    Game::window.draw(playButton);
    Game::window.draw(playText);

    renderScoreboard();
}
void MenuState::loadScores() {
    if (std::ifstream input{"../../assets/scores.json"}; input.is_open()) {
        try {
            json j;
            input >> j;
            scores = std::make_shared<std::map<std::string, int>>(j.get<std::map<std::string, int>>());
        } catch (nlohmann::detail::parse_error& e) {
            std::cerr << e.what() << std::endl;
            scores = std::make_shared<std::map<std::string, int>>();
        }
    }
}

void MenuState::renderScoreboard() {
    const sf::Vector2u size = Game::window.getSize();
    float y = static_cast<float>(size.y) * 2 / 3.f;

    for (auto const& [name, score] : (*scores)) {
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
void MenuState::onTextEntered(sf::Event::TextEvent event) {
    // 8 is backspace
    if (event.unicode == 8) {
        if (!playerName.empty())
            playerName.pop_back();
    } else if (event.unicode < 128 && playerName.length() < 12) {
        playerName += static_cast<char>(event.unicode);
    }
}
void MenuState::onMouseClick(sf::Event::MouseButtonEvent event) {
    if (playerName.empty())
        return;
    if (event.button == sf::Mouse::Left) {
        if (const sf::Vector2f mousePos(static_cast<float>(event.x), static_cast<float>(event.y));
            playButton.getGlobalBounds().contains(mousePos)) {
            if (std::shared_ptr<StateManager> state_manager = manager.lock()) {
                state_manager->push(std::make_unique<LevelState>(state_manager, playerName, scores));
            }
        }
    }
}