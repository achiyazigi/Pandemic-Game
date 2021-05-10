#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Scientist: public Player{
    private:
        int _cards_to_discover_cure;
    public:
        Scientist(Board& b, City c, int cards):Player(b,c), _cards_to_discover_cure(cards){}  
        Scientist& discover_cure(Color);
        std::string role() const{
            return "Scientist";
        }
    };
}