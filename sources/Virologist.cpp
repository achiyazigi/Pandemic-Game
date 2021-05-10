#include "Virologist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Virologist& Virologist::treat(City to_treat){
    if(b[to_treat] == 0){
        throw invalid_argument("no disease in this city");
    }
    if(location == to_treat){
        Player::treat(to_treat);
        return *this;
    }
    if(_holds.contains(to_treat)){
        _holds.erase(to_treat);
        b[to_treat]--;
    }
    else{
        throw invalid_argument("Virologist can't treat from distance without city card");
    }
    return *this;
}
string Virologist::role() const{
    return "Virologist";
}