#include "../headers/Level.h"
#include <iostream>

Level::Level(std::string filename, int w, int h, World & world): ifs{filename}, tile_width{w}, tile_height{h}, pos{w / 2.0f, h / 2.0f} {
    if(ifs.is_open()) {
        for( std::string line; getline( ifs, line ); )
        {
            for_each(begin(line), end(line), [&](char c){
                std::cout << c;
                if(c == 'p'){
                    world.add_entity(new Platform("Platform", "Platform",
                        new Platform_Behaviour(), pos, world.get_texture("platform"),
                        sf::IntRect(0,238,80,80)));
                } else if(c == '1'){
                    world.add_entity(new Player("Player1", "Player",
                        new Player1_Behaviour(), pos.x, pos.y, world.get_texture("wizard_idle"),
                        sf::IntRect(0,0,80,80)));

                } else if(c == 'e'){
                    world.add_entity(new Enemy("Enemy", "Enemy",
                        new Enemy_Behaviour(), pos.x, pos.y, world.get_texture("enemy"),
                        sf::IntRect(0,0,80,80)));
                } else if(c == 'w') {
                    world.add_entity(new Platform("Wall", "Platform",
                        new Platform_Behaviour(), pos, world.get_texture("platform"),
                        sf::IntRect(0,238,80,80)));
                } else if(c == 'r') {
                    world.add_entity(new Platform("Roof", "Platform",
                        new Platform_Behaviour(), pos, world.get_texture("platform"),
                        sf::IntRect(0,238,80,80)));
                }
                pos.x += tile_width;
            });
            pos.x = tile_width / 2;
            pos.y +=tile_height;
        }
    }
}
