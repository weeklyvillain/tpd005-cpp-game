#include "Game.h"


int Game::run(){

    sf::RenderWindow window{sf::VideoMode(1600, 900), "Bubble Bobble"};
    window.setVerticalSyncEnabled(true);
    World* world{new World(window, 0.5)};

    

    Level("../assets/test_map.txt", 80, 80, *world);

    sf::Clock clock;
    sf::Time targetFrameDelay {sf::milliseconds(10)};

    while (world->run){
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    world->run = false;
                    delete world;
                    break;
                case sf::Event::KeyPressed:
                    world->on_Key_Press(event.key.code);
                    break;
                case sf::Event::KeyReleased:
                    world->on_Key_Release(event.key.code);
                    break;
                default:
                    if (world->player1.quit){
                        window.close();
                        world->run = false; 
                        delete world;   
                    }
                    break;
			}
        }
        window.clear(sf::Color::White);
        world->update_all();
        world->render_all();
        window.display();
        //Vänta tills nästa bildruta innan du ritar
        auto frameDelay = clock.getElapsedTime();
        if ( targetFrameDelay > frameDelay )
        {
            //Vänta bara om du verkligen behöver
            auto sleepTime = targetFrameDelay - frameDelay;
            sf::sleep(sleepTime);
        }
    }
    return 0;
}
