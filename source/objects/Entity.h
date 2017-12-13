#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Behaviour.h"
#include "World.h"


class Entity : public sf::Sprite{
public:
    Entity(std::string n, std::string t, Behaviour* b) : sf::Sprite(), name{n}, type{t}, behaviour_ptr{b}{}
    virtual ~Entity() = default;
    virtual void update(World&, sf::Time const&) = 0;
    virtual void kill(World&) = 0;
    std::string get_name()const{return name;}
    std::string get_type()const{return type;}

    float time_since_last_shot{0};
protected:
    std::string name;
    std::string type;
    std::unique_ptr<Behaviour> behaviour_ptr;
    
};
