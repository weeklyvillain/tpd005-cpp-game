#pragma once

#include "Entity.h"

/**
 * \brief Platform ärver från Entity och innehåller all information för en entitet av platformstyp.
 *
 * 
 */

class Platform: public Entity{
public:
    Platform(std::string, std::string, Behaviour*, sf::Vector2f, sf::Texture const&, sf::IntRect);
    void update(World&, sf::Time const&) override;
    void kill(World& w) override;

private:
    sf::Texture texture{};
};
