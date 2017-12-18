#include "../headers/Projectile_Behaviour.h"
#include "../headers/Entity.h"


Projectile_Behaviour::Projectile_Behaviour(float dir, float init_pos):Behaviour{}, direction{dir}, init_pos{init_pos}{}
void Projectile_Behaviour::process(World& world, Entity& owner, sf::Time const& t){
    owner.setPosition(owner.getPosition().x+(-320.0f*direction * t.asSeconds()), owner.getPosition().y);
    if(auto now = world.am_I_Colliding(owner)){
        if (now->get_type() != "Player" && now->get_type() != "Projectile"){
            world.kill_me_now(owner);
            if (now->get_type() != "Platform"){
                now->kill(world);
            }
        }
    }
}