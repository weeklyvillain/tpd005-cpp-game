#include "../headers/Texture_Container.h"

Texture_Container::Texture_Container():textures{}{
    sf::Texture t;
    t.loadFromFile("assets/wizard_idle.png");;
    textures["wizard_idle"] = t;
    
    t.loadFromFile("assets/wizard_attack.png");;
    textures["wizard_attack"] = t;
    
    t.loadFromFile("assets/wizard_fly_forward.png");;
    textures["wizard_fly"] = t;

    t.loadFromFile("assets/wizard_death.png");;
    textures["wizard_death"] = t;

    t.loadFromFile("assets/projectile.png");;
    textures["projectile"] = t;

    t.loadFromFile("assets/Art_Tileset.png");;
    textures["tile_set"] = t;

    t.loadFromFile("assets/Wraith.png");;
    textures["enemy"] = t;

}
sf::Texture const& Texture_Container::get_texture(std::string name, int state) const{

}