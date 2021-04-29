#include "Virologist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Virologist& Virologist::treat(City){
    return *this;
}
const string Virologist::role() const{
    return "Virologist";
}