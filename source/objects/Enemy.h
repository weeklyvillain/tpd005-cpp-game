#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity{
public:
    Enemy(std::string n, Behaviour* b, float x, float y):Entity(n, b) {
            texture.loadFromFile("../assets/wizard_idle.png");
            this->setTexture(texture);
            this->setPosition(x, y);
            this->setOrigin(40.0f,40.0f);
            this->setTextureRect(sf::IntRect(0, 0, 80, 80));

        }

        bool update(World& w, sf::Time const& t) override {
            killed = behaviour_ptr->process(w, *this, t);

            return killed;
        }

private:
    sf::Texture texture{};

};

#endif
