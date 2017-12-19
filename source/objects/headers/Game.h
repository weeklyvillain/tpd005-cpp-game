#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "World.h"
#include "Player.h"
#include "Player_Behaviour.h"
#include "Platform.h"
#include "Platform_Behaviour.h"
#include "Level.h"
#include "Projectile.h"

/**
 * \brief Game som kör spelvärlden och har hand om main loopen.
 *
 * 
 */

class Game{
public:
    Game() = default;
    ~Game() = default;
    int run(int);
};
