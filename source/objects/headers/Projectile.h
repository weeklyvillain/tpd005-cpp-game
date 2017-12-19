#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

/**
 * \brief Projectile ärver från Entity och innehåller all information för en entitet av projektil typ.
 *
 * 
 */

class Projectile : public Entity{
public:
    Projectile(std::string n, std::string t, Behaviour* b, float x, float y, sf::Texture const&, sf::IntRect);
    void update(World&, sf::Time const& t) override;
    void kill(World& w) override;

private:
    sf::Texture texture{};
    int idle_state{0};

};

#endif
