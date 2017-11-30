#pragma once

class World;
class Entity;
template <class T>
using Ptr = std::shared_ptr<T>;

class Behaviour {
public:
    Behaviour() = default;
	virtual ~Behaviour() {}
    virtual bool process(World &world, Entity &owner) = 0;
    sf::Vector2f gravity {0, 5};
    bool falling{false};
};
