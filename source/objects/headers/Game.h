#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "World.h"
#include "Player.h"
#include "Player1_Behaviour.h"
#include "Platform.h"
#include "Platform_Behaviour.h"
#include "Level.h"
#include "Projectile.h"
#include <iostream>


class Game{
public:
    Game() = default;
    ~Game() = default;
    int run();
};
