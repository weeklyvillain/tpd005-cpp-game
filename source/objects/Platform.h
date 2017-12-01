#pragma once

#include "Entity.h"

class Platform: public Entity{
public:    
    Platform(std::string n, Behaviour* b, sf::Vector2f pos):Entity(n, b){
            texture.loadFromFile("../assets/Art_Tileset.png");
            this->setTexture(texture);
            this->setOrigin(6.0f,6.0f);
            this->setTextureRect(sf::IntRect(0, 238, 12, 12));
            this->setPosition(pos);
        }
        bool update(World& w) override {
            killed = behaviour_ptr->process(w, *this);
            return killed;
        }

private:
    sf::Texture texture{};
};  