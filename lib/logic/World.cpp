#include "World.h"

#include "Event.h"
#include "subject/Wall.h"
#include <fstream>
#include <functional>
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
            walls.push_back(wall);
            break;
        }
        case '_':
            break;
        case 'F': {
            std::shared_ptr<subjects::Fruit> fruit = factory->createFruit(coords);
            entities.push_back(fruit);
            collectables.push_back(fruit);
            break;
        }
        case 'C': {
            std::shared_ptr<subjects::Coin> coin = factory->createCoin(coords);
            entities.push_back(coin);
            collectables.push_back(coin);
            break;
        }
        case 'P': {
            std::shared_ptr<subjects::Pacman> pacman = factory->createPacman(coords);
            entities.push_back(pacman);
            pacmanHandler = std::make_shared<PacmanCollisionHandler>(pacman);
            break;
        }
        case 'G': {
            std::shared_ptr<subjects::Ghost> ghost = factory->createGhost(coords);
            entities.push_back(ghost);
            ghosts.push_back(ghost);
            break;
        }
        default:
            x = 0;
            y += 1;
            continue;
        }

        x += 1;
    }

    std::function walkCheck = [this](const Coords& c) { return this->isWalkable(c); };

    pacmanHandler->setWallValidator(walkCheck);

    for (const auto& gh : ghosts) {
        gh->setWallValidator(walkCheck);
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

bool World::isWalkable(const Coords& target) const {
    if (target.x < -1.0f || target.x > 1.0f || target.y < -1.0f || target.y > 1.0f) {
        return false;
    }
    for (const auto& wall : walls) {
        Coords hitBox = target;
        hitBox.width *= 0.9f;
        hitBox.height *= 0.9f;

        if (hitBox.overlaps(wall->getCoords())) {
            return false;
        }
    }
    return true;
}

void World::checkCollisions() const {
    const Coords pacmanCoords = pacmanHandler->getPacmanCoords();
    for (const auto& ghost : ghosts) {
        if (pacmanCoords.overlaps(ghost->getCoords())) {
            ghost->accept(pacmanHandler);
        }
    }

    for (const auto& collectable : collectables) {
        if (collectable->getCoords().overlaps(pacmanCoords)) {
            collectable->accept(pacmanHandler);
        }
    }
}

void World::render() {
    std::erase_if(collectables, [](std::shared_ptr<subjects::Collectable>& e) {
        if (e->isExpired()) {
            e->detachAll();
            e.reset();
            return true;
        }
        return false;
    });

    if (pacmanHandler->isDying()) {
        pacmanHandler->tick();
    } else {
        for (const auto& entity : entities) {
            if (entity->isExpired())
                continue;
            entity->tick();
        }
        checkCollisions();
    }
}
bool World::isOver() const { return pacmanHandler->isDead(); }
bool World::isCompleted() const { return collectables.empty(); }
int World::getLives() const { return pacmanHandler->getLives(); }