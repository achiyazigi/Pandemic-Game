#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
namespace pandemic{
    class Player{
    public:
        Player(Board, City);
        Player& take_card(City);
        Player& drive(City);
        Player& fly_direct(City);
        Player& fly_charter(City);
        Player& fly_shuttle(City);
        Player& discover_cure(Color);
        Player& build();
        Player& treat(City);
        virtual const std::string role() const{
            return "Player";
        }
    };
}