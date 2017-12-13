#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"


class Projectile : public Entity{
public:
    Projectile(std::string n, std::string t, Behaviour* b, float x, float y):Entity(n, t, b), idle_state{0}{
            texture.loadFromFile("../assets/projectile.png");
            this->setTexture(texture);
            this->setPosition(x, y);
            this->setOrigin(8.0f, 8.0f);
            this->setTextureRect(sf::IntRect(0, 0, 16, 16));
        }
        void update(World& w, sf::Time const& t) override {
            behaviour_ptr->process(w, *this, t);
        }

        void kill(World& w) override{
            w.kill_me_now(*this);
        }

private:
    sf::Texture texture{};
    int idle_state{0};

};

#endif
