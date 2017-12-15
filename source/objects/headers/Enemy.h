#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity{
public:
    Enemy(std::string, std::string, Behaviour*, float, float, sf::Texture, sf::IntRect);
    void update(World&, sf::Time const&) override;
    void kill(World&) override;

private:
    sf::Texture texture{};
};

#endif
