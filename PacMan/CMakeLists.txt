# CMakeList.txt : CMake project for PacMan, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Nombre del directorio principal
project ("PacMan")
# Directorios reconocidos por los macro include 
#include_directories(include ${CMAKE_SOURCE_DIR}/SFML/include)

# Add source to this project's executable.
# Archivos .cpp pasados al linker
#add_executable (PacMan "src/main.cpp" "src/Game.cpp" "src/PacMan.cpp" "src/Entity.cpp")
add_executable (PacMan "test.cpp")

#add_subdirectory (SFML)

# Disable the console window
# No abre una consola al ejecutar la aplicacion (solo windows)
#set_property(TARGET PacMan PROPERTY WIN32_EXECUTABLE true)

# Librerias a incluir
#target_link_libraries(PacMan sfml-audio sfml-graphics sfml-main
#                      sfml-system sfml-window)

# Copy .dll libraries to .exe folder
# Copia las librerias compiladas (.dll) al directorio del ejecutable
#add_custom_command(TARGET PacMan POST_BUILD
#                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:PacMan> 
#                   $<TARGET_FILE_DIR:PacMan> COMMAND_EXPAND_LISTS
#                  )

# Copia la carpeta media al directorio del ejecutable
#add_custom_command(TARGET PacMan POST_BUILD
#                   COMMAND ${CMAKE_COMMAND} -E make_directory media media/images
#                   $<TARGET_FILE_DIR:PacMan> COMMAND_EXPAND_LISTS
#                   )
#add_custom_command(TARGET PacMan POST_BUILD
#                   COMMAND ${CMAKE_COMMAND} -E copy
#                   ${CMAKE_SOURCE_DIR}/media/images/Pacman16.png
#                   ${CMAKE_CURRENT_BINARY_DIR}/media/images
#                  )
#add_custom_target(TARGET PacMan POST_BUILD
#                  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/media
#                  $<TARGET_FILE_DIR:PacMan> COMMAND_EXPAND_LISTS
#                  )

# TODO: Add tests and install targets if needed.
