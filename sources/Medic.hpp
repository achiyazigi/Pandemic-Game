#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class Medic: public Player{
    public:

        Medic(Board& b, City c):Player(b, c){} 

        Medic& drive(City);
        Medic& fly_direct(City);
        Medic& fly_charter(City);
        Medic& fly_shuttle(City);
        Medic& treat(City);
        std::string role() const{
            return "Medic";
        }
    };
}