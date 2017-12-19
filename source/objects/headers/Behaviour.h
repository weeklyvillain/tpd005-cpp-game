#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Entity;
class World;

/**
 * \brief Behaviour ärver ej av någonting och används för att definiera hur ett objekt beter sig i spelvärlden.
 *
 * Behaviour är en abstrakt klass som innehåller grundfunktionerna för alla beteende klasser i projektet.
 * 
 */

class Behaviour {
public:
    ///Konstruktor som inte tar in något speciellt.
    Behaviour() = default;
    ///Virtuell destruktor.
    virtual ~Behaviour(){}
    ///Virtuell funktion där själva beteendet händer.
    /// Tar in spelvärlden, ägaren till beteendet och tiden sen senaste uppdateringen.
    virtual void process(World &, Entity&, sf::Time const&) = 0;
    ///Variabel för gravitation.
    sf::Vector2f acceleration {0.0f, 0.1f};
    ///Variabel for hastigheten för entiteten.
    sf::Vector2f velocity{0.0f,0.0f};
};
