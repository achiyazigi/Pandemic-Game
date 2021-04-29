#include <iostream>
#include "Board.hpp"
#include "City.hpp"
using namespace std;
using namespace pandemic;


/**
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board(){
    for(int c = City::Algiers; c<= City::Washington; c++){
        disease_level[(City)c] = 0;
    }
}

/**
 * @brief operator[] for changing disease level in city c
 * 
 * @param c 
 * @return int& 
 */
int& Board::operator[](const City c){
    return disease_level[c];
}

/**
 * @brief operator[] to retrieve the disease level of city c
 * 
 * @param c 
 * @return const int 
 */
const int Board::operator[](const City c) const{
    return disease_level.at(c);
}

const bool Board::is_clean(){
    for(auto& city: this->disease_level){
        if(city.second){
            return false;
        }
    }
    return true;
}

/**
 * @brief prints the board
 * 
 * @param os 
 * @param b 
 * @return ostream& 
 */
ostream& pandemic::operator<<(ostream& os, const Board& b){
    for(auto& city: b.disease_level){
        os << '(' << city.first << ',' << city.second << ')';
    }
    return os;
}