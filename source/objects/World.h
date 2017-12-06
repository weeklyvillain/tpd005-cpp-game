#pragma once

#include "tool_chain.h"
#include "Key_Handling.h"
#include "Entity.h"


class World{
    public:
        World(sf::RenderWindow&, float);
        ~World();

        void add_entity(Entity*);
        void update_all();
        void render_all();
        void on_Key_Press(sf::Keyboard::Key);
        void on_Key_Release(sf::Keyboard::Key);
        bool am_I_Colliding(Entity const&) const;
        void kill_me_now(Entity const&);

        Key_Handling player1{};
        bool run{true};

    private:
        sf::RenderWindow& window;
        float gravity;
        std::vector<std::unique_ptr<Entity>> entities;

};
