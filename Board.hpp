#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>

namespace pandemic{
    
    class Board{
    protected:
    public:
        std::unordered_map<City,int> disease_level;
        Board();
        int& operator[](const City c);
        const int operator[](const City c) const;
        const bool is_clean();
        friend std::ostream& operator<<(std::ostream&, const Board&);
    };
}