#include "../headers/Player.h"

Player::Player(std::string n, std::string t, 
    Behaviour* b, float x, float y, sf::Texture const& texture, sf::IntRect size)
    :Entity(n, t, b, texture, size), idle_state{0}{
        setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
        setPosition(x, y);

    }
void Player::update(World& w, sf::Time const& t){
    behaviour_ptr->process(w, *this, t);
}

void Player::kill(World& w){
    if(w.get_lives() > 0){
        w.remove_life();
        setPosition(800, 100);
    }else{
        w.kill_me_now(*this);
    }

}
