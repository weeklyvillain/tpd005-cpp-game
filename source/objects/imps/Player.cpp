#include "../headers/Player.h"

Player::Player(std::string n, std::string t,
    Behaviour* b, float x, float y, sf::Texture const& texture, sf::IntRect size, World& w)
    :Entity(n, t, b, texture, size, w), idle_state{0}{
        setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
        setPosition(x, y);

    }
void Player::update(sf::Time const& t){
    behaviour_ptr->process(world, *this, t);
}

void Player::kill(World& w){
    if(w.get_lives() > 0){
        w.remove_life();
        setPosition(800, 100);
    }else{
        w.kill_me_now(*this);
    }

}
