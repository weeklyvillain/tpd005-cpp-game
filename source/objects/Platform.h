#pragma once

#include "Entity.h"

class Platform: public Entity{
public:
    Platform(std::string n, std::string t, Behaviour* b, sf::Vector2f pos):Entity(n, t, b){
            texture.loadFromFile("../assets/Art_Tileset.png");
            this->setTexture(texture);
            this->setOrigin(40.0f, 40.0f);
            this->setTextureRect(sf::IntRect(0, 238, 80, 80));
            this->setPosition(pos);
        }

        void update(World& w, sf::Time const& t) override {
            behaviour_ptr->process(w, *this, t);
        }

private:
    sf::Texture texture{};
};
