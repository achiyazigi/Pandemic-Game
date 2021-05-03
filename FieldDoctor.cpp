#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

FieldDoctor& FieldDoctor::treat(City to_treat){
    if(b[to_treat] == 0){
        throw invalid_argument("no disease in this city");
    }
    if(location == to_treat){
        Player::treat(to_treat);
        return *this;
    }
    if(b.are_neighbors(location, to_treat)){
        b[to_treat]--;
    }
    else{
        throw invalid_argument("citys are not neighbors");
    }
    return *this;
}
// const string& GeneSplicer::role() const{

// }