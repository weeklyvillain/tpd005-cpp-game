#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Behaviour.h"
#include "World.h"

/**
 * \brief Entity ärver från sf::Sprite och är grundklassen för alla entiteter i spelvärlden.
 *
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
    ///Copy konstruktor
    Entity(Entity const & other) = delete;
    ///Move konstruktor
    Entity(Entity && other) = delete;
    ///Copy operator
    Entity& operator=(Entity const & rhs) & = delete;
    ///Move operator
	Entity& operator=(Entity && rhs) = delete;
    ///Default destruktor.
    virtual ~Entity() = default;
    ///Funktionen som world kallar på för att få varje entitet att uppdatera sig.
    /// Den kallar i sin tur på Behaviour#Process()
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
