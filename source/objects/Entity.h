#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Behaviour.h"
#include "World.h"


class Entity : public sf::Sprite{
public:
    Entity(std::string n, Behaviour* b) : sf::Sprite(), name{n}, behaviour_ptr{b}, killed{false}{}
    virtual ~Entity() = default;
    virtual bool update(World&) = 0;
    std::string get_name()const{return name;}
    
protected:
    std::string name;
    Ptr<Behaviour> behaviour_ptr;
    bool killed;

};
