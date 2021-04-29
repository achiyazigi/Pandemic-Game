#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Researcher: public Player{
    public:
        Researcher(Board b, City c):Player(b, c){} 
        Researcher& discover_cure(Color);
        const std::string role() const{
            return "Researcher";
        }
    };
}