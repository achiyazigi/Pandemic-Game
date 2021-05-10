#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Dispatcher: public Player{
    public:
        Dispatcher(Board& b, City c):Player(b, c){} 
        Dispatcher& fly_direct(City);
        std::string role() const{
            return "Dispatcher";
        }
    };
}