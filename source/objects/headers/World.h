#pragma once

#include "tool_chain.h"
#include "Key_Handling.h"
#include "Entity.h"
#include "Texture_Container.h"

class World{
    public:
        World(sf::RenderWindow&, float);
        ~World() = default;

        void add_entity(Entity*);
        void update_all(sf::Time const&);
        void render_all();
        void on_Key_Press(sf::Keyboard::Key);
        void on_Key_Release(sf::Keyboard::Key);
        Entity* am_I_Colliding(Entity const&) const;
        void kill_me_now(Entity&);
        Entity* get_player() const;

        int get_lives();
        void add_life();
        void remove_life();

        sf::Texture get_texture(std::string name){return texture_list.get_texture(name);}
        Key_Handling player1{
            sf::Keyboard::Up, 
            sf::Keyboard::Left, 
            sf::Keyboard::Right, 
            sf::Keyboard::Space
        };
        
        Key_Handling player2{
            sf::Keyboard::W, 
            sf::Keyboard::A, 
            sf::Keyboard::D, 
            sf::Keyboard::F
        };
        bool run{true};

    private:
        sf::RenderWindow& window;
        float gravity;
        std::vector<std::unique_ptr<Entity>> entities;
        int lives{3};
        Texture_Container texture_list{};

};
