#pragma once

#include "tool_chain.h"
class Entity;
class World;


class Behaviour {
public:
    Behaviour() = default;
	virtual ~Behaviour() {}
    virtual bool process(World &, Entity&, sf::Time const&) = 0;
    sf::Vector2f acceleration {0.0f, 0.1f};
    bool falling{true};
    sf::Vector2f velocity{0.0f,0.0f};
};
