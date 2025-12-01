#include "World.h"

#include "Event.h"
#include "subject/Wall.h"
#include <fstream>
#include <iostream>
#include <utility>

World::World(std::shared_ptr<AbstractFactory> f) : factory(std::move(f)) {
    std::ifstream file;
    file.open("../../assets/maps/1.txt");
    if (!file.is_open()) {
        std::cerr << "file not found" << std::endl;
    }

    std::string line;
    int height = 0;
    int width = 0;
    while (std::getline(file, line)) {
        ++height;
        width = std::max(width, static_cast<int>(line.length()));
    }

    float normalized_height = 2.0f / static_cast<float>(height);
    float normalized_width = 2.0f / static_cast<float>(width);

    // reset positie op file
    file.clear();
    file.seekg(0);

    auto max_x = static_cast<float>(width - 1);
    auto max_y = static_cast<float>(height - 1);

    char token;
    int x = 0;
    int y = 0;

    while (file.get(token)) {
        float normalized_x = 2.0f * (static_cast<float>(x) / max_x) - 1.0f;
        float normalized_y = 2.0f * (static_cast<float>(y) / max_y) - 1.0f;

        Coords coords{normalized_x, normalized_y, normalized_width, normalized_height};

        // TODO update map layout so that you can distinguish the ghosts

        switch (token) {
        case 'W': {
            std::shared_ptr<subjects::Wall> wall = factory->createWall(coords);
            entities.push_back(wall);
            components[wall] = wall;
            break;
        }
        case '_':
            // blank space
            break;
        case 'F': {
            std::shared_ptr<subjects::Fruit> fruit = factory->createFruit(coords);
            entities.push_back(fruit);
            break;
        }
        case 'C': {
            std::shared_ptr<subjects::Coin> coin = factory->createCoin(coords);
            entities.push_back(coin);
            break;
        }
        case 'P': {
            std::shared_ptr<subjects::Pacman> pacman = factory->createPacman(coords);
            entities.push_back(pacman);
            visitors[pacman] = pacman;
            break;
        }
        case 'G': {
            std::shared_ptr<subjects::Ghost> ghost = factory->createGhost(coords);
            entities.push_back(ghost);
            break;
        }
        default:
            x = 0;
            y += 1;
            continue;
        }

        x += 1;
    }
}
void World::moveLeft() const {
    for (const auto& entity : entities) {
        entity->notify(std::make_shared<DirectionChangeEvent>(LEFT));
    }
}
void World::moveUp() const {
    for (const auto& entity : entities) {
        entity->notify(std::make_shared<DirectionChangeEvent>(UP));
    }
}
void World::moveDown() const {
    for (const auto& entity : entities) {
        entity->notify(std::make_shared<DirectionChangeEvent>(DOWN));
    }
}
void World::moveRight() const {
    for (const auto& entity : entities) {
        entity->notify(std::make_shared<DirectionChangeEvent>(RIGHT));
    }
}
void World::checkCollisions() const {
    for (const auto& [modelA, component]: components) {
        for (const auto& [modelB, visitor] : visitors) {
            Coords a = modelA->getCoords();
            Coords b = modelB->getCoords();

            // bottom left of A
            float x1 = a.x-(a.width/2);
            float y1 = a.y-(a.height/2);

            // top right of A
            float x2 = a.x+(a.width/2);
            float y2 = a.y+(a.height/2);

            // bottom left of B
            float x3 = b.x-(b.width/2);
            float y3 = b.y-(b.height/2);

            // top right of B
            float x4 = b.x+(b.width/2);
            float y4 = b.y+(b.height/2);

            // intersection
            const float x5 = std::max(x1, x3);
            const float y5 = std::max(y1, y3);

            const float x6 = std::min(x2, x4);
            const float y6 = std::min(y2, y4);

            if (x5 > x6 || y5 > y6) {
                // no intersection
                continue;
            }

            component->accept(visitor);
        }
    }
}

void World::render() const {
    checkCollisions();
    for (const auto& entity : entities) {
        entity->tick();
        entity->notify(std::make_shared<PositonUpdateEvent>(entity->getCoords()));
    }
}
