SET(SRC
        Stopwatch.cpp
        Random.cpp
        Random.h
        Subject.cpp
        Subject.h
        EntityModel.cpp
        EntityModel.h
        Ghost.cpp
        Ghost.h
        Pacman.cpp
        Pacman.h
        World.cpp
        World.h)

ADD_LIBRARY(logic STATIC ${SRC})