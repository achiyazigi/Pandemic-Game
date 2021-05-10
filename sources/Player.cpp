#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace pandemic;

Player::Player(Board& board, City c):b(board), location(c){}
Player& Player::take_card(City to_take){
    _holds.insert(to_take);
    return *this;
}
Player& Player::drive(City to_drive){
    if(b.are_neighbors(location, to_drive)){
        location = to_drive;
    }
    else{
        throw invalid_argument("illegal action: city isn't connected");
    }
    return *this;
}
Player& Player::fly_direct(City to_fly_direct){
    if(location == to_fly_direct){
        throw invalid_argument("can't fly from city to itself");

    }
    if(_holds.contains(to_fly_direct)){
        _holds.erase(to_fly_direct);
        location = to_fly_direct;
    }
    else{
        throw invalid_argument("Player doesn't hold this card");
    }
    return *this;
}
Player& Player::fly_charter(City to_fly_charter){
    if(location == to_fly_charter){
        throw invalid_argument("can't fly from city to itself");

    }
    if(_holds.contains(location)){
        _holds.erase(location);
        location = to_fly_charter;
    }
    else{
        throw invalid_argument("Player doesn't hold his location card");
    }
    return *this;
}
Player& Player::fly_shuttle(City to_fly_shuttle){
    if(location == to_fly_shuttle){
        throw invalid_argument("can't fly from city to itself");

    }
    if(b.has_station(location) && b.has_station(to_fly_shuttle)){
        location = to_fly_shuttle;
    }
    else{
        throw invalid_argument("In order to complete this action please build stations in the src and the dst citys");
    }
    return *this;
}
Player& Player::discover_cure(Color disease){
    if(b.is_cure_found(disease)){
        return *this;
    }
    if(b.has_station(location)){
        vector<City> to_throw = get_all_cards_colored(disease);
        if(to_throw.size() >= CARDS_TO_DISCOVER_CURE){
            for(size_t i = 0; i < CARDS_TO_DISCOVER_CURE; i++){
                _holds.erase(to_throw.at(i));
            }
            b.cure_found(disease);
        }
        else{
            throw invalid_argument("Player doesn't hold 5 cards from this color");
        }
    }
    else{
        throw invalid_argument("A station needed in order to discover cure");
    }
    return *this;
}
Player& Player::build(){
    if(_holds.contains(location)){
        _holds.erase(location);
        b.add_station(location);
        // if(!b.add_station(location)){
        //     throw invalid_argument("there is already a station here");
        // }
    }
    else{
        throw invalid_argument("Player doesn't hold his location city card");
    }
    return *this;
}
Player& Player::treat(City to_treat){
    if(location == to_treat && b[to_treat] > 0){
        if(b.is_cure_found(b.get_color(to_treat))){
            b[to_treat] = 0;
        }
        else{
            b[to_treat]--;
        }
    }
    else if(b[to_treat] <= 0){
        throw invalid_argument("no disease in this city");
    }
    else{
        throw invalid_argument("can't treat remote city");
    }
    return *this;
}

vector<City> Player::get_all_cards_colored(Color color){
    vector<City> res;
    for(const auto& card: _holds){
        if(b.get_color(card) == color){
            res.push_back(card);
        }
    }
    return res;
}


