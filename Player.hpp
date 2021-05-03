#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <vector>
#include <unordered_set>
namespace pandemic{
    class Player{
    protected:
        Board& b;
        City location;
        std::unordered_set<City> _holds;
        std::vector<City> get_all_cards_colored(Color);
    public:
        Player(Board&, City);
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