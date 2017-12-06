#include "World.h"
#include <iostream>

World::World(sf::RenderWindow &w, float g)
    :window(w), gravity{g}, entities{}{}

World::~World(){
    entities.erase(entities.begin(), entities.end());
}

void World::add_entity(Entity* e){
    entities.push_back(std::unique_ptr<Entity>{e});
}

void World::update_all(){
    for(auto& it : entities){
        if (it != nullptr){
            it->update(*this);
        }
    }
}

void World::render_all(){
    for(auto& it : entities){
        if (it != nullptr){
            window.draw(*it);
        }

    }
}

void World::on_Key_Press(sf::Keyboard::Key k){
    player1.onKey(true, k);
}

void World::on_Key_Release(sf::Keyboard::Key k){
    player1.onKey(false, k);
}

bool World::am_I_Colliding(Entity const& e) const{
    for(auto& it : entities){
        if(it->get_name() != e.get_name() && it->get_name() != "proj"){
            sf::FloatRect bounding_box = e.getGlobalBounds();
            sf::FloatRect other_box = it->getGlobalBounds();
            if(bounding_box.intersects(other_box)){
                return true;
            }
        }
    }
    return false;
}

void World::kill_me_now(Entity const& e){
    for (size_t indx{0}; indx < entities.size(); indx++){
        if(entities.at(indx)->get_name() == e.get_name()){
            entities.erase(entities.begin()+indx);
            break;
        }
    }
}
