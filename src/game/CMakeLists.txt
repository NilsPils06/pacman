SET(SRC main.cpp Game.cpp)
ADD_EXECUTABLE(game ${SRC})

FIND_PACKAGE(SFML COMPONENTS system window graphics)
TARGET_INCLUDE_DIRECTORIES(game PRIVATE ${SFML_INCLUDE_DIR})

TARGET_LINK_LIBRARIES(game PRIVATE sfml-system sfml-window sfml-graphics logic)