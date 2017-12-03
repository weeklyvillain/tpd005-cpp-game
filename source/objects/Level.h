#ifndef LEVEL_H
#define LEVEL_H

#include "Platform.h"
#include "Platform_Behaviour.h"
#include <vector>
#include <fstream>
#include <iostream>

class Level {
public:
    std::vector<Platform*> platforms{};
    Level(std::string filename, int w, int h): ifs{filename}, tile_width{w}, tile_height{h} {
        if(ifs.is_open()) {
            for( std::string line; getline( ifs, line ); )
            {
                for_each(begin(line), end(line), [&](char c){
                    if(c == 'x'){
                        platforms.push_back(new Platform("Platform", new Platform_Behaviour(), pos));

                    }
                    pos.x += tile_width;

                });
                pos.x = 0;
                pos.y +=tile_height;
            }
        }
    }


private:
    std::ifstream ifs;
    int tile_width;
    int tile_height;
    sf::Vector2f pos{0.0f,0.0f};

};

#endif
