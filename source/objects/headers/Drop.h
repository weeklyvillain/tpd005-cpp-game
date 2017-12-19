#ifndef DROP_H
#define DROP_H

#include "Entity.h"

/**
 * \brief Drop ärver från Entity och innehåller all information för en entitet av droptyp.
 *
 * 
 */

class Drop : public Entity{
public:
    Drop(std::string, std::string, Behaviour*, float, float, sf::Texture const&, sf::IntRect);
    void update(World&, sf::Time const&) override;
    void kill(World&) override;

private:
    sf::Texture texture{};
};

#endif
