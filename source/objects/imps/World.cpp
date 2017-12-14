#include "../headers/World.h"

World::World(sf::RenderWindow &w, float g)
    :window(w), gravity{g}, entities{}{}


void World::add_entity(Entity* e){
    entities.push_back(std::unique_ptr<Entity>{e});
}


void World::update_all(sf::Time const& t){
    for(auto& it : entities){
        if (it != nullptr){
            it.get()->update(*this, t);
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


Entity* World::am_I_Colliding(Entity const& e) const{
    for(auto& it : entities){
        if (&e != it.get()) {
            sf::FloatRect bounding_box = e.getGlobalBounds();
            sf::FloatRect other_box = it->getGlobalBounds();
            if(bounding_box.intersects(other_box)){
                return it.get();
            }
        }
    }
    return nullptr;
}

void World::kill_me_now(Entity& e){
    for (size_t indx{0}; indx < entities.size(); indx++){
        if(entities.at(indx).get() != nullptr && entities.at(indx).get() == &e){
            entities.erase(entities.begin()+indx);
            break;
        }
    }
}

Entity* World::get_player() const{
    for(auto& it : entities){
        if(it->get_name() == "Player1"){
            return it.get();

        }
    }
    return nullptr;
}
