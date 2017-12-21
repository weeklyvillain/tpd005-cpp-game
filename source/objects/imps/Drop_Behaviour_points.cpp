#include "../headers/Drop_Behaviour_points.h"
#include "../headers/Entity.h"

void Drop_Behaviour_points::process(World& world, Entity& owner,
    sf::Time const& t){

    //Applying gravity
    velocity.y += acceleration.y;

    //Moving sprite
    owner.setPosition(owner.getPosition() + velocity);

    Entity* now = world.am_I_Colliding(owner);
    if (now && now->get_name() == "Platform"){
      owner.setPosition(owner.getPosition().x, now->getPosition().y - 48.0f);
       velocity.y = 0;
    }

   now = world.am_I_Colliding(owner);
   if(now && now->get_type() == "Player"){
       owner.kill(world);
       world.add_score(50);
       now = nullptr;
   }
}
