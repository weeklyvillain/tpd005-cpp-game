#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Key_Handling.h"
#include "Entity.h"
#include "Texture_Container.h"

/**
 * \brief World simulerar spelvärlden.
 *
 * 
 */


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
        void clear();
        bool win();
        int get_lives();
        void add_life();
        void remove_life();
        unsigned int get_score();
        void add_score(unsigned int);
        void remove_score(unsigned int);

        sf::Texture const& get_texture(std::string name)const{return texture_list.get_texture(name);}
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
        unsigned int score{0};
        Texture_Container texture_list{};

};
