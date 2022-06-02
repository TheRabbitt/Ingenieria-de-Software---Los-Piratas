# CMakeList.txt : CMake project for PacMan, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Nombre del directorio principal
project ("PacMan")

# Directorios reconocidos por los macro include 
include_directories(${CMAKE_SOURCE_DIR}/../include ${CMAKE_SOURCE_DIR}/../SFML/include)

# Archivos .cpp con los que se construye el binario ejecutable
add_executable (PacManImageTest "src/Entity.cpp" "src/PacMan.cpp" "src/Map.cpp" "tests/PacManImageTest.cpp" )
add_executable (mapImageTest "src/Map.cpp" "tests/mapImageTest.cpp" )
# Directorio de la libreria
#add_subdirectory (SFML)

# No abre una consola al ejecutar la aplicacion
#set_property(TARGET PacMan PROPERTY WIN32_EXECUTABLE true)

# Librerias a incluir
target_link_libraries(PacManImageTest sfml-graphics sfml-main
                      sfml-system sfml-window)

target_link_libraries(mapImageTest sfml-graphics sfml-main
                      sfml-system sfml-window)
