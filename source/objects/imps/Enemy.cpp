#include "../headers/Enemy.h"

Enemy::Enemy(std::string n, std::string t,
    Behaviour* b, float x, float y, sf::Texture texture, sf::IntRect size)
    :Entity(n, t, b, texture, size) {
        setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
        setPosition(x, y);
    }

void Enemy::update(World& w, sf::Time const& t){
    behaviour_ptr->process(w, *this, t);
}

void Enemy::kill(World& w){
    w.kill_me_now(*this);
}