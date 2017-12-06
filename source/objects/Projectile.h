#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"


class Projectile : public Entity{
public:
    Projectile(std::string n, Behaviour* b, float x, float y):Entity(n, b), idle_state{0}{
            texture.loadFromFile("../assets/projectile.png");
            this->setTexture(texture);
            this->setPosition(x, y);
            this->setOrigin(8.0f, 8.0f);
            this->setTextureRect(sf::IntRect(0, 0, 16, 16));
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
