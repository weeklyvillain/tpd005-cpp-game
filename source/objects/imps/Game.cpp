#include "../headers/Game.h"

int Game::run(int player_amount){

    sf::RenderWindow window{sf::VideoMode(1900, 900), "Bubble Bobble", sf::Style::Titlebar | sf::Style::Close};
    window.setVerticalSyncEnabled(true);
    World world{window, 0.5};

    std::vector<std::string> lvls
    {"assets/levels/level1.lvl" ,
     "assets/levels/level2.lvl",
     "assets/levels/level3.lvl",
     "assets/levels/level4.lvl",
     "assets/levels/level5.lvl",
     "assets/levels/level6.lvl",
     "assets/levels/level7.lvl",
     "assets/levels/level8.lvl"
    };
    sf::Texture t{};
    sf::Sprite bkg{};
    if(t.loadFromFile("assets/background.png")){
        bkg.setTexture(t);
    }


    int level_index{0};
    Level(lvls.at(level_index), 80, 80, world, player_amount);

    sf::Clock clock;
    sf::Time targetFrameDelay {sf::milliseconds(16.7)};

    while (world.run){
        sf::Event event;
        while (window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    world.run = false;
                    break;
                case sf::Event::KeyPressed:
                    world.on_Key_Press(event.key.code);
                    break;
                case sf::Event::KeyReleased:
                    world.on_Key_Release(event.key.code);
                    break;
                case sf::Event::Resized:
                    //world.MaintainAspectRatio();
                    break;
                default:
                    if (world.player1.quit){
                        window.close();
                        world.run = false;
                    }
                    break;
			}
        }

        //Vänta tills nästa bildruta innan du ritar
        auto frameDelay = clock.restart();


        window.clear(sf::Color::White);
        window.draw(bkg);
        if(!world.player1.pause){
            world.update_all(frameDelay);
        }
        world.render_all();
        if(!world.get_player()) {
            sf::Texture t{};
            sf::Sprite screen{};
            if(t.loadFromFile("assets/game_over.png")){
                screen.setTexture(t);
                window.draw(screen);
            }
        }
        sf::Font font{};
        sf::Text hp;
        sf::Text score;
        sf::Text paused;
        if (font.loadFromFile("assets/ScoreFont.ttf"))
    	{
            sf::FloatRect item = hp.getGlobalBounds();
        	hp.setPosition(sf::Vector2f((1600 / 2) - (item.width / 2) + 900, 900 / 3));
    		hp.setFont(font);
        	hp.setColor(sf::Color::Red);
        	hp.setString("HP: " + std::to_string(world.get_lives()));
            window.draw(hp);

            item = score.getGlobalBounds();
        	score.setPosition(sf::Vector2f((1600 / 2) - (item.width / 2) + 900, 900 / 2));
    		score.setFont(font);
        	score.setColor(sf::Color::Red);
        	score.setString("Score: " + std::to_string(world.get_score()));
            window.draw(score);

            if(world.player1.pause){
                item = paused.getGlobalBounds();
                paused.setPosition(sf::Vector2f((1600 / 2) - (item.width / 2), (900 / 2) - (item.height / 2)));
                paused.setFont(font);
                paused.setColor(sf::Color::Red);
                paused.setString("PAUSED");
                window.draw(paused);
            }
        }

        if ( targetFrameDelay > frameDelay )
        {
            //Vänta bara om du verkligen behöver
            auto sleepTime = targetFrameDelay - frameDelay;
            sf::sleep(sleepTime);
        }

        if(world.win()) {
            world.clear();
            level_index++;
            Level(lvls.at(level_index), 80, 80, world, player_amount);
        }
        window.display();
    }
    return 0;

}
