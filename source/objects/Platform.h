#pragma once

#include "Entity.h"

class Platform: public Entity{
public:
    Platform(std::string n, Behaviour* b, sf::Vector2f pos):Entity(n, b){
            texture.loadFromFile("../assets/Art_Tileset.png");
            this->setTexture(texture);
            this->setOrigin(40.0f, 40.0f);
            this->setTextureRect(sf::IntRect(0, 238, 80, 80));
            this->setPosition(pos);
        }
        bool update(World& w, Entity& e) override {
            killed = behaviour_ptr->process(w, e);
            return killed;
        }

private:
    sf::Texture texture{};
};
