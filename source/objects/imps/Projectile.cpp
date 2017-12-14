#include "../headers/Projectile.h"

Projectile::Projectile(std::string n, std::string t, Behaviour* b, float x, float y):Entity(n, t, b), idle_state{0}{
        texture.loadFromFile("assets/projectile.png");
        this->setTexture(texture);
        this->setPosition(x, y);
        this->setOrigin(8.0f, 8.0f);
        this->setTextureRect(sf::IntRect(0, 0, 16, 16));
}
    
void Projectile::update(World& w, sf::Time const& t){
    behaviour_ptr->process(w, *this, t);
}

void Projectile::kill(World& w){
    w.kill_me_now(*this);
}