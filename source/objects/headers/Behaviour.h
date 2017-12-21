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
    ///Copy konstruktor
    Behaviour(Behaviour const & other) = delete;
    ///Move konstruktor
    Behaviour(Behaviour && other) = delete;
    ///Copy operator
    Behaviour& operator=(Behaviour const & rhs) & = delete;
    ///Move operator
    Behaviour& operator=(Behaviour && rhs) = delete;
    ///Virtuell destruktor.
    virtual ~Behaviour() = default;
    ///Virtuell funktion där själva beteendet händer.
    /// Tar in spelvärlden, ägaren till beteendet och tiden sen senaste uppdateringen.
    virtual void process(World &, Entity&, sf::Time const&) = 0;

protected:
    ///Variabel för gravitation.
    sf::Vector2f acceleration {0.0f, 0.1f};
    ///Variabel for hastigheten för entiteten.
    sf::Vector2f velocity{0.0f,0.0f};
};
