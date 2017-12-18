#include "../headers/Key_Handling.h"

Key_Handling::Key_Handling(): jump{}, left{}, right{}, shoot{},
    jump_key{sf::Keyboard::Up}, left_key{sf::Keyboard::Left}, right_key{sf::Keyboard::Right}, shoot_key{sf::Keyboard::Space}{};

Key_Handling::Key_Handling(sf::Keyboard::Key j, sf::Keyboard::Key l,
    sf::Keyboard::Key r, sf::Keyboard::Key s)
    : jump{}, left{}, right{}, shoot{}, jump_key{j}, left_key{l}, right_key{r}, shoot_key{s}{}

void Key_Handling::onKey(bool pressed, sf::Keyboard::Key const& key) {
    if(key == jump_key){
        jump = pressed;
    }else if(key == left_key){
        left = pressed;
    }else if(key == right_key){
        right = pressed;
    }else if(key == shoot_key){
        shoot = pressed;
    }else if(key == sf::Keyboard::Q || key == sf::Keyboard::Escape){
        quit = true;
    } 
}

sf::Vector2f Key_Handling::direction() const {
    sf::Vector2f dir;
    if (jump)
        dir.y -= 1.0f;
    if (left)
        dir.x -= 1.0f;
    if (right)
        dir.x += 1.0f;
    return dir;
}