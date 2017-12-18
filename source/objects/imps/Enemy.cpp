#include "../headers/Enemy.h"
#include <iostream>

Enemy::Enemy(std::string n, std::string t,
    Behaviour* b, float x, float y, sf::Texture const& texture, sf::IntRect size, World& w)
    :Entity(n, t, b, texture, size, w) {
        setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
        setPosition(x, y);
    }

void Enemy::update(sf::Time const& t){
    behaviour_ptr->process(world, *this, t);
}

void Enemy::kill(World& w){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 10);
    int will_drop = dis(rd);  // generates number in the range 1..2
    int drop = dis(rd);

    std::cout << "will_drop: " << will_drop << std::endl << "drop: " << drop << std::endl;
    if(will_drop % 2 == 0) {
        if(drop == 10) {
            world.add_entity(new Drop("Heart", "Drop",
                new Drop_Behaviour_heart(), getPosition().x, getPosition().y, world.get_texture("projectile"),
                sf::IntRect(0,0,16,16), world));
        } else {
            world.add_entity(new Drop("Points", "Drop",
                new Drop_Behaviour_points(), getPosition().x, getPosition().y, world.get_texture("projectile"),
                sf::IntRect(0,0,16,16), world));
        }
    }
    w.add_score(100);
    w.kill_me_now(*this);
}
