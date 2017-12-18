#include "../headers/Player1_Behaviour.h"
#include <iostream>

void Player1_Behaviour::process(World &world, Entity& owner, sf::Time const& t){
    Player& o = dynamic_cast<Player&>(owner);
    sf::Vector2f dir = world.player1.direction();

    //Flipping sprite based on movement
    flip(o, dir);

    //Animation
    //animate(o);

    //Shooting
    shoot(world, o, t);

    //Movement
    move_y(o, dir, t);

    //Collisons
    collision_y(world, o);

    //Movement
    move_x(o, dir, t);

    //Collisons
    collision_x(world, o);

    std::cout << owner.getPosition().x << ":" << owner.getPosition().y << std::endl;
}

void Player1_Behaviour::flip(Entity& owner, sf::Vector2f const& dir){
    if (dir.x == 1.0f && owner.getScale().x == 1.0f){
        owner.setScale(-1.0f, 1.0f);
    }else if (dir.x == -1.0f && owner.getScale().x == -1.0f ){
        owner.setScale(1.0f, 1.0f);
    }
}

void Player1_Behaviour::animate(Entity& owner){
    owner.setTextureRect(sf::IntRect(frame * 80, 0, 80, 80));
    if(i > 10){
        if(frame < 9){
            frame++;
        } else {
            frame = 0;
        }
        i = 0;
    } else {
        i++;
    }
}

void Player1_Behaviour::shoot(World& world, Player& owner, sf::Time t)const{
    if (world.player1.shoot && owner.time_since_last_shot + t.asSeconds() > 0.5f){
        world.add_entity(
            new Projectile("proj", "Projectile",
                new Projectile_Behaviour(owner.getScale().x, owner.getPosition().x),
                owner.getPosition().x+(-50.0f*owner.getScale().x), owner.getPosition().y,
                world.get_texture("projectile"),
                sf::IntRect(0, 0, 16, 16),
                world
            )
        );
        owner.time_since_last_shot = 0.0f;
    }else{
        owner.time_since_last_shot += t.asSeconds();
    }
}

void Player1_Behaviour::move_y(Entity& owner, sf::Vector2f const& dir, sf::Time t){
    if (velocity.y == 0.0f){
        velocity.y = dir.y * 500 * t.asSeconds();
    }
    owner.setPosition(owner.getPosition() + velocity);

    //Applying gravity
    velocity.y += acceleration.y;
}
void Player1_Behaviour::move_x(Entity& owner, sf::Vector2f const& dir, sf::Time t){
    velocity.x = dir.x * 80 * t.asSeconds();

    owner.setPosition(owner.getPosition().x + velocity.x, owner.getPosition().y);


}
void Player1_Behaviour::collision_y(World& world, Entity& owner){

    Entity* now = world.am_I_Colliding(owner);
    if (now && velocity.y >= 0.0f && now->get_name() == "Platform"
            && owner.getPosition().y + 40 >= now->getPosition().y - 40
            && owner.getPosition().y + 40 <= now->getPosition().y - 20){

        owner.setPosition(owner.getPosition().x, now->getPosition().y -80.0f);
        velocity.y = 0.0f;
    }

    if(now && now->get_name() == "Roof") {
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
void Player1_Behaviour::collision_x(World& world, Entity& owner){

    Entity* now = world.am_I_Colliding(owner);

    if(now && now->get_name() == "Wall" && velocity.x < 0) {
        velocity.x = -velocity.x;
        owner.setPosition(now->getPosition().x + 81, owner.getPosition().y);
    } else if(now && now->get_name() == "Wall" && velocity.x > 0) {
        velocity.x = -velocity.x;
        owner.setPosition(now->getPosition().x - 81, owner.getPosition().y);

    }

}
