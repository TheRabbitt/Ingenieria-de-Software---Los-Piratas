# CMakeList.txt : CMake project for PacMan, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Nombre del directorio principal
project ("PacMan")

# Directorios reconocidos por los macro include 
include_directories(include ${CMAKE_SOURCE_DIR}/SFML/include)

# Configura el directorio donde construir en configuracion "debug"
set(presetName "x64-debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/out/build/${presetName})

# Archivos .cpp con los que se construye el binario ejecutable
add_executable (PacMan "src/main.cpp" "src/Entity.cpp" "src/PacMan.cpp" "src/Game.cpp"  "src/Map.cpp")

# Directorio de la libreria
add_subdirectory (SFML)

# No abre una consola al ejecutar la aplicacion
#set_property(TARGET PacMan PROPERTY WIN32_EXECUTABLE true)

# Librerias a incluir
target_link_libraries(PacMan sfml-audio sfml-graphics sfml-main
                      sfml-system sfml-window)

# Copia las librerias compiladas (.dll) al directorio del ejecutable
add_custom_command(TARGET PacMan POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:PacMan> 
                   $<TARGET_FILE_DIR:PacMan> COMMAND_EXPAND_LISTS
                  )

# Copia la carpeta media al directorio del ejecutable
file(COPY "${CMAKE_SOURCE_DIR}/media" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# TESTS
add_executable (testImage "src/Entity.cpp" "src/PacMan.cpp" "tests/PacManLoadImage.cpp" )

target_link_libraries(testImage sfml-graphics sfml-main
                      sfml-system sfml-window)

add_executable (mapTest "tests/mapTest.cpp" )

target_link_libraries(testImage sfml-graphics sfml-main
                      sfml-system sfml-window)


