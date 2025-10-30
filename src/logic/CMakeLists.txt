SET(SRC
        Stopwatch.cpp
        Random.cpp
        Random.h
        Subject.cpp
        Subject.h
        EntityModel.cpp
        EntityModel.h
        Ghost.cpp
        Ghost.h)

ADD_LIBRARY(logic STATIC ${SRC})