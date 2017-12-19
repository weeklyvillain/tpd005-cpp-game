#include "../headers/Projectile.h"

Projectile::Projectile(std::string n, std::string t,
    Behaviour* b, float x, float y, sf::Texture const& texture, sf::IntRect size)
    :Entity(n, t, b, texture, size), idle_state{0}{
    setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
    setPosition(x, y);

}

void Projectile::update(World& world, sf::Time const& t){
    behaviour_ptr->process(world, *this, t);
}

void Projectile::kill(World& w){
    w.kill_me_now(*this);
}
