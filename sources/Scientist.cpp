#include "Scientist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <vector>

using namespace std;
using namespace pandemic;

Scientist& Scientist::discover_cure(Color disease){
    if(b.has_station(location)){
        vector<City> to_throw = Player::get_all_cards_colored(disease);
        if(to_throw.size() >= _cards_to_discover_cure){
            for(size_t i = 0; i < _cards_to_discover_cure; i++){
                _holds.erase(to_throw.at(i));
            }
            b.cure_found(disease);
        }
        else{
            cout << to_throw.size() << " , " << _cards_to_discover_cure << endl;
            throw invalid_argument("scientist doesn't hold enough cards from this color");
        }
    }
    else{
        throw invalid_argument("A station needed in order to discover cure");
    }
    return *this;
}
