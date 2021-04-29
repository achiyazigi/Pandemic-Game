#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
using namespace std;
using namespace pandemic;

Player::Player(Board, City){}
Player& Player::take_card(City){
    return *this;
}
Player& Player::drive(City){
    return *this;
}
Player& Player::fly_direct(City){
    return *this;
}
Player& Player::fly_charter(City){
    return *this;
}
Player& Player::fly_shuttle(City){
    return *this;
}
Player& Player::discover_cure(Color){
    return *this;
}
Player& Player::build(){
    return *this;
}
Player& Player::treat(City){
    return *this;
}


