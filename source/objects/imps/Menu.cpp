#include "../headers/Menu.h"

Menu::Menu(float width, float height) : item_width{width}, item_height{height}, menu_depth{0}, selectedItemIndex{0}, font{}{
	font.loadFromFile("assets/ScoreFont.ttf");
	add_option("Play", 300);
	add_option("High Score", 400);
	add_option("Exit", 500);
	selectedItemIndex = 0;
	menu_depth = 0;
	menu.at(selectedItemIndex).setColor(sf::Color::White);
}

void Menu::draw(sf::RenderWindow &window){
	for (int i = 0; i < menu.size(); i++)
	{
		window.draw(menu.at(i));
	}
}

void Menu::MoveUp(){
	if (selectedItemIndex - 1 >= 0)
	{
		menu.at(selectedItemIndex).setColor(sf::Color::Red);
		selectedItemIndex--;
		menu.at(selectedItemIndex).setColor(sf::Color::White);
	} else {
		menu.at(selectedItemIndex).setColor(sf::Color::Red);
		selectedItemIndex = menu.size()-1;
		menu.at(selectedItemIndex).setColor(sf::Color::White);
	}
}

void Menu::MoveDown(){
	if (selectedItemIndex + 1 < menu.size()){
		menu.at(selectedItemIndex).setColor(sf::Color::Red);
		selectedItemIndex++;
		menu.at(selectedItemIndex).setColor(sf::Color::White);
	}else{
		menu.at(selectedItemIndex).setColor(sf::Color::Red);
		selectedItemIndex = 0;
		menu.at(selectedItemIndex).setColor(sf::Color::White);
	}
}

void Menu::onKey(sf::Keyboard::Key const& key, sf::RenderWindow & w){
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
					menu.erase(menu.begin(), menu.end());
					add_option("Singleplayer", 300);
					add_option("Multiplayer", 400);
					add_option("Back", 500);
					selectedItemIndex = 0;
					menu_depth = 1;
					menu.at(selectedItemIndex).setColor(sf::Color::White);
					break;
				}
				case 1:{
					read_score(w);
					add_option("Back", 700);
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
					w.close();
					game.run(1);
					break;
				}
				case 1:{
					w.close();
					game.run(2);
					break;
				}
				case 2:{
					menu.erase(menu.begin(), menu.end());
					add_option("Play", 300);
					add_option("High Score", 400);
					add_option("Exit", 500);
					selectedItemIndex = 0;
					menu_depth = 0;
					menu.at(selectedItemIndex).setColor(sf::Color::White);
					break;
				}
			}
		}else if(menu_depth == 2){
			if(GetPressedItem() == menu.size()-1){
				menu.erase(menu.begin(), menu.end());
				add_option("Play", 300);
				add_option("High Score", 400);
				add_option("Exit", 500.0f);
				selectedItemIndex = 0;
				menu_depth = 0;
				menu.at(selectedItemIndex).setColor(sf::Color::White);
			}
		}
	}
}

void Menu::read_score(sf::RenderWindow &window) {
	std::ifstream ifs{"assets/score"};
	menu.erase(menu.begin(), menu.end());

	if(ifs.is_open()) {
		float pos{100.0f};
		float step{1.0f};
        for(std::string line; getline( ifs, line );)
        {
            add_option(line, (pos + step));
			step += 50.0f;
        }
    }
	ifs.close();
	if(menu.size() == 0){
		add_option("There doesn't seem to be anything here", 350.0f);
	}
	selectedItemIndex = 0;
	menu_depth = 2;
	menu.at(selectedItemIndex).setColor(sf::Color::White);
}

void Menu::add_option(std::string s, float f){
	sf::Text option;
	option.setFont(font);
	option.setColor(sf::Color::Red);
	option.setString(s);
	sf::FloatRect item = option.getGlobalBounds();
	option.setPosition(sf::Vector2f((item_width / 2) - (item.width / 2), f));
	menu.push_back(option);
}
