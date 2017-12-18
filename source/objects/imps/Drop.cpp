#include "../headers/Drop.h"

Drop::Drop(std::string n, std::string t,
    Behaviour* b, float x, float y, sf::Texture const& texture, sf::IntRect size, World& w)
    :Entity(n, t, b, texture, size, w){
        setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
        setPosition(x, y);

    }
void Drop::update(sf::Time const& t){
    behaviour_ptr->process(world, *this, t);
}

void Drop::kill(World& w){
    w.kill_me_now(*this);
}
