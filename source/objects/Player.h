#ifndef PLAYER_H
#define PLAYER_H

#include "World.h"
#include "Entity.h"



class Player : public Entity{
public:
    Player(Behaviour* b):Entity(b), idle_state{0}{
            texture.loadFromFile("../assets/wizard_idle.png");
            this->setTexture(texture);
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