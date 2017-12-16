#include "../headers/Enemy.h"

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
    std::default_random_engine generator;
    std::uniform_int_distribution<int> drop_chance(1,2);
    int will_drop = drop_chance(generator);  // generates number in the range 1..6

    std::uniform_int_distribution<int> wich_drop(1,2);
    int drop = wich_drop(generator);
    if(will_drop == 1) {
        if(drop == 1) {
            world.add_entity(new Drop("Heart", "Drop",
                new Drop_Behaviour_heart(), getPosition().x, getPosition().y, world.get_texture("projectile"),
                sf::IntRect(0,0,16,16), world));
        } else {
            world.add_entity(new Drop("Points", "Drop",
                new Drop_Behaviour_points(), getPosition().x, getPosition().y, world.get_texture("projectile"),
                sf::IntRect(0,0,16,16), world));
        }
    }
    w.kill_me_now(*this);
}
