#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity{

public:
    Player(std::string n, std::string t, Behaviour* b, float x, float y):Entity(n, t, b), idle_state{0}{
            texture.loadFromFile("../assets/wizard_idle.png");
            this->setTexture(texture);
            this->setPosition(x, y);
            this->setOrigin(40.0f, 40.0f);
            this->setTextureRect(sf::IntRect(0, 0, 79, 79));

        }
        void update(World& w, sf::Time const& t) override {
            behaviour_ptr->process(w, *this, t);
        }
        void kill(World& w) override{
            w.kill_me_now(*this);
        }
        
        float time_since_last_shot{0};

private:
    sf::Texture texture{};
    int idle_state{0};

};

#endif
