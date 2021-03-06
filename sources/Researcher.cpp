#include "Researcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <stdexcept>

using namespace std;
using namespace pandemic;

Researcher& Researcher::discover_cure(Color disease){
    
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
    
    return *this;
}
