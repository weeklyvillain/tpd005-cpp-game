#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <fstream>
#include "Platform.h"
#include "Platform_Behaviour.h"
#include "Player_Behaviour.h"
#include "Enemy_Behaviour.h"
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

private:
    ///En input file stream för att kunna läsa från en fil.
    std::ifstream ifs;
    //Variabler för att spara undan bredd och höjd.
    int tile_width;
    int tile_height;
    //Vilken position vi just nu arbetar på.
    sf::Vector2f pos;

};

#endif
