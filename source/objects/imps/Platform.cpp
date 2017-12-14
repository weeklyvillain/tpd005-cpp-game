#include "../headers/Platform.h"

Platform::Platform(std::string n, std::string t, Behaviour* b, sf::Vector2f pos):Entity(n, t, b){
        texture.loadFromFile("assets/Art_Tileset.png");
        this->setTexture(texture);
        this->setOrigin(40.0f, 40.0f);
        this->setTextureRect(sf::IntRect(0, 238, 80, 80));
        this->setPosition(pos);
    }

void Platform::update(World& w, sf::Time const& t){
    behaviour_ptr->process(w, *this, t);
}

void Platform::kill(World& w){
    w.kill_me_now(*this);
}