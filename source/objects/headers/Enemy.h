#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Drop.h"
#include "Drop_Behaviour_heart.h"
#include "Drop_Behaviour_points.h"
#include <random>

/**
 * \brief Enemy ärver från Entity och innehåller all information för en entitet av fiendetyp.
 *
 * 
 */

class Enemy : public Entity{
public:
    Enemy(std::string, std::string, Behaviour*, float, float, sf::Texture const&, sf::IntRect);
    void update(World&, sf::Time const&) override;
    void kill(World&) override;

private:
    sf::Texture texture{};
};

#endif
