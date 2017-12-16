#ifndef DROP_H
#define DROP_H

#include "Entity.h"

class Drop : public Entity{
public:
    Drop(std::string, std::string, Behaviour*, float, float, sf::Texture const&, sf::IntRect, World&);
    void update(sf::Time const&) override;
    void kill(World&) override;

private:
    sf::Texture texture{};
};

#endif
