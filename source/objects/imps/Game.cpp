#include "../headers/Game.h"

int Game::run(){


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

    int level_index{0};
    Level(lvls.at(level_index), 80, 80, world);


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
        world.update_all(frameDelay);
        world.render_all();

        if ( targetFrameDelay > frameDelay )
        {
            //Vänta bara om du verkligen behöver
            auto sleepTime = targetFrameDelay - frameDelay;
            sf::sleep(sleepTime);
        }
        if(world.win()) {
            world.clear();
            level_index++;
            Level(lvls.at(level_index), 80, 80, world);
        }
        window.display();
    }
    return 0;
}
