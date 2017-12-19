#include "../headers/Texture_Container.h"
#include <iostream>

Texture_Container::Texture_Container():textures{}{
    sf::Texture t1;
    if(t1.loadFromFile("assets/wizard_idle.png")){
        textures["wizard_idle"] = std::make_unique<sf::Texture>(t1);
    }

    sf::Texture t2;
    if(t2.loadFromFile("assets/wizard_attack.png")){
        textures["wizard_attack"] = std::make_unique<sf::Texture>(t2);
    }

    sf::Texture t3;
    if(t3.loadFromFile("assets/Wraith.png")){
        textures["enemy"] = std::make_unique<sf::Texture>(t3);
    }

    sf::Texture t5;
    if(t5.loadFromFile("assets/projectile.png")){
        textures["projectile"] = std::make_unique<sf::Texture>(t5);
    }

    sf::Texture t6;
    if(t6.loadFromFile("assets/Art_Tileset.png")){
        textures["platform"] = std::make_unique<sf::Texture>(t6);
    }
    
    sf::Texture t7;
    if(t7.loadFromFile("assets/heart.png")){
        textures["heart"] = std::make_unique<sf::Texture>(t7);
    }
    
    sf::Texture t8;
    if(t8.loadFromFile("assets/coin.png")){
        textures["coin"] = std::make_unique<sf::Texture>(t8);
    }
}
sf::Texture const& Texture_Container::get_texture(std::string name) const{
    return *textures.at(name);
}
