#include "../headers/Player.h"

Player::Player(std::string n, std::string t, Behaviour* b, float x, float y):Entity(n, t, b), idle_state{0}{
        texture.loadFromFile("assets/wizard_idle.png");
        this->setTexture(texture);
        this->setPosition(x, y);
        this->setOrigin(40.0f, 40.0f);
        this->setTextureRect(sf::IntRect(0, 0, 79, 79));

    }
    void Player::update(World& w, sf::Time const& t){
        behaviour_ptr->process(w, *this, t);
    }
    void Player::kill(World& w){
        w.kill_me_now(*this);
    }