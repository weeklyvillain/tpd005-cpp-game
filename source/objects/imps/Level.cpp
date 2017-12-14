#include "../headers/Level.h"

Level::Level(std::string filename, int w, int h, World & world): ifs{filename}, tile_width{w}, tile_height{h}, pos{w / 2.0f, h / 2.0f} {
    if(ifs.is_open()) {
        for( std::string line; getline( ifs, line ); )
        {
            for_each(begin(line), end(line), [&](char c){
                if(c == 'x'){
                    world.add_entity(new Platform("Platform", "Platform", new Platform_Behaviour(), pos));
                }
                if(c == 'p'){
                    world.add_entity(new Player("Player1", "Player", new Player1_Behaviour(), pos.x, pos.y));
                }
                if(c == 'e'){
                    world.add_entity(new Enemy("Enemy", "Enemy" , new Enemy_Behaviour(), pos.x, pos.y));
                }
                pos.x += tile_width;
            });
            pos.x = tile_width / 2;
            pos.y +=tile_height;
        }
    }
}