#pragma once

#include "SFML/Graphics.hpp"
#include <fstream>
#include <vector>
#include "Game.h"

/**
 * \brief Menu har hand om menyer innan man börjar spela spelet.
 *
 * Menu skapar, ritar ut och hanterar input i de menyer spelet har innan spelet startar.
 * Det använder sig av std::string och sf::Text för att skapa
 * listor av val som användaren sedan kan välja med hjälp av
 * piltangenterna och enter.
 *
 */

class Menu{
public:
	///Konstruktor som tar in 2 floats.
	/// 1 för bredd och 1 för höjd på fönstret.
	Menu(float width, float height);
	///Copy konstruktor
    Menu(Menu const & other) = delete;
    ///Move konstruktor
    Menu(Menu && other) = delete;
    ///Copy operator
    Menu& operator=(Menu const & rhs) & = delete;
    ///Move operator
	Menu& operator=(Menu && rhs) = delete;
	///Default Destruktor
	~Menu() = default;

	///Ritar ut alla meny objekt.
	void draw(sf::RenderWindow &window);
	///Flyttar upp ett meny val men flyttar
	/// också till sista om selected index är det första.
	void MoveUp();
	///Flyttar ner ett meny val men flyttar
	/// också till första om selected index är det sista.
	void MoveDown();
	///Tar fram vilken del av menyn som tryckts på.
	int GetPressedItem() { return selectedItemIndex; }
	///Läser in high score från score filen.
	///Formaterar sedan dessa som meny val och låter menyn skriva ut dem.
	void read_score(sf::RenderWindow &window);
	///Tar hand om knapptryckningar i menyn.
	///Om man kommer till slutet av menyn och
	/// fortsätter så börjar man om i början av menyn.
	void onKey(sf::Keyboard::Key const& key, sf::RenderWindow &);
	///Lägger till ett nytt meny val. Tar in en sträng och
	/// formaterar den till en sf::Text.
	void add_option(std::string, float);

private:
	///Variabel för fönstrets bredd.
	float item_width;
	///Variabel för fönstrets höjd.
	float item_height;
	///Variabel för meny djupet. Detta för att kunna
	/// ha mer än 1 meny med flera olika beteenden.
	int menu_depth;
	///Variabel för vilken del av menyn som är vald.
	///Den highlightas och är också den som beteendet baseras på.
	int selectedItemIndex;
	///Variabel för att spara vilken font menyn ska ha.
	///Om man inte sparar den så försvinner den när den går ur scope.
	sf::Font font;
	///En std::vector som innehåller sf::Text objekt som representerar
	/// en del i menyn.
	std::vector<sf::Text> menu;
	///En instans av Game. Sparas så att den inte går utanför scope.
	Game game{};
	///Variabel som sparar din ip. Används för
	std::string ip;
};
