#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

FieldDoctor& FieldDoctor::treat(City to_treat){
    if(location == to_treat){
        Player::treat(to_treat);
        return *this;
    }
    if(b[to_treat] == 0){
        throw invalid_argument("no disease in this city");
    }
    if(!b.are_neighbors(location, to_treat)){
        throw invalid_argument("citys are not neighbors");
    }
    if(b.is_cure_found(b.get_color(to_treat))){
            b[to_treat] = 0;
        }
    else{
        b[to_treat]--;
    }
    return *this;
}
