#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Behaviour.h"
#include "World.h"

/**
 * \brief Entity ärver från sf::Sprite och är grundklassen för alla entiteter i spelvärlden.
 *
 * 
 */

class Entity : public sf::Sprite{
public:
    ///Entitys konstruktor baseras på sf::Sprites men tar också in ett namn, en typ, en pekare till behaviour
    ///, en textur och en storlek på texturen.
    Entity(std::string n, std::string t, Behaviour* b,
        sf::Texture const& texture, sf::IntRect size)
        :sf::Sprite(texture, size), name{n}, type{t}, behaviour_ptr{b}{}
    ///Default konstruktor.
    virtual ~Entity() = default;
    ///Funktionen som world kallar på för att få varje entitet att uppdatera sig.
    virtual void update(World&, sf::Time const&) = 0;
    ///Om entiteten ska dö så signalerar denna funktion det till world.
    virtual void kill(World&) = 0;
    ///Returnerar namnet på entititen.
    std::string get_name()const{return name;}
    ///Returnerar typen på entititen.
    std::string get_type()const{return type;}

protected:
    ///Namn
    std::string name;
    ///Typ
    std::string type;
    ///Unik smart-pekare till ett objekt av Behaviour klassen.
    std::unique_ptr<Behaviour> behaviour_ptr;
};
