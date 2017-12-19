#ifndef LEVEL_H
#define LEVEL_H

#include "Platform.h"
#include "Platform_Behaviour.h"
#include "Player_Behaviour.h"
#include "Enemy_Behaviour.h"
#include "Enemy.h"
#include "Player.h"
#include "World.h"
#include <vector>
#include <fstream>

class Level {
public:
    Level(std::string, int, int, World&, int);

private:
    std::ifstream ifs;
    int tile_width;
    int tile_height;
    sf::Vector2f pos;

};

#endif
