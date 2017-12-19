#include "../headers/Platform.h"

Platform::Platform(std::string n, std::string t,
    Behaviour* b, sf::Vector2f pos,
    sf::Texture const& texture, sf::IntRect size)
    :Entity(n, t, b, texture, size){
        setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
        setPosition(pos);
    }

void Platform::update(World& world, sf::Time const& t){
    behaviour_ptr->process(world, *this, t);
}

void Platform::kill(World& w){
    w.kill_me_now(*this);
}
