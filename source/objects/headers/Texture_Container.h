#pragma once
#include "SFML/Graphics.hpp"
#include <memory>
#include <map>

class Texture_Container{
public:
    Texture_Container();
    sf::Texture const& get_texture(std::string) const;

private:
    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
};