project(bubble)

set(CMAKE_BUILD_TYPE Debug)

#Lägger till alla source filer
set(SOURCE_FILES
    source/objects/headers/Behaviour.h
    source/objects/headers/Enemy_Behaviour.h
    source/objects/headers/Enemy.h
    source/objects/headers/Entity.h
    source/objects/headers/Game.h
    source/objects/headers/Key_Handling.h
    source/objects/headers/Level.h
    source/objects/headers/Menu.h
    source/objects/headers/Platform_Behaviour.h
    source/objects/headers/Platform.h
    source/objects/headers/Player.h
    source/objects/headers/Player1_Behaviour.h
    source/objects/headers/Projectile_Behaviour.h
    source/objects/headers/Projectile.h
    source/objects/headers/Texture_Container.h
    source/objects/headers/tool_chain.h
    source/objects/headers/World.h

    source/objects/imps/Enemy_Behaviour.cpp
    source/objects/imps/Enemy.cpp
    source/objects/imps/Game.cpp
    source/objects/imps/Key_Handling.cpp
    source/objects/imps/Level.cpp
    source/objects/imps/Menu.cpp
    source/objects/imps/Platform.cpp
    source/objects/imps/Player.cpp
    source/objects/imps/Player1_Behaviour.cpp
    source/objects/imps/Projectile_Behaviour.cpp
    source/objects/imps/Projectile.cpp
    source/objects/imps/Texture_Container.cpp
    source/objects/imps/World.cpp
    source/main.cpp
) 


# På skolans Linux -system finns det två versioner av SFML. Se efter vilken som används:
if (DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".*prog/gcc/6.1.0.*"))
    set(CMAKE_CXX_COMPILER /sw/gcc-6.1.0/bin/g++)
    if (DEFINED ENV{SFML_ROOT})
        list(APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
    endif()
endif()

# Välj vilka moduler i SFML som ska användas.
set(SFML_MODULES network graphics window system)

# Försök att hitta SFML genom att anropa 'FindSFML.cmake ' (om det finns).
find_package(SFML 2 COMPONENTS ${SFML_MODULES})
include_directories(${SFML_INCLUDE_DIR})

# Om det inte finns hoppas vi på att SFML finns installerat ändå.
if (NOT (${SFML_FOUND} STREQUAL "TRUE"))
    set(SFML_LIBRARIES "")
    foreach(i ${SFML_MODULES})
        list(APPEND SFML_LIBRARIES "sfml-${i}")
    endforeach(i)
endif()

add_executable(bubble ${SOURCE_FILES})

target_link_libraries(bubble ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})