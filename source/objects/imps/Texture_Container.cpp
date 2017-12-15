#include "../headers/Texture_Container.h"
#include <iostream>

Texture_Container::Texture_Container():textures{}{
    sf::Texture t1;
    t1.loadFromFile("assets/wizard_idle.png");;
    textures["wizard_idle"] = t1;
    
    sf::Texture t3;
    t3.loadFromFile("assets/wizard_fly_forward.png");;
    textures["wizard_fly"] = t3;

    sf::Texture t4;
    t4.loadFromFile("assets/wizard_death.png");;
    textures["wizard_death"] = t4;

    sf::Texture t5;
    t5.loadFromFile("assets/projectile.png");;
    textures["projectile"] = t5;

    sf::Texture t6;
    t6.loadFromFile("assets/Art_Tileset.png");;
    textures["platform"] = t6;

    sf::Texture t7;
    t6.loadFromFile("assets/Wraith.png");;
    textures["enemy"] = t7;

}
sf::Texture const& Texture_Container::get_texture(std::string name) const{
    return textures.at(name);
}