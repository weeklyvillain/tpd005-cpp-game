#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Entity.h"


class Player : public Entity{
public:
    Player():Entity(), idle_state{0}{
            texture.loadFromFile("../assets/wizard_idle.png");
            this->setTexture(texture);
            this->setTextureRect(sf::IntRect(0, 0, 80, 80));
        }

        virtual bool update() override {
        
            return killed;
        }


private:
    sf::Texture texture{};
    int idle_state{0};

};

#endif