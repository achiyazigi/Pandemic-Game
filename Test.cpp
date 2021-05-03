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
#include <sstream>
#include <stdexcept>
using namespace std;



TEST_CASE("Initialization"){
    SUBCASE("Board"){

    /*  nothing to see here... ->  */                                                                                                                                                                            cout << "(\\__/)    \033[1;31mAchiya\033[0m\n(>'.'<)   \033[1;31mZigler's\033[0m\n(\")_(\")   \033[1;31mTest\033[0m" << endl;
        CHECK_NOTHROW(Board b;);
        Board b;
        CHECK(b.is_clean());
    }

    //  defining new board
    Board board;

    SUBCASE("Player"){
        CHECK_NOTHROW(Player p(board,Algiers););
    }

    //  defining new generic player
    Player player{board,Algiers};

    SUBCASE("Board Setup: Existance of all citys and operator[] well defined"){
        board[Algiers] = 1;
        board[Atlanta] = 1;
        board[Baghdad] = 1;
        board[Bangkok] = 1;
        board[Beijing] = 1;
        board[Bogota] = 1;
        board[BuenosAires] = 1;
        board[Cairo] = 1;
        board[Chennai] = 1;
        board[Chicago] = 1;
        board[Delhi] = 1;
        board[Essen] = 1;
        board[HoChiMinhCity] = 1;
        board[HongKong] = 1;
        board[Istanbul] = 1;
        board[Jakarta] = 1;
        board[Johannesburg] = 1;
        board[Karachi] = 1;
        board[Khartoum] = 1;
        board[Kinshasa] = 1;
        board[Kolkata] = 1;
        board[Lagos] = 1;
        board[Lima] = 1;
        board[London] = 1;
        board[LosAngeles] = 1;
        board[Madrid] = 1;
        board[Manila] = 1;
        board[MexicoCity] = 1;
        board[Miami] = 1;
        board[Milan] = 1;
        board[Montreal] = 1;
        board[Moscow] = 1;
        board[Mumbai] = 1;
        board[NewYork] = 1;
        board[Osaka] = 1;
        board[Paris] = 1;
        board[Riyadh] = 1;
        board[SanFrancisco] = 1;
        board[Santiago] = 1;
        board[SaoPaulo] = 1;
        board[Seoul] = 1;
        board[Shanghai] = 1;
        board[StPetersburg] = 1;
        board[Sydney] = 1;
        board[Taipei] = 1;
        board[Tehran] = 1;
        board[Tokyo] = 1;
        board[Washington] = 1;

        CHECK_EQ(board[Algiers], 1);

        stringstream os;
        CHECK_NOTHROW(os << board;);
    }
    SUBCASE("Experties: init all roles correctly"){
        CHECK_NOTHROW(Dispatcher dispatcher(board, Algiers););
        CHECK_NOTHROW(FieldDoctor fieldDoctor(board, Algiers););
        CHECK_NOTHROW(Virologist virologist(board, Algiers););
        CHECK_NOTHROW(OperationsExpert operationsExpert(board, Algiers););
        CHECK_NOTHROW(Medic medic(board, Algiers););
        CHECK_NOTHROW(GeneSplicer geneSplicer(board, Algiers););
        CHECK_NOTHROW(Researcher researcher(board, Algiers););
        CHECK_NOTHROW(Scientist scientist(board, Algiers, 4););
    }

    //  defining all role players
    Dispatcher dispatcher(board, Algiers);
    FieldDoctor fieldDoctor(board, Algiers);
    Virologist virologist(board, Algiers);
    OperationsExpert operationsExpert(board, Algiers);
    Medic medic(board, StPetersburg);
    GeneSplicer geneSplicer(board, Algiers);
    Researcher researcher(board, StPetersburg);
    Scientist scientist(board, Algiers, 4);

    // define disease level:
    board[StPetersburg] = 2;
    board[Algiers] = 1;
    board[Madrid] = 1;
    board[Washington] = 1;
    SUBCASE("Check if role Methods implemented well"){

        // scientist takes 4 cards (Black):
        scientist.take_card(Algiers)
                .take_card(Baghdad)
                .take_card(Cairo)
                .take_card(Chennai);
        CHECK_NOTHROW(operationsExpert.build()); // operationExpert builds in Algiers
        CHECK_NOTHROW(dispatcher.fly_direct(StPetersburg)); // dispatcher doesn't need card to fly
        CHECK_NOTHROW(scientist.discover_cure(Black);); // scientist throws 4 cards
        CHECK_THROWS(researcher.discover_cure(Blue);); // researcher doesn't have cards

        // researcher takes 5 cards (Blue):
        researcher.take_card(Atlanta)
                  .take_card(Chicago)
                  .take_card(Essen)
                  .take_card(London)
                  .take_card(Madrid);
        CHECK_EQ(board[StPetersburg], 2);
        CHECK_NOTHROW(researcher.discover_cure(Blue).treat(StPetersburg);); // researcher can discover even though there is no station
        CHECK_EQ(board[StPetersburg], 0);

        // define disease level:
        board[StPetersburg] = 2;

        CHECK_EQ(board[StPetersburg], 2);
        CHECK_NOTHROW(medic.treat(StPetersburg);); // medic treats completly
        CHECK_EQ(board[StPetersburg], 0);

        CHECK_EQ(board[Washington], 1);
        CHECK_NOTHROW(virologist.treat(Washington)); // virologist can treat from distance
        CHECK_EQ(board[Washington], 0);

        // geneSplicer takes 5 cards different colors:
        geneSplicer.take_card(Milan) // Blue
                   .take_card(Bangkok) // Red
                   .take_card(Beijing) // Red
                   .take_card(Bogota) // Yellow
                   .take_card(Delhi); // Black
        CHECK_NOTHROW(geneSplicer.discover_cure();); // geneSplicer can cure with different color cards

        CHECK_EQ(board[Madrid], 1);
        CHECK_NOTHROW(fieldDoctor.treat(Madrid);); // fieldDoctor can treat neighbor city disease
        CHECK_EQ(board[Madrid], 0);
    
    }
    // defining array of players:
    Player *players[] = {&dispatcher,
                         &fieldDoctor,
                         &operationsExpert,
                         &scientist,
                         &researcher,
                         &medic,
                         &virologist,
                         &geneSplicer};

    SUBCASE("Check if role() can be called on &Player"){
        string last_role = "";
        for(auto& p: players){
            CHECK_NE(p->role(), last_role);
            // cout << p->role() << endl;
            /*  ^ should print (Example):
                            Dispatcher
                            FieldDoctor
                            OperationsExpert
                            Scientist
                            Researcher
                            Medic
                            Virologist
                            GeneSplicer */
            last_role = p->role();
        }
    }
}
TEST_CASE("Basic player functionality"){
    Board board;
    CHECK(board.is_clean()); // new board
    Player player{board, Algiers};


    // player takes 5 cards (Black):
    player.take_card(Algiers)
        .take_card(Baghdad)
        .take_card(Cairo)
        .take_card(Chennai)
        .take_card(Delhi);


    SUBCASE("Moving by rules"){

        // drive
        CHECK_NOTHROW(player.drive(Madrid);); // player drive to neighbor city
        CHECK_THROWS(player.drive(Lima);); // player can't move to distanced city
        CHECK_NOTHROW(player.drive(Algiers).drive(Madrid);); // player drive to neighbor city and back

        // fly_direct
        CHECK_THROWS(player.fly_direct(Lima);); // player doesn't hold that card
        CHECK_NOTHROW(player.fly_direct(Cairo);); // player holds that card
        CHECK_NOTHROW(player.fly_direct(Chennai).fly_direct(Delhi)); // player fly_direct twice
        CHECK_THROWS(player.fly_direct(Algiers).fly_direct(Delhi)); // player doesn't hold that 2nd card
        CHECK_THROWS(player.fly_direct(Baghdad).fly_direct(Baghdad)); // player doesn't hold that 2nd card

        // player takes 5 cards (Black):
        player.take_card(Algiers)
            .take_card(Baghdad)
            .take_card(Cairo)
            .take_card(Chennai)
            .take_card(Delhi);

        // player fly back to Algiers:
        player.fly_direct(Algiers);

        // fly_charter
        CHECK_THROWS(player.fly_charter(Lima);); // player doesn't hold his place card
        CHECK_THROWS(player.fly_charter(Baghdad);); // player doesn't hold his place card
        CHECK_THROWS(player.fly_charter(Algiers);); // player doesn't hold his place card

        player.drive(Cairo); // player drive to neighbor city

        CHECK_NOTHROW(player.fly_charter(Algiers);); // player throws his place card

        player.take_card(Algiers)
              .take_card(Cairo); // player takes those cards back
        
        CHECK_THROWS(player.fly_charter(Algiers).fly_charter(Cairo)); // order is wrong here

        player.take_card(Algiers); // player takes back this card

        CHECK_NOTHROW(player.fly_charter(Cairo).fly_charter(Algiers)); // fly_charter and back

        // fly_shuttle
        CHECK_THROWS(player.fly_shuttle(Delhi);); // no station in this city
        player.build().fly_direct(Delhi).build(); // player builds in 2 citys (Algiers, Delhi)
        CHECK_NOTHROW(player.fly_shuttle(Algiers);); // player fly_shuttle to Algiers
        CHECK_NOTHROW(player.fly_shuttle(Delhi).fly_shuttle(Algiers);); // player fly_shuttle to Delhi and back
    }

    SUBCASE("discover, treat, build functionality"){
        board[Algiers] = 5;
        board[Paris] = 3;
        board[Cairo] = 2;

        // player takes 6 cards (Black):
        player.take_card(Algiers)
            .take_card(Baghdad)
            .take_card(Cairo)
            .take_card(Chennai)
            .take_card(Delhi)
            .take_card(Istanbul);

        CHECK_THROWS(player.discover_cure(Black);); // there is no station in Algiers yet
        CHECK_NOTHROW(player.build();); // builds station in Algiers, throw Algiers card

        CHECK_EQ(board[Algiers], 5);
        CHECK_NOTHROW(player.discover_cure(Black);); // player throws 5 black cards
        CHECK_NOTHROW(player.treat(Algiers);); // remove all disease level 5 to 0
        CHECK_EQ(board[Algiers], 0);

        CHECK_NOTHROW(player.drive(Cairo).treat(Cairo).treat(Cairo);); // moving to neighbor city and treating twice
        CHECK_EQ(board[Cairo], 0);
        CHECK_THROWS(player.treat(Cairo);); // can't treat a healthy city

        CHECK_EQ(board[Paris], 3);
        CHECK_NOTHROW(player.drive(Algiers).drive(Paris).treat(Paris);); // navigating to paris through Algiers and treating
        CHECK_EQ(board[Paris], 2);
    }

    SUBCASE("OperationExpert Functionality"){
        
    }
    SUBCASE("Dispatcher Functionality"){

    }
    SUBCASE("Scientist Functionality"){

    }
    SUBCASE("Researcher Functionality"){

    }
    SUBCASE("Medic Functionality"){

    }
    SUBCASE("Virologist Functionality"){

    }
    SUBCASE("GeneSplicer Functionality"){

    }
    SUBCASE("FieldDoctor Functionality"){

    }
}

