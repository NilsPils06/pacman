SET(SRC main.cpp Game.cpp
        State.cpp
        State.h
        StateManager.cpp
        StateManager.h
        MenuState.cpp
        MenuState.h)
ADD_EXECUTABLE(game ${SRC})

FIND_PACKAGE(SFML COMPONENTS system window graphics)
TARGET_INCLUDE_DIRECTORIES(game PRIVATE ${SFML_INCLUDE_DIR})

TARGET_LINK_LIBRARIES(game PRIVATE sfml-system sfml-window sfml-graphics logic)