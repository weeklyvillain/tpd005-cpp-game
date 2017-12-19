#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"

/**
 * \brief Projectile_Behaviour ärver från Behaviour och tillhandahåller beteendet för projektiler.
 *
 * Projectile_Behaviour ger projektiler deras beteende. Den gör så att projektilen åker ifrån spelaren 
 * i den riktining som spelaren tittar. Projektilen åker sedan tills den kolliderar med ett objekt 
 * som inte är en projektil eller en spelare. Den dödar objektet om det är en Enemy.
 * 
 */

class Projectile_Behaviour : public Behaviour {
public:
	///En konstruktor som tar emot vilket håll projektilen ska åka åt och 
	/// var den startar.
	Projectile_Behaviour(float, float);
	///Process som låter projektilen flyga iväg, kollidera med fiender och väggar.
	void process(World&, Entity&, sf::Time const&) override;

private:
	///Variabel som håller koll på vilket håll projektilen ska flyga åt.
	float direction{};
	///Variabel som sparar undan var projektilen startade ifrån.
	float init_pos{};
};
