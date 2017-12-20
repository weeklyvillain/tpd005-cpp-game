#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include "Key_Handling.h"
#include "Entity.h"
#include "Texture_Container.h"

/**
 * \brief World simulerar spelvärlden.
 *
 * World utför simulation av spelvärlden. 
 * Den baserar sig på SFMLs inbyggda positions system och uppdaterar entiteter varje gång
 * update_all() kallas på. Klassen håller också koll på input från användaren,
 * hur många extraliv en spelare har och hur många poäng denne har.
 *
 */

class World{
public:
    ///World's konstruktor tar in ett sf::RenderWindow och sparar detta i en variabel.
    World(sf::RenderWindow&);
    ///Copy konstruktor
    World(World const & other) = delete;
    ///Move konstruktor
    World(World && other) = delete;
    ///Copy operator
    World& operator=(World const & rhs) & = delete;
    ///Move operator
	World& operator=(World && rhs) = delete;
    ///Default destruktor.
    ~World() = default;
    ///Lägger till en Entity objekt pekare i World#Entities. 
    /// Använder unika smart pekare för att undvika memory leaks.
    void add_entity(Entity*);
    ///Går igenom World#Entities och kör deras Entity#Update().
    void update_all(sf::Time const&);
    ///Går igenom World#Entities och ritar dessa till window.
    void render_all() const;
    ///Tar hand om tangenttryckningar genom att skicka true när den trycks ner.
    void on_Key_Press(sf::Keyboard::Key);
    ///Tar hand om tangenttryckningar genom att skicka false när den släpps upp.
    void on_Key_Release(sf::Keyboard::Key);
    ///En funktion som returnerar ett referens 
    /// till ett Entity objekt om det kolliderar med det objekt som tillhandahålls.
    /// Den kollar detta med hjälp av SFMLs egna intersect().
    /// Dock returnerar den bara det första objektet som kolliderar.
    /// Detta kan skapa problem.
    Entity* am_I_Colliding(Entity const&) const;
    ///Tar bort det objekt som tillhandahålls från World#Entities.
    /// Detta genom att gå igenom och hitta den pekare i World#Entities 
    /// som pekar på samma minnesaddress som objektet som tillhandahålls.
    /// Sedan tas den bort. 
    void kill_me_now(Entity&);
    ///Returnerar den första spelaren i World#Entities.
    /// Används för att avgöra huruvida alla spelare har dött.
    Entity* get_player() const;
    ///Tar bort alla objekt i World#Entities.
    /// Detta används för att kunna skapa nya nivåer utan att de gamla stör.
    void clear();
    ///Om spelaren har dödat alla enemy objekt så returnerar denna true.
    bool win() const;
    ///Getter för World#lives.
    int get_lives() const;
    ///Lägger till 1 life.
    void add_life();
    ///Tar bort 1 life.
    void remove_life();
    ///Getter för World#score.
    unsigned int get_score() const;
    ///Lägger till n på score.
    void add_score(unsigned int);
    ///tar bort n på score.
    void remove_score(unsigned int);
    ///Hämtar en texture från World#texture_list.
    sf::Texture const& get_texture(std::string name)const{
        return texture_list.get_texture(name);
    }
    ///Tangent hanterare för spelare 1.
    Key_Handling player1{
        sf::Keyboard::Up,
        sf::Keyboard::Left,
        sf::Keyboard::Right,
        sf::Keyboard::Space
    };
    ///Tangent hanterare för spelare 2.
    Key_Handling player2{
        sf::Keyboard::W,
        sf::Keyboard::A,
        sf::Keyboard::D,
        sf::Keyboard::F
    };
    ///Bool som används för att avsluta spelet.
    bool run{true};
private:
    ///Fönstret som illustrerar spelet
    sf::RenderWindow& window;
    ///En vektor av unika smart pekare som innehåller alla Entitys i världen.
    std::vector<std::unique_ptr<Entity>> entities;
    ///Antal liv för spelarna.
    int lives{3};
    ///Spelarnas poäng
    unsigned int score{0};
    ///En Texture_Container som innehåller alla grafiska delar av spelet.
    Texture_Container texture_list{};

};
