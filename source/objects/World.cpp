#include "World.h"
#include <iostream>

World::World(sf::RenderWindow &w, float g)
    :window(w), gravity{g}, entities{}{}

World::~World() = default;

void World::add_entity(Entity* e){
    entities.push_back(Ptr<Entity>{e});
}

void World::add_entity(Ptr<Entity> e){
    entities.push_back(e);
}

void World::update_all(){
    for(Ptr<Entity> it : entities){
        it->update(*this);
    }
}

void World::render_all(){
    for(Ptr<Entity> it : entities){
        window.draw(*it);
    }
}

void World::on_Key_Press(sf::Keyboard::Key k){
    player1.onKey(true, k);
}

void World::on_Key_Release(sf::Keyboard::Key k){
    player1.onKey(false, k);
}