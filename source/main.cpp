#include <iostream>
#include <SFML/Graphics.hpp>

#include "objects/World.h"
#include "objects/Key_Handling.h"
#include "objects/Entity.h"
#include "objects/Player.h"


int main(){
    sf::RenderWindow window{sf::VideoMode(1600, 900),"Bubble Bobble"};
    World world{window, 0.5};
    Player player1{};
    world.add_entity(&player1);
    
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
        player1.update();
        window.draw(player1);
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
}