#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

/**
 * \brief Player ärver från Entity och innehåller all information för en entitet av spelartyp.
 *
 * 
 */

class Player : public Entity{
public:
    ///Player konstruktor som tar in ett namn, en typ, en Behaviour pekare, 
    /// en texture, vilken kvadrat som ska ritas ut och vilken färg den ska ha.
    Player(std::string, std::string, Behaviour*, float, float, sf::Texture const&, sf::IntRect, sf::Color);
    ///Copy konstruktor
    Player(Player const & other) = delete;
    ///Move konstruktor
    Player(Player && other) = delete;
    ///Copy operator
    Player& operator=(Player const & rhs) & = delete;
    ///Move operator
	Player& operator=(Player && rhs) = delete;
	///Default Destruktor
	~Player() = default;
    ///Entity#update() override
    /// Funktion som kallas av world när det här specifika objektet ska uppdatera sig.
    /// Det gör sedan detta genom att t.ex. flytta på sig och kolla kollisioner.
    void update(World&, sf::Time const&) override;
    ///Om det här objektet har dödats så kommer kill att göra det genom att informera World om det.
    void kill(World&) override;
    ///En float för att se hur lång tid det var sen spelare senast sköt.
    float time_since_last_shot{0};
};

#endif
