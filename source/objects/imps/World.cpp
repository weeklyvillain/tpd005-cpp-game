#include "../headers/World.h"
#include <iostream>

World::World(sf::RenderWindow &w)
    :window(w), entities{}{}

void World::add_entity(Entity* e){
    entities.push_back(std::unique_ptr<Entity>{e});
}

void World::update_all(sf::Time const& t){
    for(auto& it : entities){
        if (it != nullptr){
            it.get()->update(*this, t);
        }
    }
}

void World::render_all(){
    for(auto& it : entities){
        if (it != nullptr){
            window.draw(*it);
        }

    }
}

void World::on_Key_Press(sf::Keyboard::Key k){
    player1.onKey(true, k);
    player2.onKey(true, k);
}

void World::on_Key_Release(sf::Keyboard::Key k){
    player1.onKey(false, k);
    player2.onKey(false, k);
}

Entity* World::am_I_Colliding(Entity const& e) const{
    for(auto& it : entities){
        if (&e != it.get()) {
            sf::FloatRect bounding_box = e.getGlobalBounds();
            sf::FloatRect other_box = it->getGlobalBounds();
            if(bounding_box.intersects(other_box)){
                return it.get();
            }
        }
    }
    return nullptr;
}

void World::kill_me_now(Entity& e){
    for (size_t indx{0}; indx < entities.size(); indx++){
        if(entities.at(indx).get() != nullptr && entities.at(indx).get() == &e){
            entities.erase(entities.begin()+indx);
            break;
        }
    }
}

Entity* World::get_player() const{
    for(auto& it : entities){
        if(it->get_type() == "Player"){
            return it.get();

        }
    }
    return nullptr;
}

void World::clear(){
    entities.erase(begin(entities), end(entities));
}

bool World::win(){
    for(auto& it : entities){
        if(it->get_name() == "Enemy"){
            return false;
        }
    }
    return true;
}

int World::get_lives(){
    return lives;
}

void World::add_life(){
    lives++;
}

void World::remove_life(){
    lives--;
}

unsigned int World::get_score(){
    return score;
}

void World::add_score(unsigned int i){
    score += i;
}

void World::remove_score(unsigned int i){
    score -= i;
}

void World::send_packet(sf::IpAddress ip, unsigned short port) {
    sf::Packet packet;
	packet << lives << score;
    sf::TcpSocket socket;
    socket.connect(ip, port);
    socket.send(packet);
};
void World::receive_packet(unsigned short port) {
    sf::Packet packet;
    
    sf::TcpListener listener;
	listener.listen(port);
	listener.accept(socket);
    socket.receive(packet);
    packet >> lives >> score;
};
/*
sf::Packet& operator <<(sf::Packet& packet, World& w)
{
    return packet << w.get_lives() << w.get_score();
}

sf::Packet& operator >>(sf::Packet& packet, World& w)
{
    return packet >> p_lives >> p_score;
}
*/
