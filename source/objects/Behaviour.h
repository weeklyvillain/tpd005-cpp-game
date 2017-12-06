#pragma once

#include "tool_chain.h"
class Entity;
class World;


class Behaviour {
public:
    Behaviour() = default;
	virtual ~Behaviour() {}
    virtual bool process(World &world, Entity &owner) = 0;
    sf::Vector2f acceleration {0.0f, 2.1f};
    bool falling{true};
    sf::Vector2f velocity{0.0f,0.0f};
};
