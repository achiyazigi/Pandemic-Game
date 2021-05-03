#include "OperationsExpert.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

OperationsExpert& OperationsExpert::build(){
    _holds.erase(location);
    if(!b.add_station(location)){
        throw invalid_argument("not valid");
    }
    return *this;
}
// const string& OperationsExpert::role() const{

// }
