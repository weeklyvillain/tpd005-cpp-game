#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity{

public:
    Player(std::string, std::string, Behaviour*, float, float);
        void update(World&, sf::Time const&) override;
        void kill(World&) override;
        
        float time_since_last_shot{0};

private:
    sf::Texture texture{};
    int idle_state{0};

};

#endif
