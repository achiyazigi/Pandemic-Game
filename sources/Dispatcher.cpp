#include "Dispatcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Dispatcher& Dispatcher::fly_direct(City c){
    if(location == c){
        throw invalid_argument("can't fly from city to itself");

    }
    if(!b.has_station(location)){
        Player::fly_direct(c);
        return *this;
    }
    location = c;
    return *this;
}
