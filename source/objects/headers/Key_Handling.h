#pragma once

#include <SFML/Graphics.hpp>

/**
 * \brief Key_Handling har hand om input från spelaren.
 *
 * Key_Handling är den klass som tar hand om tangenttryckningar.
 * Den gör detta genom att ta emot SFMLs Keyboard structs.
 * Den kollar vilka tangenter som tryckts ner och 
 * ändrar sedan Key_Handling#direction() för att visa vad som har tryckts ner.
 * Det går också att kolla direkt mot denna då den är publik om det är en knapp som inte har
 * med movement att göra t.ex. Key_Handling#shoot eller Key_Handling#quit.
 * 
 */

class Key_Handling {
public:
	///Variabel för hopp knappen.
	bool jump{false};
	///Variabel för vänster movement.
	bool left{false};
	///Variabel för höger movement.
	bool right{false};
	///Variabel för att skjuta.
	bool shoot{false};
	///Variabel för att avsluta spelet.
	bool quit{false};
	///Variabel för att pausa spelet.
	bool pause{false};
	///Variabel för vilken tangent som betyder hoppa.
	sf::Keyboard::Key jump_key{};
	///Variabel för vilken tangent som betyder vänster.
	sf::Keyboard::Key left_key{};
	///Variabel för vilken tangent som betyder höger.
	sf::Keyboard::Key right_key{};
	///Variabel för vilken tangent som betyder skjut.
	sf::Keyboard::Key shoot_key{};
	
	///Default konstruktor som skapar Key_Handling med fördefinierade tangenter.
	Key_Handling();
	///Konstruktor som tar emot 4 tangenter.
	Key_Handling(sf::Keyboard::Key, sf::Keyboard::Key, 
		sf::Keyboard::Key, sf::Keyboard::Key);
	///Funktion som körs från main-loopen. Den tar emot huruvida tangenten släpptes eller trycktes ner
	/// och vilken tangent det var som triggrade eventet.
	void onKey(bool, sf::Keyboard::Key const&);
	///En funktion som tillhandahåller en sf::Vector2f baserat på vilka knappar som trycks ner 
	/// när funktionen kallas på.
	sf::Vector2f direction() const;
};
