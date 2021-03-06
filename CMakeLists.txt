cmake_minimum_required(VERSION 3.10)
project(GAME_PROVA3)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(testDirectory)

set(SFML_ROOT C:/Users/Yasmin/Documents/SFML-2.4.2)

set(SOURCE_FILES main.cpp Character.cpp Character.h Monster.cpp Monster.h GameCharacter.cpp GameCharacter.h Entity.cpp Entity.h
        Projectile.cpp Projectile.h Random.cpp Random.h TextDisplay.cpp TextDisplay.h Enumeration.cpp Enumeration.h
        PickUp.cpp PickUp.h Wall.cpp Wall.h Sound.cpp Sound.h Tile.cpp Tile.h Map.cpp Map.h MapObjects.cpp MapObjects.h
        Strategy.cpp Strategy.h LoadDisplay.cpp LoadDisplay.h)

add_executable(GAME_PROVA3 ${SOURCE_FILES})

add_library(core ${SOURCE_FILES})

target_link_libraries(GAME_PROVA3 core)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(GAME_PROVA3 ${SFML_LIBRARIES})
endif()