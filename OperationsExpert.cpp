#include "OperationsExpert.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

OperationsExpert& OperationsExpert::build(){
    if(!b.add_station(location)){
        throw invalid_argument("there is a station here already");
    }
    return *this;
}
// const string& OperationsExpert::role() const{

// }
