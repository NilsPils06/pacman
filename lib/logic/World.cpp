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

    float normalized_height = 2.0f / static_cast<float>(height - 1);
    float normalized_width = 2.0f / static_cast<float>(width - 1);

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

        switch (token) {
        case 'W': {
            std::shared_ptr<subjects::Wall> wall = factory->createWall(coords);
            entities.push_back(wall);
            components[wall] = wall;
            break;
        }
        case '_':
            break;
        case 'F': {
            std::shared_ptr<subjects::Fruit> fruit = factory->createFruit(coords);
            entities.push_back(fruit);
            components[fruit] = fruit;
            collectables++;
            break;
        }
        case 'C': {
            std::shared_ptr<subjects::Coin> coin = factory->createCoin(coords);
            entities.push_back(coin);
            components[coin] = coin;
            collectables++;
            break;
        }
        case 'P': {
            std::shared_ptr<subjects::Pacman> pacman = factory->createPacman(coords);
            entities.push_back(pacman);
            collisionHandler = std::make_shared<PacmanCollisionHandler>(pacman);
            break;
        }
        case 'G': {
            std::shared_ptr<subjects::Ghost> ghost = factory->createGhost(coords);
            entities.push_back(ghost);
            components[ghost] = ghost;
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
    for (const auto& [modelA, component] : components) {
        if (modelA->isExpired())
            continue;

        const Coords a = modelA->getCoords();
        const Coords b = collisionHandler->getPacmanCoords();

        // Bottom left and top right of A
        float x1 = a.x - (a.width / 2);
        float y1 = a.y - (a.height / 2);
        float x2 = a.x + (a.width / 2);
        float y2 = a.y + (a.height / 2);

        // Bottom left and top right of B
        float x3 = b.x - (b.width / 2);
        float y3 = b.y - (b.height / 2);
        float x4 = b.x + (b.width / 2);
        float y4 = b.y + (b.height / 2);

        // Intersection bounds
        const float x5 = std::max(x1, x3);
        const float y5 = std::max(y1, y3);
        const float x6 = std::min(x2, x4);
        const float y6 = std::min(y2, y4);

        const float overlapX = x6 - x5;
        const float overlapY = y6 - y5;

        if (overlapX < 0.002f || overlapY < 0.002f) {
            continue;
        }

        component->accept(collisionHandler);
    }
}

void World::render() {
    std::erase_if(entities, [](std::shared_ptr<subjects::EntityModel>& e) {
        if (e->isExpired()) {
            e->detachAll();
            e.reset();
            return true;
        }
        return false;
    });

    if (collisionHandler->isDying()) {
        collisionHandler->tick();
    } else {
        for (const auto& entity : entities) {
            if (entity->isExpired())
                continue;
            entity->tick();
        }
        checkCollisions();
        collectables -= collisionHandler->getAmountOfCollections();
    }
}
bool World::isOver() const { return collisionHandler->isDead(); }
bool World::isCompleted() const { return collectables <= 0; }
int World::getLives() const { return collisionHandler->getLives(); }