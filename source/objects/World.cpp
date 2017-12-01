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

bool World::am_I_Colliding(Entity const& e) const{
    for(auto it : entities){
        if(it->get_name() != e.get_name()){ 
            sf::FloatRect bounding_box = e.getGlobalBounds();
            sf::FloatRect other_box = it->getGlobalBounds(); 
            if(bounding_box.intersects(other_box)){
                return true;
            }
        }
    }
    return false;
}

void World::print_all(){
    for(auto it: entities){
        std::cerr << it << std::endl;
    }
    std::cerr << std::endl;
}