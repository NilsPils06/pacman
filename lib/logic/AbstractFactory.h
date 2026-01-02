#ifndef PACMAN_ABSTRACTFACTORY_H
#define PACMAN_ABSTRACTFACTORY_H
#include "subject/Coin.h"
#include "subject/Fruit.h"
#include "subject/Ghost.h"
#include "subject/Pacman.h"
#include "subject/Wall.h"

class AbstractFactory {
public:
    /**
     * @brief Constructs an AbstractFactory object.
     * @note Not used, since this is an abstract class.
     */
    AbstractFactory() = default;

    /**
     * @brief Destructs the object.
     */
    virtual ~AbstractFactory() = default;

    /**
     * @brief Creates a wall at the coordinates coords.
     * @param coords
     * @return
     */
    virtual std::shared_ptr<subjects::Wall> createWall(Coords coords) = 0;

    /**
     * @brief Creates a pacman at the coordinates coords.
     * @param coords
     * @return
     */
    virtual std::shared_ptr<subjects::Pacman> createPacman(Coords coords) = 0;

    /**
     * @brief Creates a coin at the coordinates coords.
     * @param coords
     * @return
     */
    virtual std::shared_ptr<subjects::Coin> createCoin(Coords coords) = 0;

    /**
     * @brief Creates a fruit at the coordinates coords.
     * @param coords
     * @return
     */
    virtual std::shared_ptr<subjects::Fruit> createFruit(Coords coords) = 0;

    /**
     * @brief Creates a ghost at the coordinates coords.
     * @param coords
     * @return
     */
    virtual std::shared_ptr<subjects::Ghost> createGhost(Coords coords) = 0;
};

#endif // PACMAN_ABSTRACTFACTORY_H
