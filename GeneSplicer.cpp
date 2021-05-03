#include "GeneSplicer.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

GeneSplicer& GeneSplicer::discover_cure(Color disease){
    if(b.has_station(location)){
        if(_holds.size() >= 5){
            int count = 0;
            for(auto& card : _holds){
                if(count++ < 5){
                    _holds.erase(card);
                }
            }
            b.cure_found(disease);
        }
        else{
            throw invalid_argument("Player doesn't hold 5 cards or more");
        }
    }
    else{
        throw invalid_argument("A station needed in order to discover cure");
    }
    return *this;
}
// const string& GeneSplicer::role() const{

// }