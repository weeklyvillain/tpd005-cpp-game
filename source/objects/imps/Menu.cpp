#include "../headers/Menu.h"


Menu::Menu(float width, float height) : item_width{width}, item_height{height}, menu_depth{0}, selectedItemIndex{0}, font{}{
	if (!font.loadFromFile("assets/Font.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	sf::FloatRect item = menu[0].getGlobalBounds();
	menu[0].setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), item_height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Options");
	item = menu[1].getGlobalBounds();
	menu[1].setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), item_height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	item = menu[2].getGlobalBounds();
	menu[2].setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), item_height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
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


	if(key == sf::Keyboard::Return ){
		if (menu_depth == 0){
			switch (GetPressedItem()){
				case 0:{
					menu[0].setFont(font);
					menu[0].setColor(sf::Color::Red);
					menu[0].setString("Singeplayer");
					sf::FloatRect item = menu[0].getGlobalBounds();
					menu[0].setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), item_height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

					menu[1].setFont(font);
					menu[1].setColor(sf::Color::White);
					menu[1].setString("Multiplayer");
					item = menu[1].getGlobalBounds();
					menu[1].setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), item_height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

					menu[2].setFont(font);
					menu[2].setColor(sf::Color::White);
					menu[2].setString("Back");
					item = menu[2].getGlobalBounds();
					menu[2].setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), item_height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

					selectedItemIndex = 0;
					menu_depth = 1;
					break;
				}
				case 1:{
					{
						read_score(w);
					}
					break;
				}
				case 2:{
					w.close();
					break;
				}
			}
		}else if(menu_depth == 1){
			switch (GetPressedItem()){
				case 0:{
					game.run(1);
					w.close();
					break;
				}
				case 1:{
					game.run(2);
					w.close();
					break;
				}
				case 2:{
					menu[0].setFont(font);
					menu[0].setColor(sf::Color::Red);
					menu[0].setString("Play");
					sf::FloatRect item = menu[0].getGlobalBounds();
					menu[0].setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), item_height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

					menu[1].setFont(font);
					menu[1].setColor(sf::Color::White);
					menu[1].setString("Options");
					item = menu[1].getGlobalBounds();
					menu[1].setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), item_height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

					menu[2].setFont(font);
					menu[2].setColor(sf::Color::White);
					menu[2].setString("Exit");
					item = menu[2].getGlobalBounds();
					menu[2].setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), item_height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
					selectedItemIndex = 0;
					menu_depth = 0;
					break;
				}
			}
		}else if(menu_depth == 3){

		}
	}
}

void Menu::read_score(sf::RenderWindow &window) {
	std::ifstream ifs{"assets/score"};
	std::vector<sf::Text> text;
	if(ifs.is_open()) {
        for( std::string line; getline( ifs, line ); )
        {
            text.push_back(sf::Text{line, font});
			std::cout << line << '\n';
        }
    }
    ifs.close();
	for(int i = 0; i < text.size(); i++){
		text[i].setColor(sf::Color::Red);
		sf::FloatRect item = text[i].getGlobalBounds();
		text[i].setPosition(sf::Vector2f(900, 100 * i));
		window.draw(text[i]);
	}
}
