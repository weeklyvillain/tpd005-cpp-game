#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <fstream>
#include "Platform.h"
#include "Platform_Behaviour.h"
#include "Player_Behaviour.h"
#include "Enemy_Behaviour.h"
#include "Enemy2_Behaviour.h"
#include "Enemy.h"
#include "Player.h"
#include "World.h"

/**
 * \brief Level läser in från .lvl filer och skapar entiteter till World.
 *
 * Level läser in en fil som har skapats specifikt för det här projektet.
 * Den innehåller information om hur spelvärlden ska se ut, var fiender ska finnas och var spelaren ska starta.
 * Den skapar sedan dessa entititer och lägger till dem i World.entities.
 *
 */

class Level {
public:
    ///Allting händer här i konstruktorn.
    /// Konstruktorn tar in en sökväg, bredd och höjd på varje tile,
    /// en värld som den ska skriva till och antalet spelare i världen.
    Level(std::string, int, int, World&, int);
    ///Copy konstruktor
    Level(Level const & other) = delete;
    ///Move konstruktor
    Level(Level && other) = delete;
    ///Copy operator
    Level& operator=(Level const & rhs) & = delete;
    ///Move operator
	Level& operator=(Level && rhs) = delete;
    ///Default destruktor
    ~Level() = default;

private:
    ///En input file stream för att kunna läsa från en fil.
    std::ifstream ifs;
    ///Variabel för att spara undan bredd
    int tile_width;
    ///Variabel för att spara undan höjd
    int tile_height;
    ///Vilken position vi just nu arbetar på.
    sf::Vector2f pos;
};

#endif
