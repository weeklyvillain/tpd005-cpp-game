#include "../headers/Player.h"

Player::Player(std::string n, std::string t,
    Behaviour* b, float x, float y, sf::Texture const& texture,
    sf::IntRect size, sf::Color c)
    :Entity(n, t, b, texture, size){
        setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
        setPosition(x, y);
        setColor(c);

    }
void Player::update(World& world, sf::Time const& t){
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
