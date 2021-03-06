#include "../headers/Enemy.h"

Enemy::Enemy(std::string n, std::string t,
    Behaviour* b, float x, float y, sf::Texture const& texture, sf::IntRect size)
    :Entity(n, t, b, texture, size) {
        setOrigin(getLocalBounds().width/2, getLocalBounds().height/2);
        setPosition(x, y);
    }

void Enemy::update(World& world, sf::Time const& t){
    behaviour_ptr->process(world, *this, t);
}

void Enemy::kill(World& world){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    int will_drop = dis(rd);
    int drop = dis(rd);

    if(will_drop % 2 == 0) {
        if(drop == 10) {
            world.add_entity(new Drop("Heart", "Drop",
                new Drop_Behaviour_heart(), getPosition().x, getPosition().y, world.get_texture("heart"),
                    sf::IntRect(0,0,16,16)));
        } else {
            world.add_entity(new Drop("Points", "Drop",
                new Drop_Behaviour_points(), getPosition().x, getPosition().y, world.get_texture("coin"),
                    sf::IntRect(0,0,16,16)));
        }
    }
    world.add_score(100);
    world.kill_me_now(*this);
}
