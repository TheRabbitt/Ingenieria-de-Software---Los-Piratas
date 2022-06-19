# CMakeList.txt : CMake project for PacMan
#
#
cmake_minimum_required (VERSION 3.8)

# Nombre del directorio principal
project ("PacMan")

# Numero de version del proyecto
set(PacMan_VERSION_MAJOR "1")
set (PacMan_VERSION_MINOR "0")
set(PacMan_VERSION_PATCH "0")

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Directorios reconocidos por los macro include 
include_directories(include ${CMAKE_SOURCE_DIR}/SFML/include)

# Configura el directorio donde construir en modo "debug" o "release"
set(debugName "x64-debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/out/build/${debugName}/bin)
set(releaseName "x64-release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/out/build/${releaseName}/bin)

# Archivos .cpp con los que se construye el binario ejecutable. AppIcon.rc agrega icono al ejecutable
add_executable (PacMan "AppIcon.rc" "src/main.cpp" "src/Entity.cpp" "src/PacMan.cpp" "src/Ghost.cpp" "src/GameController.cpp" "src/State.cpp" "src/Game.cpp" "src/Menu.cpp" "src/Map.cpp" "src/Dots.cpp" "src/Publisher.cpp" "src/Strategy.cpp" "src/Chase.cpp" "src/Scatter.cpp" "src/Frightened.cpp")

# Directorio de la libreria
add_subdirectory (SFML)

# Ejecuta la aplicacion sin abrir una consola
set_property(TARGET PacMan PROPERTY WIN32_EXECUTABLE true)

# Librerias a incluir
target_link_libraries(PacMan sfml-audio sfml-graphics sfml-main
                      sfml-system sfml-window)

# Copia las librerias dinamicas compiladas (.dll) al directorio del ejecutable
add_custom_command(TARGET PacMan POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:PacMan> 
                   $<TARGET_FILE_DIR:PacMan> COMMAND_EXPAND_LISTS
                  )

# Copia la carpeta media al directorio del ejecutable
file(COPY "${CMAKE_SOURCE_DIR}/media" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# TESTS
add_subdirectory (tests)

# Crea directorio con bin y media en modo Install
install(TARGETS PacMan DESTINATION bin)
install(FILES "media/images/Ghost16.png" "media/images/Pacman16.png" "media/images/PacmanDeath16.png" "media/images/Map16.png" DESTINATION media/images)
install(FILES "media/fonts/namco.ttf" "media/fonts/pac-font.ttf" DESTINATION media/fonts)

# Configuracion de cpack para el installer
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_SOURCE_GENERATOR "TGZ")
# Da la opcion de agregar el directorio de instalacion al path y crear un shortcut en el desktop
#set(CPACK_NSIS_MODIFY_PATH "ON")

# Iconos para el installer / uninstaller
set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/media/images/pacman.ico")
set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/media/images/pacman.ico")
# Icono del unistaller en panel de control
set(CPACK_NSIS_INSTALLED_ICON_NAME "Uninstall.exe")
# Iamgen en el instalador
set(CPACK_PACKAGE_ICON "${CMAKE_SOURCE_DIR}/media/images\\\\pacman.bmp")
# Numero de version en la carpeta instalada
set(CPACK_PACKAGE_INSTALL_DIRECTORY "PacMan ${PacMan_VERSION_MAJOR}.${PacMan_VERSION_MINOR}.${PacMan_VERSION_PATCH}")

# Declaracion de licencia a mostrar en el installer
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")

# Nombre de la compañia :p
set(CPACK_PACKAGE_VENDOR "Los Piratas")

# Link al ejecutable para crear el shortcut - no logra setear bien el directorio "start in" 
#set(CPACK_CREATE_DESKTOP_LINKS PacMan)

# Nombre del ejecutable y nombre del shortcut
#set(CPACK_PACKAGE_EXECUTABLES "PacMan" "pacman" )

# Accesos directos en Start Menu
#set(CPACK_NSIS_MENU_LINKS "bin/PacMan.exe" "PacMan" "Uninstall.exe" "Uninstall")

# Comando alternativo para crear el shortcut en el desktop. SetOutPath configura el directorio "start in"
set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "
    SetOutPath '$INSTDIR\\\\bin'
    CreateShortCut \\\"$DESKTOP\\\\PacMan.lnk\\\" \\\"$INSTDIR\\\\bin\\\\PacMan.exe\\\"
")
set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS "
    Delete \\\"$DESKTOP\\\\PacMan.lnk\\\"
")

get_cmake_property(CPACK_COMPONENTS_ALL COMPONENTS)
list(REMOVE_ITEM CPACK_COMPONENTS_ALL "devel" "lib")
include(CPack)