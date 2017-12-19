#include "../headers/Player_Behaviour.h"
#include <iostream>

Player_Behaviour::Player_Behaviour(Key_Handling& key_handler):Behaviour(), handler{key_handler}{}

void Player_Behaviour::process(World &world, Entity& owner, sf::Time const& t){
    Player& o = dynamic_cast<Player&>(owner);
    sf::Vector2f dir = handler.direction();

    //Flipping sprite based on movement
    flip(o, dir);

    //Animation
    animate(world, o);

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

}

void Player_Behaviour::flip(Entity& owner, sf::Vector2f const& dir){
    if (dir.x == 1.0f && owner.getScale().x == 1.0f){
        owner.setScale(-1.0f, 1.0f);
    }else if (dir.x == -1.0f && owner.getScale().x == -1.0f ){
        owner.setScale(1.0f, 1.0f);
    }
}

void Player_Behaviour::animate(World& world, Entity& owner){
    owner.setTextureRect(sf::IntRect(frame * 80, 0, 80, 80));
    if(i > 10){
        if(frame < 9){
            frame++;
        } else {
            frame = 0;
            owner.setTexture(world.get_texture("wizard_idle"));
        }
        i = 0;
    } else {
        i++;
    }
}

void Player_Behaviour::shoot(World& world, Player& owner, sf::Time t){
    if (handler.shoot && owner.time_since_last_shot + t.asSeconds() > 0.5f){
        owner.setTexture(world.get_texture("wizard_attack"));
        i = 0;
        frame = 6;
        world.add_entity(
            new Projectile("proj", "Projectile",
                new Projectile_Behaviour(owner.getScale().x, owner.getPosition().x),
                owner.getPosition().x+(-50.0f*owner.getScale().x), owner.getPosition().y,
                world.get_texture("projectile"),
                sf::IntRect(0, 0, 16, 16)
            )
        );
        owner.time_since_last_shot = 0.0f;
    }else{
        owner.time_since_last_shot += t.asSeconds();
    }
}

void Player_Behaviour::move_y(Entity& owner, sf::Vector2f const& dir, sf::Time t){
    if (velocity.y == 0.0f){
        velocity.y = dir.y * 7;
    }
    owner.setPosition(owner.getPosition().x, owner.getPosition().y + velocity.y);

    //Applying gravity
    velocity.y += acceleration.y;
}
void Player_Behaviour::move_x(Entity& owner, sf::Vector2f const& dir, sf::Time t){
    velocity.x = dir.x * 160 * t.asSeconds();

    owner.setPosition(owner.getPosition().x + velocity.x, owner.getPosition().y);


}
void Player_Behaviour::collision_y(World& world, Entity& owner){

    Entity* now = world.am_I_Colliding(owner);
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
void Player_Behaviour::collision_x(World& world, Entity& owner){

    Entity* now = world.am_I_Colliding(owner);

    if(now && now->get_type() == "Wall" && velocity.x < 0) {
        velocity.x = -velocity.x;
        owner.setPosition(now->getPosition().x + 81, owner.getPosition().y);
    } else if(now && now->get_type() == "Wall" && velocity.x > 0) {
        velocity.x = -velocity.x;
        owner.setPosition(now->getPosition().x - 81, owner.getPosition().y);

    }
}
