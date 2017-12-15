#pragma once

#include "Entity.h"

class Platform: public Entity{
public:
    Platform(std::string, std::string, Behaviour*, sf::Vector2f, sf::Texture const&, sf::IntRect);
    void update(World& w, sf::Time const& t) override;
    void kill(World& w) override;

private:
    sf::Texture texture{};
};
