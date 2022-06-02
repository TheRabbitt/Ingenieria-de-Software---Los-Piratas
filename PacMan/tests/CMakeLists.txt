# CMakeList.txt : CMake project for PacMan, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Nombre del directorio principal
project ("PacMan")

# Directorios reconocidos por los macro include 
include_directories(${CMAKE_SOURCE_DIR}/../include ${CMAKE_SOURCE_DIR}/../SFML/include)

# Configura el directorio donde construir en configuracion "debug"
#set(presetName "x64-debug")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/out/build/${presetName})

# Archivos .cpp con los que se construye el binario ejecutable
add_executable (testImage "../src/Entity.cpp" "../include/Entity.hpp" "../src/PacMan.cpp" "../include/PacMan.hpp" "PacManLoadImage.cpp")

# Directorio de la libreria
#add_subdirectory (SFML)

# No abre una consola al ejecutar la aplicacion
#set_property(TARGET PacMan PROPERTY WIN32_EXECUTABLE true)

# Librerias a incluir
target_link_libraries(testImage sfml-graphics sfml-main
                      sfml-system sfml-window)

# Copia las librerias compiladas (.dll) al directorio del ejecutable
add_custom_command(TARGET testImage POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:testImage> 
                   $<TARGET_FILE_DIR:testImage> COMMAND_EXPAND_LISTS
                  )

# Copia la carpeta media al directorio del ejecutable
add_custom_command(TARGET testImage POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E make_directory media media/images
                   $<TARGET_FILE_DIR:testImage> COMMAND_EXPAND_LISTS
                   )
add_custom_command(TARGET testImage POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${CMAKE_SOURCE_DIR}/../media/images/Pacman16.png
                   ${CMAKE_CURRENT_BINARY_DIR}/media/images
                  )

# TODO: Add .. and install targets if needed.
