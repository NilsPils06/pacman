SET(SRC main.cpp Game.cpp
        state/State.cpp
        state/State.h
        state/StateManager.cpp
        state/StateManager.h
        state/MenuState.cpp
        state/MenuState.h
        EntityView/EntityView.cpp
        EntityView/EntityView.h
        EntityView/Pacman.cpp
        EntityView/Pacman.h
        EntityView/Ghost.cpp
        EntityView/Ghost.h
        EntityView/Coin.cpp
        EntityView/Coin.h
        EntityView/Fruit.cpp
        EntityView/Fruit.h
        EntityView/Wall.cpp
        EntityView/Wall.h)
ADD_EXECUTABLE(game ${SRC})

FIND_PACKAGE(SFML COMPONENTS system window graphics)
TARGET_INCLUDE_DIRECTORIES(game PRIVATE ${SFML_INCLUDE_DIR} ../lib/logic)

TARGET_LINK_LIBRARIES(game PRIVATE sfml-system sfml-window sfml-graphics logic)