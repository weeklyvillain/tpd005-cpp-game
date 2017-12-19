#ifndef DROP_H
#define DROP_H

#include "Entity.h"

/**
 * \brief Drop ärver från Entity och innehåller all information för en entitet av droptyp.
 *
 * Drop ärver från den abstrakta klassen Entity och däför behöver den köra override på update() och Kill()
 *
 */

class Drop : public Entity{
public:
    ///Drop's konstruktor tar in ett namn, en typ, en pekare till ett objekt av Behaviour-typ, 
    /// x och y värdet där objektet ska finnas, 
    /// en texture från Texture_Container och vilken del av texturen som ska visas
    Drop(std::string, std::string, Behaviour*, float, float, sf::Texture const&, sf::IntRect);
    ///Funktion som kallas av world när det här specifika objektet ska uppdatera sig.
    /// Det gör sedan detta genom att t.ex. flytta på sig och kolla kollisioner.
    void update(World&, sf::Time const&) override;
    ///Om det här objektet har dödats så kommer kill att göra det genom att informera World om det.
    void kill(World&) override;
};

#endif
