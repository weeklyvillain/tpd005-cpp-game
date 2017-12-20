#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>
#include "World.h"
#include "Player.h"
#include "Player_Behaviour.h"
#include "Platform.h"
#include "Platform_Behaviour.h"
#include "Level.h"
#include "Projectile.h"
#include <iostream>
#include <fstream>
#include <utility>



/**
 * \brief Game som kör spelvärlden och har hand om main loopen.
 *
 * Game hanterar main loopen i sin Game#run() och skapar där World objektet och Level Objektet.
 * Sedan håller den koll på när Key_Handling ska få knapptryckningar, när allt ska uppdateras genom
 * World#update_all() och när allt ska ritas ut med World#render_all() och sfml sf::RenderWindow.display().
 * Den skapar också dödsskärmen och skriver in high score efter att spelaren har dött.
 * 
 */

class Game{
public:
    ///Default konstruktor
    Game() = default;
    //////Default destruktor
    ~Game() = default;
    ///Funktionen som kör själva spelet.
    int run(int);
    ///Filip fixar
    void run_lan(int);
    ///Filip fixar
    void join(std::string);
    ///Sätter spelarens namn
    void set_name(std::string);
    ///Skriver spelarens score till en .txt fil.
    void set_score(World&);
    ///Funktion som ritar ut ett objekt på spelplanen som inte är en del av spelet.
    ///T.ex. antal liv, score och pausskärmen.
    void draw_new_item(std::string const&, sf::Vector2f const&, sf::Font const&, sf::RenderWindow&);
    ///Filip fixar
    sf::TcpSocket socket;
private:
    ///Variabel för spelarens namn.
    std::string name{"   "};
};
