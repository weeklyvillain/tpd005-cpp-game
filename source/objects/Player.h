#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"



class Player : public Entity{
public:
    Player(std::string n, Behaviour* b):Entity(n, b), idle_state{0}{
            texture.loadFromFile("../assets/wizard_idle.png");
            this->setTexture(texture);
            this->setOrigin(40.0f,40.0f);
            this->setTextureRect(sf::IntRect(0, 0, 80, 80));
            this->setPosition(900, 450);
        }

        bool update(World& w) override {
            killed = behaviour_ptr->process(w, *this);
            return killed;
        }

private:
    sf::Texture texture{};
    int idle_state{0};

};

#endif