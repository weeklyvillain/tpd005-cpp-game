#include "../headers/Level.h"

Level::Level(std::string filename, int w, int h, World & world, int player_amount):
    ifs{filename}, tile_width{w}, tile_height{h}, pos{w / 2.0f, h / 2.0f} {
    if(ifs.is_open()) {
        for( std::string line; getline( ifs, line ); ){
            for_each(begin(line), end(line), [&](char c){
                if(c == 'p'){
                    world.add_entity(new Platform("Platform", "Platform",
                        new Platform_Behaviour(), pos,
                        world.get_texture("platform"),
                        sf::IntRect(0,238,80,80)));
                } else if(c == '1'){
                    world.add_entity(new Player("Player1", "Player",
                        new Player_Behaviour(world.player1), pos.x, pos.y,
                        world.get_texture("wizard_idle"),
                        sf::IntRect(0,0,80,80), sf::Color::White));
                } else if (c == '2') {
                    if(player_amount == 2){
                        world.add_entity(new Player("Player2", "Player",
                            new Player_Behaviour(world.player2), pos.x, pos.y,
                            world.get_texture("wizard_idle"),
                            sf::IntRect(0,0,80,80), sf::Color::Blue));
                    }
                } else if(c == 'e'){
                    world.add_entity(new Enemy("Enemy", "Enemy",
                        new Enemy_Behaviour(), pos.x, pos.y,
                        world.get_texture("enemy"),
                        sf::IntRect(0,0,80,80)));
                }else if(c == 'f'){
                    world.add_entity(new Enemy("Enemy", "Enemy",
                        new Enemy2_Behaviour(pos, pos.x + 100, pos.y),
                        pos.x, pos.y, world.get_texture("enemy2"),
                        sf::IntRect(0,0,80,80)));
                } else if(c == 'w') {
                    world.add_entity(new Platform("Wall", "Wall",
                        new Platform_Behaviour(), pos,
                        world.get_texture("platform"),
                        sf::IntRect(0,238,80,80)));
                } else if(c == 'r') {
                    world.add_entity(new Platform("Roof", "Roof",
                        new Platform_Behaviour(), pos,
                        world.get_texture("platform"),
                        sf::IntRect(0,238,80,80)));
                }
                pos.x += tile_width;
            });
            pos.x = tile_width / 2;
            pos.y +=tile_height;
        }
    }
    ifs.close();
}
