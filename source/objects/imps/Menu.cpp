#include "../headers/Menu.h"


Menu::Menu(float width, float height) : selectedItemIndex{0}, font{}
{
	if (!font.loadFromFile("../assets/Font.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	sf::FloatRect item = menu[0].getGlobalBounds();
	menu[0].setPosition(sf::Vector2f((width / 2) - (item.width / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Options");
	item = menu[1].getGlobalBounds();
	menu[1].setPosition(sf::Vector2f((width / 2) - (item.width / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	item = menu[2].getGlobalBounds();
	menu[2].setPosition(sf::Vector2f((width / 2) - (item.width / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	} else {
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex = 2;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	} else {
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex = 0;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}
void Menu::onKey(sf::Keyboard::Key const& key, sf::RenderWindow & w) {
	if(key == sf::Keyboard::Up){
		MoveUp();
	}
	if(key == sf::Keyboard::Down){
		MoveDown();
	}


	if(key == sf::Keyboard::Return){
		switch (GetPressedItem())
		{
		case 0:
			w.close();
			game.run();
			break;
		case 1:
			std::cout << "Option button has been pressed" << std::endl;
			break;
		case 2:
			w.close();
			break;
		}
	}
}
