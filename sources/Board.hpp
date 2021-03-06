#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include <unordered_set>
#include <array>

namespace pandemic{
    const int CARDS_TO_DISCOVER_CURE = 5;
    
    class Board{
    private:
        std::unordered_map<City,int> disease_level;
        std::unordered_map<City,Color> citys_colors;
        std::unordered_map<City,bool> stations;
        std::unordered_map<City,std::unordered_set<City>> _neighbors;
        std::unordered_set<int> _cards;
        std::array<bool, 4> _cure_found;

    public:
        Board();
        const std::unordered_set<int>& cards() const{
            return _cards;
        }
        bool are_neighbors(City src, City dst) {
            return _neighbors[src].contains(dst);
        }
        bool has_station(City c){
            return stations[c];
        }

        bool add_station(City to_add){
            if(stations[to_add]){
                return false;
            }
            stations[to_add] = true;
            return true;
        }

        Color get_color(City c){
            return citys_colors[c];
        }

        bool is_cure_found(Color disease) const{
            return _cure_found.at((uint)disease);
        }
        void cure_found(Color disease){
            _cure_found.at((uint)disease) = true;
        }

        int& operator[](City c);
        // const int operator[](City c) const;
        bool is_clean();
        void remove_cures(); // removes all disease discoveries, only for tests.
        friend std::ostream& operator<<(std::ostream&, const Board&);
    };
}