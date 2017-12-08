#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity{
public:
    Player(std::string n, Behaviour* b, float x, float y):Entity(n, b), idle_state{0}{
            texture.loadFromFile("../assets/wizard_idle.png");
            this->setTexture(texture);
            this->setPosition(x, y);
            this->setOrigin(40.0f, 40.0f);
            this->setTextureRect(sf::IntRect(0, 0, 79, 79));

        }

        bool update(World& w, Entity& e) override {
            killed = behaviour_ptr->process(w, e);
            
            return killed;
        }

private:
    sf::Texture texture{};
    int idle_state{0};

};

#endif
