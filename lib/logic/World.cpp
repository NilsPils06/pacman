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

    // reset positie op file
    file.clear();
    file.seekg(0);

    float max_x = static_cast<float>(width - 1);
    float max_y = static_cast<float>(height - 1);

    char token;
    int x = 0;
    int y = 0;

    while (file.get(token)) {
        float normalized_x = 2.0f * (static_cast<float>(x) / max_x) - 1.0f;
        float normalized_y = 2.0f * (static_cast<float>(y) / max_y) - 1.0f;

        switch (token) {
        case 'W':
            entities.push_back(factory->createWall(normalized_x, normalized_y));
            break;
        case '_':
            break;
        case 'F':
            break;
        case 'C':
            break;
        case 'P':
            break;
        case 'G':
            break;
        default:
            x = 0;
            y += 1;
            continue;
        }

        x += 1;
    }
}

void World::render() const {
    for (const auto& entity : entities) {
        entity->notify(std::make_shared<PositonUpdateEvent>(entity->getCoords()));
    }
}
