#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

/**
 * \brief Player ärver från Entity och innehåller all information för en entitet av spelartyp.
 *
 * 
 */

class Player : public Entity{
public:
    Player(std::string, std::string, Behaviour*, float, float, sf::Texture const&, sf::IntRect, sf::Color);
        void update(World&, sf::Time const&) override;
        void kill(World&) override;

        float time_since_last_shot{0};

private:
    sf::Texture texture{};
    int idle_state{0};

};

#endif
