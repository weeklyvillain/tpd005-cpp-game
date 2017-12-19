#pragma once

#include "tool_chain.h"
class Entity;
class World;


/**
 * Behaviour är en abstrakt klass som används för att definiera hur ett objekt beter sig i spelvärlden
 */

class Behaviour {
public:
    ///Konstruktor som inte tar in något speciellt
    Behaviour() = default;
    ///Virtual destruktor
    virtual ~Behaviour(){}
    ///Virtuell funktion där själva beteendet händer
    ///Tar in spelvärlden, ägaren till beteendet och tiden sen senaste uppdateringen
    virtual void process(World &, Entity&, sf::Time const&) = 0;
    ///Variabel för gravitation
    sf::Vector2f acceleration {0.0f, 0.1f};
    ///Variabel for hastigheten för entiteten
    sf::Vector2f velocity{0.0f,0.0f};
};
