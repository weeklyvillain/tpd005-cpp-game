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
    flip(owner, dir);

    //Movement
    move_y(owner, dir, t);

    //Collisons
    collision_y(world, owner);

    //Movement
    move_x(owner, dir, t);

    //Collisons
    collision_x(world, owner);
}


void Enemy_Behaviour::flip(Entity& owner, sf::Vector2f const& dir){
    if (dir.x == 1.0f && owner.getScale().x == 1.0f){
        owner.setScale(-1.0f, 1.0f);
    }else if (dir.x == -1.0f && owner.getScale().x == -1.0f ){
        owner.setScale(1.0f, 1.0f);
    }
}

void Enemy_Behaviour::move_y(Entity& owner, sf::Vector2f const& dir, sf::Time t){
    if (velocity.y == 0.0f){
        velocity.y = dir.y * 7;
    }
    owner.setPosition(owner.getPosition().x, owner.getPosition().y + velocity.y);

    //Applying gravity
    velocity.y += acceleration.y;
}

void Enemy_Behaviour::move_x(Entity& owner, sf::Vector2f const& dir, sf::Time t){
    velocity.x = dir.x * 100 * t.asSeconds();
    owner.setPosition(owner.getPosition().x + velocity.x, owner.getPosition().y);
}
void Enemy_Behaviour::collision_y(World& world, Entity& owner){
    Entity* now = world.am_I_Colliding(owner);
    if (now && now->get_type() == "Enemy" && velocity.y > 0){
        owner.setPosition(owner.getPosition().x, now->getPosition().y - 81);
    }else if(now && now->get_type() == "Enemy" && velocity.y <= 0){
        owner.setPosition(owner.getPosition().x, now->getPosition().y + 81);
    }

    if(now && now->get_type() == "Player"){
        now->kill(world);
        now = nullptr;
    }

    if (now && velocity.y >= 0.0f && now->get_type() == "Platform"
            && owner.getPosition().y + 40 >= now->getPosition().y - 40
            && owner.getPosition().y + 40 <= now->getPosition().y - 20){

        owner.setPosition(owner.getPosition().x, now->getPosition().y -80.0f);
        velocity.y = 0.0f;
    }

    if(now && now->get_type() == "Roof") {
        owner.setPosition(owner.getPosition().x, now->getPosition().y + 80.0f);
        velocity.y = acceleration.y;
    }

    if (owner.getPosition().y < 0 || owner.getPosition().y > 900){
        owner.setPosition(800, 50);
        velocity.y = acceleration.y;
    }
    if (owner.getPosition().x < 0 || owner.getPosition().x > 1600){
        owner.setPosition(800, 50);
        velocity.y = acceleration.y;
    }
}
void Enemy_Behaviour::collision_x(World& world, Entity& owner){
    Entity* now = world.am_I_Colliding(owner);

    if (now && now->get_type() == "Enemy" && velocity.x > 0){
        owner.setPosition(now->getPosition().x - 81, owner.getPosition().y);
    }else if(now && now->get_type() == "Enemy" && velocity.x <= 0){
        owner.setPosition(now->getPosition().x + 81, owner.getPosition().y);
    }

    if(now && now->get_type() == "Wall" && velocity.x < 0) {
        velocity.x = -velocity.x;
        owner.setPosition(now->getPosition().x + 81, owner.getPosition().y);
    } else if(now && now->get_type() == "Wall" && velocity.x > 0) {
        velocity.x = -velocity.x;
        owner.setPosition(now->getPosition().x - 81, owner.getPosition().y);
    }
}
