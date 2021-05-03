#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class GeneSplicer: public Player{
    public:
        GeneSplicer(Board& b, City c):Player(b, c){} 
        GeneSplicer& discover_cure();
        const std::string role() const{
            return "GeneSplicer";
        }
    };
}