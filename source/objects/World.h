#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Key_Handling.h"
#include "Entity.h"

template <class T>
using Ptr = std::shared_ptr<T>;

class World{
    public:
        World(sf::RenderWindow&, float);
        ~World();

        void add_entity(Entity*);
        void add_entity(Ptr<Entity>);
        void update_all();
        void render_all();
        void on_Key_Press(sf::Keyboard::Key);
        void on_Key_Release(sf::Keyboard::Key);
        bool am_I_Colliding(Entity const&) const;
        void print_all();

        Key_Handling player1{};
        bool run{true};
    
    private:
        sf::RenderWindow& window;
        float gravity;
        std::vector<Ptr<Entity>> entities;

};


