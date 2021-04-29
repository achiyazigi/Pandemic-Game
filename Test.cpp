#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;


TEST_CASE("Initialization"){
    /*  nothing to see here... ->  */                                                                                                                                                                            cout << "(\\__/)    \033[1;31mAchiya\033[0m\n(>'.'<)   \033[1;31mZigler's\033[0m\n(\")_(\")   \033[1;31mTest\033[0m" << endl;
    SUBCASE("Board"){
        CHECK_NOTHROW(Board b;);
    }
    Board board;
    SUBCASE("Player"){
        CHECK_NOTHROW(Player p(board,Algiers););
    }
    Player player{board,Algiers};
    SUBCASE("Board Setup"){
        board[Algiers] = 1
    }

}