#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"
class World;


class Entity : public sf::Sprite{
public:
    Entity(Behaviour* b) : sf::Sprite(),behaviour_ptr{b}, killed{}{}
    virtual ~Entity() = default;
    virtual bool update(World&) = 0;

protected:
    Ptr<Behaviour> behaviour_ptr;
    bool killed{false};
};

