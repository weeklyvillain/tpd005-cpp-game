#pragma once
#include "SFML/Graphics.hpp"
#include <memory>
#include <map>

/**
 * \brief Texture_Container tillhandahåller texturer till alla entiteter.
 *
 * Texture_Container läser in alla grafiska bitar av spelet och
 * tillhandahåller pekare till dessa. Detta för att använda mindre grafiskt minne.
 * 
 */

class Texture_Container{
public:
    ///Vanlig Konstruktor
    Texture_Container();
    ///Copy konstruktor
    Texture_Container(Texture_Container const & other) = delete;
    ///Move konstruktor
    Texture_Container(Texture_Container && other) = delete;
    ///Copy operator
    Texture_Container& operator=(Texture_Container const & rhs) & = delete;
    ///Move operator
	Texture_Container& operator=(Texture_Container && rhs) = delete;
	///Default Destruktor
	~Texture_Container() = default;
    ///En funktion som returnerar den textur som har namnet strängen anger.
    sf::Texture const& get_texture(std::string) const;

private:
    ///En std#map som innehåller unika smart pekare.
    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
};