#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite{
public:
    Entity():sf::Sprite(), killed{}{}
    virtual ~Entity() = default;
    virtual bool update() = 0;

protected:
    bool killed{false};
};

#endif