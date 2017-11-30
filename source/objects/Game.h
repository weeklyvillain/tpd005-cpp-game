#pragma once

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Player.h"
#include "Player1_Behaviour.h"


class Game{
public:
    Game() = default;
    ~Game() = default;
    int run();
};

