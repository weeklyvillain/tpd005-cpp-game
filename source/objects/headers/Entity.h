#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Behaviour.h"
#include "World.h"


class Entity : public sf::Sprite{
public:
    Entity(std::string n, std::string t, Behaviour* b,
        sf::Texture const& texture, sf::IntRect size, World& w)
        :sf::Sprite(texture, size), name{n}, type{t}, behaviour_ptr{b}, world{w}{}
    virtual ~Entity() = default;
    virtual void update(sf::Time const&) = 0;
    virtual void kill(World&) = 0;
    std::string get_name()const{return name;}
    std::string get_type()const{return type;}

protected:
    std::string name;
    std::string type;
    std::unique_ptr<Behaviour> behaviour_ptr;
    World& world;
};