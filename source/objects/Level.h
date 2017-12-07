#ifndef LEVEL_H
#define LEVEL_H

#include "Platform.h"
#include "Platform_Behaviour.h"
#include "Player1_Behaviour.h"
#include "Enemy_Behaviour.h"
#include "Enemy.h"
#include "Player.h"
#include "World.h"
#include <vector>
#include <fstream>

class Level {
public:
    Level(std::string filename, int w, int h, World & world): ifs{filename}, tile_width{w}, tile_height{h}, pos{w / 2.0f, h / 2.0f} {
        if(ifs.is_open()) {
            for( std::string line; getline( ifs, line ); )
            {
                for_each(begin(line), end(line), [&](char c){
                    if(c == 'x'){
                        world.add_entity(new Platform("Platform",new Platform_Behaviour(), pos));
                    }
                    if(c == 'p'){
                        world.add_entity(new Player("Player1", new Player1_Behaviour(), pos.x, pos.y));
                    }
                    if(c == 'e'){
                        world.add_entity(new Enemy("Enemy", new Enemy_Behaviour(), pos.x, pos.y));
                    }
                    pos.x += tile_width;
                });
                pos.x = tile_width / 2;
                pos.y +=tile_height;
            }
        }
    }


private:
    std::ifstream ifs;
    int tile_width;
    int tile_height;
    sf::Vector2f pos;

};

#endif
