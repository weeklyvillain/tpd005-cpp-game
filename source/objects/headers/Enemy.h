#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Drop.h"
#include "Drop_Behaviour_heart.h"
#include "Drop_Behaviour_points.h"
#include <random>

class Enemy : public Entity{
public:
    Enemy(std::string, std::string, Behaviour*, float, float, sf::Texture const&, sf::IntRect, World& w);
    void update(sf::Time const&) override;
    void kill(World&) override;

private:
    sf::Texture texture{};
};

#endif