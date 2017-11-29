#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Entity.h"
#include "Key_Handling.h"

template <class T>
using Ptr = std::shared_ptr<T>;

class World{
    public:
        World(sf::RenderWindow&, float);
        ~World();

        void add_entity(Entity*);
        void add_entity(Ptr<Entity>);
        void update_all();
        void on_Key_Press(sf::Keyboard::Key);
        void on_Key_Release(sf::Keyboard::Key);

    
        bool run{true};
    
    private:
        Key_Handling player{};
        sf::RenderWindow& window;
        float gravity;
        std::vector<Ptr<Entity>> entities;

};
#endif

