# CMakeList.txt : CMake project for PacMan, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Nombre del directorio principal
project ("PacMan")

#TESTS
if (CMAKE_BUILD_TYPE STREQUAL Debug)
add_executable (PacManImageTest "../src/Entity.cpp" "../src/PacMan.cpp" "../src/Map.cpp" "PacManImageTest.cpp" )

target_link_libraries(PacManImageTest sfml-graphics sfml-main
                      sfml-system sfml-window)

add_executable (GhostImageTest "../src/Entity.cpp" "../src/PacMan.cpp" "../src/Map.cpp" "GhostImageTest.cpp" "../src/Ghost.cpp" "../src/Strategy.cpp" "../src/Chase.cpp")

target_link_libraries(GhostImageTest sfml-graphics sfml-main
                      sfml-system sfml-window)

add_executable (mapImageTest "../src/Map.cpp" "mapImageTest.cpp" "../src/Dots.cpp")

target_link_libraries(mapImageTest sfml-graphics sfml-main
                      sfml-system sfml-window)

add_executable (menuImageTest "../src/Map.cpp" "../src/PacMan.cpp" "../src/Game.cpp" "../src/Entity.cpp" "../src/Ghost.cpp" "../src/Menu.cpp" "../src/GameController.cpp" "MenuImageTest.cpp" "../src/State.cpp" "../src/Dots.cpp" "../src/Publisher.cpp" "../src/Strategy.cpp" "../src/Chase.cpp" "../src/Scatter.cpp" "../src/Frightened.cpp")

target_link_libraries(menuImageTest sfml-graphics sfml-main
                        sfml-system sfml-window)

add_executable (ScoreTest "../src/Map.cpp" "../src/PacMan.cpp" "../src/Game.cpp" "../src/Entity.cpp" "../src/Ghost.cpp" "../src/Menu.cpp" "../src/GameController.cpp" "MenuImageTest.cpp" "../src/State.cpp" "../src/Dots.cpp" "../src/Publisher.cpp" "../src/Strategy.cpp" "../src/Chase.cpp" "../src/Scatter.cpp" "../src/Frightened.cpp" )

target_link_libraries(ScoreTest sfml-graphics sfml-main
                      sfml-system sfml-window)

add_executable (StrategyTest "../src/Ghost.cpp" "../src/Chase.cpp" "../src/Entity.cpp" "../src/Map.cpp" "../src/PacMan.cpp" "../src/Strategy.cpp" "StrategyTest.cpp" "../src/State.cpp" "../src/Scatter.cpp" )

target_link_libraries(StrategyTest sfml-graphics sfml-main
                      sfml-system sfml-window)


add_executable (PacManMoveTest "../src/Entity.cpp" "../src/PacMan.cpp" "../src/Map.cpp" "PacManMoveTest.cpp")

target_link_libraries(PacManMoveTest sfml-graphics sfml-main
                      sfml-system sfml-window)


#add_executable (test "src/State.cpp" "src/Menu.cpp" "tests/test.cpp" )

#target_link_libraries(test sfml-graphics sfml-main
#                      sfml-system sfml-window)

endif()