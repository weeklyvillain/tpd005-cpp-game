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
            it->update(*this, *it);
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
bool World::ADVBoxCollision(sf::FloatRect const& FirstRect, sf::FloatRect const& SecondRect, bool& pTop, bool& pSide)const{
    bool Firsttotheleft = false;
    bool Firsttotheright = false;
    bool Firstabove = false;
    bool Firstbelow = false;
    //ToS stands for Top or side. It tells whether the sprite collided with the top/bottom part or the side part. 
    //0 = top/bottom, 1 = sides
    if(FirstRect.intersects(SecondRect)){
        if((FirstRect.left - 20) <= (SecondRect.left - FirstRect.width)){
            Firsttotheleft = true;            
        }
        if(((FirstRect.left + FirstRect.width) + 20) >= ((SecondRect.left + SecondRect.width) + FirstRect.width)){
            Firsttotheright = true;
        }
        if((FirstRect.top - 20) <= (SecondRect.top - FirstRect.height)){
            Firstabove = true;
        }
        if(((FirstRect.top + FirstRect.height) + 20) >= ((SecondRect.top + SecondRect.height) + FirstRect.height)){
            Firstbelow = true;
        }
        if(Firstbelow || Firstabove){
            pTop = true;
        }
        if(Firsttotheright || Firsttotheleft){
            pSide = true;
        }
        return FirstRect.intersects(SecondRect);
    }else{
        return false;
    } 
}


bool World::am_I_Colliding(Entity const& e, bool &p_top, bool &p_side) const{
    for(auto& it : entities){
        if(it->get_name() != e.get_name()){
            sf::FloatRect bounding_box = e.getGlobalBounds();
            sf::FloatRect other_box = it->getGlobalBounds();
            if (ADVBoxCollision(bounding_box, other_box, p_top, p_side)){
                return true;
            }
        }
    }
    return false;
}

void World::kill_me_now(Entity& e){
    for (size_t indx{0}; indx < entities.size(); indx++){
        if(entities.at(indx)->get_name() == e.get_name()){
            entities.erase(entities.begin()+indx);
            break;
        }
    }
}