TEST_CASE("Game Simulation"){
    Board board;

    //  defining all role players
    Dispatcher dispatcher(board, Washington); // Blue
    FieldDoctor fieldDoctor(board, HoChiMinhCity); // Red
    Virologist virologist(board, Montreal); // Blue
    OperationsExpert operationsExpert(board, Santiago); // Yellow
    Medic medic(board, StPetersburg); // Blue
    GeneSplicer geneSplicer(board, Algiers); // Black
    Researcher researcher(board, StPetersburg); // Blue
    Scientist scientist(board, Jakarta, 4); // Red

    // defining disease levels:
    board[Algiers] = 1; // Black
    board[Atlanta] = 1; // Blue
    board[Baghdad] = 2; // Black
    board[Bangkok] = 2; // Red
    board[Beijing] = 2; // Red
    board[Bogota] = 2; // Yellow
    board[BuenosAires] = 2; // Yellow

    // Game Starts
    // each turn each player takes 3 cards and has 4 actions to do

    // "turn 1 : Dispatcher's turn"
        // location: Washington
        CHECK_EQ(board[Algiers], 1);
        CHECK_NOTHROW(
            dispatcher.take_card(Algiers) // Black
                    .take_card(Atlanta) // Blue
                    .take_card(Jakarta) // Black
                    .fly_direct(Algiers) // throws 1 card
                    .treat(Algiers);
        );

        CHECK_EQ(board[Algiers], 0);
        CHECK_THROWS(dispatcher.treat(Algiers);); // no disease in Algiers

        CHECK_NOTHROW(
            dispatcher.drive(Istanbul)
                      .drive(Baghdad);
        );
    
    // "turn 2 : FieldDoctor's turn"
        // location: HoChiMinhCity
        CHECK_NOTHROW(fieldDoctor.take_card(Bangkok)
                                 .take_card(Beijing)
                                 .take_card(Bogota)
                                 .treat(Bangkok)
                                 .treat(Bangkok)
                                 .fly_direct(Beijing) // throws 1 card
                                 .treat(Beijing);
        );
        CHECK_EQ(board[Bangkok], 0);
        CHECK_EQ(board[Beijing], 1);
    
    //"turn 3 : Virologist's turn"
        // location: Montreal
        CHECK_NOTHROW(virologist.take_card(BuenosAires)
                                 .take_card(Cairo)
                                 .take_card(Chennai)
                                 .treat(BuenosAires) // throws 1 card
                                 .drive(Chicago)
                                 .drive(Atlanta)
                                 .treat(Atlanta); // throws 1 card
        );
        CHECK_EQ(board[BuenosAires], 1);
        CHECK_EQ(board[Atlanta], 0);
    
    //"turn 4 : OperationsExpert's turn"
        // location: Santiago
        CHECK_NOTHROW(operationsExpert.take_card(Chicago)
                                 .take_card(Delhi)
                                 .take_card(Essen)
                                 .drive(Lima)
                                 .drive(Bogota)
                                 .build() // not throwing any card, station in Bogota!
                                 .treat(Bogota); // throws 1 card
        );
        CHECK_EQ(board[Bogota], 1);
    
    //"turn 5 : Medic's turn"
        // location: StPetersburg
        CHECK_NOTHROW(medic.take_card(Baghdad)
                                 .take_card(HongKong)
                                 .take_card(Istanbul)
                                 .drive(Istanbul)
                                 .drive(Baghdad)
                                 .treat(Baghdad)
                                 .build(); // throws 1 card, station in Bagdhad!
        );
        CHECK_EQ(board[Baghdad], 0);

    //"turn 6 : GeneSplicer's turn"
        // location: Algiers
        CHECK_NOTHROW(geneSplicer.take_card(HoChiMinhCity)
                                 .take_card(Johannesburg)
                                 .take_card(Karachi)
                                 .fly_direct(HoChiMinhCity) // throws 1 card
                                 .drive(HongKong)
                                 .drive(Shanghai)
                                 .drive(Beijing);
        );

    //"turn 7 : Researcher's turn"
        // location: StPetersburg
        CHECK_NOTHROW(researcher.take_card(Khartoum)
                                 .take_card(Kinshasa)
                                 .take_card(Kolkata)
                                 .fly_direct(Kinshasa) // throws 1 card
                                 .drive(Lagos)
        );
        CHECK_THROWS(researcher.discover_cure(Yellow);); // doesn't hold 5 yellow cards
                                 
        CHECK_NOTHROW(researcher.drive(SaoPaulo)
                                .drive(BuenosAires);
        );
    
    //"turn 8 : Scientist's turn"
        // location: Jakarata
        CHECK_NOTHROW(scientist.take_card(Lagos)
                                 .take_card(Lima)
                                 .take_card(London)
                                 .fly_direct(Lima) // throws 1 card
                                 .drive(Bogota)
                                 .treat(Bogota)
                                 .drive(BuenosAires)
        );
        CHECK_EQ(board[Bogota], 0);

    // "turn 9 : Dispatcher's turn"
        // location: Baghdad
        // holds: Atlanta, Jakarta
        CHECK_NOTHROW(
            dispatcher.take_card(LosAngeles) 
                    .take_card(Madrid) 
                    .take_card(Manila) 
                    .fly_direct(Madrid) // doesn't throw card! station in Baghdad!
                    .build() // throws 1 card, station in Madrid!
                    .drive(NewYork)
                    .drive(Washington);
        );

    // "turn 10 : FieldDoctor's turn"
        // location: Beijing
        // holds: Bangkok, Bogota
        CHECK_NOTHROW(fieldDoctor.take_card(MexicoCity)
                                 .take_card(Miami)
                                 .take_card(Milan)
                                 .treat(Beijing)
                                 .drive(Seoul)
                                 .drive(Tokyo)
                                 .drive(SanFrancisco);
        );
        CHECK_EQ(board[Beijing], 0);
    //"turn 11 : Virologist's turn"
        // location: Atlanta
        // holds: Cairo, Chennai
        CHECK_NOTHROW(virologist.take_card(Montreal)
                                 .take_card(Moscow)
                                 .take_card(Mumbai)
                                 .drive(Chicago)
                                 .drive(Montreal)
                                 .build(); // throws 1 card, station in Montreal!
                                 //skiping 1 action turn
        );
    //"turn 12 : OperationsExpert's turn"
        // location: Bogota
        //holds: Chicago, Delhi, Essen
        CHECK_NOTHROW(operationsExpert.take_card(NewYork)
                                 .take_card(Osaka)
                                 .take_card(Paris)
                                 .drive(SaoPaulo)
                                 .drive(BuenosAires)
                                 .treat(BuenosAires);
        );
        CHECK_EQ(board[BuenosAires], 0);
    
    // all diseases have been cured!
    CHECK(board.is_clean());
}