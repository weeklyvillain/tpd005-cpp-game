#include "Game.h"


int Game::run(){

    sf::RenderWindow window{sf::VideoMode(1600, 900), "Bubble Bobble"};
    window.setVerticalSyncEnabled(true);
    World world{window, 0.5};
    
    Player1_Behaviour* pl1{new Player1_Behaviour()};
    Player* player1{new Player("player1", pl1)};
    Platform_Behaviour* p{new Platform_Behaviour()};
    for(float x{0}; x < 144; x = x + 12){
        Platform* plat{new Platform("plat1", p, sf::Vector2f{100+x, 600})};
        world.add_entity(plat); 
    }

    Platform* plat{new Platform("plat1", p, sf::Vector2f{288, 400})};
    plat->setColor(sf::Color::Black);
    world.add_entity(plat);


    for(float x{0}; x < 576; x = x + 12){
        Platform* plat{new Platform("plat1", p, sf::Vector2f{300+x, 400})};
        world.add_entity(plat); 
    }

    
    world.add_entity(player1);
    
    sf::Clock clock;
    sf::Time targetFrameDelay {sf::milliseconds(10)};
    
    while (world.run){
        clock.restart();
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
                    break;
			}
        }
        window.clear(sf::Color::White);
        world.update_all();
        world.render_all();
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