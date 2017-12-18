#include "../headers/Enemy_Behaviour.h"
#include "../headers/Entity.h"

void Enemy_Behaviour::process(World& world, Entity& owner, sf::Time const& t){

    sf::Vector2f dir{0.0f, 0.0f};

    Entity* player = world.get_player();
    sf::Vector2f player_pos;
    if (player){
        player_pos = player->getPosition();
    }

    if(player && owner.getPosition().x > player_pos.x){
        dir.x = -1.0f;
    } else if(player && owner.getPosition().x < player_pos.x){
        dir.x = 1.0f;
    } else {
        dir.x = 0.0f;
    }
    if(player && owner.getPosition().y > player_pos.y){
        dir.y = -1.0f;
    } else {
        dir.y = 1.0f;
    }

    //Flipping sprite based on movement
    if (dir.x == 1.0f && owner.getScale().x == 1.0f){
        owner.setScale(-1.0f, 1.0f);
    }else if (dir.x == -1.0f && owner.getScale().x == -1.0f ){
        owner.setScale(1.0f, 1.0f);
    }

    //Moving sprite
    owner.setPosition(owner.getPosition() + velocity);

    //Movement
    velocity.x = dir.x* 80 * t.asSeconds();
    if (velocity.y == 0.0f){
        velocity.y = dir.y* 500 * t.asSeconds();
    }

    //Applying gravity
    velocity.y += acceleration.y;

    Entity* now = world.am_I_Colliding(owner);
    if(now && now->get_type() == "Player"){
        now->kill(world);
        now = nullptr;
    }

    if (now && velocity.y >= 0.0f && now->get_name() == "Platform"
        && (owner.getPosition().x  >= now->getPosition().x - 80.0f
        && owner.getPosition().x <= now->getPosition().x + 80.0f)){

        owner.setPosition(owner.getPosition().x, now->getPosition().y -80.0f);
        velocity.y = 0.0f;
    }else if(now && velocity.y < 0.0f && now->get_name() == "Platform"
        && (owner.getPosition().x  >= now->getPosition().x - 80.0f
        && owner.getPosition().x <= now->getPosition().x + 80.0f)){

            owner.setPosition(owner.getPosition().x, now->getPosition().y +80.0f);
            velocity.y = acceleration.y;
    }
    if (now && velocity.x > 0.0f && now->get_name() == "Platform"
        && (owner.getPosition().y  >= now->getPosition().y - 20.0f
        && owner.getPosition().y <= now->getPosition().y + 20.0f)){

            owner.setPosition(now->getPosition().x - 81.0f, owner.getPosition().y);
            velocity.x = -velocity.x;
    }else if(now && velocity.x < 0.0f && now->get_name() == "Platform"
        && (owner.getPosition().y  >= now->getPosition().y - 20.0f
        && owner.getPosition().y <= now->getPosition().y + 20.0f)){

            owner.setPosition(now->getPosition().x + 81.0f , owner.getPosition().y);
            velocity.x = -velocity.x;
        }
            
}