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
#include <iostream>
#include <fstream>
#include <utility>




class Game{
public:
    Game() = default;
    ~Game() = default;
    int run(int);
    void set_name(std::string);
    void set_score(World&);
private:
    std::string name{"hejj"};
};
