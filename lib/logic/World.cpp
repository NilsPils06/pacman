#include "World.h"

#include "Event.h"
#include "subject/Wall.h"
#include <fstream>
#include <utility>

World::World(std::shared_ptr<AbstractFactory> f) : factory(std::move(f)) {
    std::ifstream file;
    file.open("../../assets/maps/1.txt");

    std::string line;
    int height = 0;
    int width = 0;
    while (std::getline(file, line)) {
        ++height;
        width = std::max(width, static_cast<int>(line.length()));
    }

    float max_x = static_cast<float>(width - 1);
    float max_y = static_cast<float>(height - 1);

    char token;
    int x = 0;
    int y = 0;

    while (file.get(token)) {
        float normalized_x = 2.0f * ((float)x / max_x) - 1.0f;
        float normalized_y = 2.0f * ((float)y / max_y) - 1.0f;

        switch (token) {
        case 'W':
            entities.push_back(std::make_unique<subjects::Wall>(factory->createWall(normalized_x, normalized_y)));
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

        // voeg entitymodel toe aan world

        x += 1;
    }
}

void World::render() const {
    for (const auto& entity : entities) {
        entity->notify(std::make_shared<PositonUpdateEvent>(entity->getCoords()));
    }
}
