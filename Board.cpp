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
    for(size_t i = 0; i < 4; i++){
        _cure_found[i] = false;
    }
    City city;
    for(size_t i = Algiers; i <= Washington; i++){
        _cards.insert(i);
        stations[(City)i] = false;
    }

    _neighbors[Algiers].insert({Madrid, Paris, Istanbul, Cairo});
    _neighbors[Atlanta].insert({Chicago, Miami, Washington});
    _neighbors[Baghdad].insert({Tehran, Istanbul, Cairo, Riyadh, Karachi});
    _neighbors[Bangkok].insert({Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong});
    _neighbors[Beijing].insert({Shanghai, Seoul});
    _neighbors[Bogota].insert({MexicoCity, Lima, Miami, SaoPaulo, BuenosAires});
    _neighbors[BuenosAires].insert({Bogota, SaoPaulo});
    _neighbors[Cairo].insert({Algiers, Istanbul, Baghdad, Khartoum, Riyadh});
    _neighbors[Chennai].insert({Mumbai, Delhi, Kolkata, Bangkok, Jakarta});
    _neighbors[Chicago].insert({SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal});
    _neighbors[Delhi].insert({Tehran, Karachi, Mumbai, Chennai, Kolkata});
    _neighbors[Essen].insert({London, Paris, Milan, StPetersburg});
    _neighbors[HoChiMinhCity].insert({Jakarta, Bangkok, HongKong, Manila});
    _neighbors[HongKong].insert({Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei});
    _neighbors[Istanbul].insert({Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow});
    _neighbors[Jakarta].insert({Chennai, Bangkok, HoChiMinhCity, Sydney});
    _neighbors[Johannesburg].insert({Kinshasa, Khartoum});
    _neighbors[Karachi].insert({Tehran, Baghdad, Riyadh, Mumbai, Delhi});
    _neighbors[Khartoum].insert({Cairo, Lagos, Kinshasa, Johannesburg});
    _neighbors[Kinshasa].insert({Lagos, Khartoum, Johannesburg});
    _neighbors[Kolkata].insert({Delhi, Chennai, Bangkok, HongKong});
    _neighbors[Lagos].insert({SaoPaulo, Khartoum, Kinshasa});
    _neighbors[Lima].insert({MexicoCity, Bogota, Santiago});
    _neighbors[London].insert({NewYork, Madrid, Essen, Paris});
    _neighbors[LosAngeles].insert({SanFrancisco, Chicago, MexicoCity, Sydney});
    _neighbors[Madrid].insert({London, NewYork, Paris, SaoPaulo, Algiers});
    _neighbors[Manila].insert({Taipei, SanFrancisco, HoChiMinhCity, Sydney});
    _neighbors[MexicoCity].insert({LosAngeles, Chicago, Miami, Lima, Bogota});
    _neighbors[Miami].insert({Atlanta, MexicoCity, Washington, Bogota});
    _neighbors[Milan].insert({Essen, Paris, Istanbul});
    _neighbors[Montreal].insert({Chicago, Washington, NewYork});
    _neighbors[Moscow].insert({StPetersburg, Istanbul, Tehran});
    _neighbors[Mumbai].insert({Karachi, Delhi, Chennai});
    _neighbors[NewYork].insert({Montreal, Washington, London, Madrid});
    _neighbors[Osaka].insert({Taipei, Tokyo});
    _neighbors[Paris].insert({Algiers, Essen, Madrid, Milan, London});
    _neighbors[Riyadh].insert({Baghdad, Cairo, Karachi});
    _neighbors[SanFrancisco].insert({LosAngeles, Chicago, Tokyo, Manila});
    _neighbors[Santiago].insert({Lima});
    _neighbors[SaoPaulo].insert({Bogota, BuenosAires, Lagos, Madrid});
    _neighbors[Seoul].insert({Beijing, Shanghai, Tokyo});
    _neighbors[Shanghai].insert({Beijing, HongKong, Taipei, Seoul, Tokyo});
    _neighbors[StPetersburg].insert({Essen, Istanbul, Moscow});
    _neighbors[Sydney].insert({Jakarta, Manila, LosAngeles});
    _neighbors[Taipei].insert({Shanghai, HongKong, Osaka, Manila});
    _neighbors[Tehran].insert({Baghdad, Moscow, Karachi, Delhi});
    _neighbors[Tokyo].insert({Seoul, Shanghai, Osaka, SanFrancisco});
    _neighbors[Washington].insert({Atlanta, NewYork, Montreal, Miami}); 
    
    citys_colors[Algiers] = Black;
    citys_colors[Atlanta] = Blue;
    citys_colors[Baghdad] = Black;
    citys_colors[Bangkok] = Red;
    citys_colors[Beijing] = Red;
    citys_colors[Bogota] = Yellow;
    citys_colors[BuenosAires] = Yellow;
    citys_colors[Cairo] = Black;
    citys_colors[Chennai] = Black;
    citys_colors[Chicago] = Blue;
    citys_colors[Delhi] = Black;
    citys_colors[Essen] = Blue;
    citys_colors[HoChiMinhCity] = Red;
    citys_colors[HongKong] = Red;
    citys_colors[Istanbul] = Black;
    citys_colors[Jakarta] = Red;
    citys_colors[Johannesburg] = Yellow;;
    citys_colors[Karachi] = Black;
    citys_colors[Khartoum] = Yellow;
    citys_colors[Kinshasa] = Yellow;
    citys_colors[Kolkata] = Black;
    citys_colors[Lagos] = Yellow;
    citys_colors[Lima] = Yellow;
    citys_colors[London] = Blue;
    citys_colors[LosAngeles] = Yellow;
    citys_colors[Madrid] = Blue;
    citys_colors[Manila] = Red;
    citys_colors[MexicoCity] = Yellow;
    citys_colors[Miami] = Yellow;
    citys_colors[Milan] = Blue;
    citys_colors[Montreal] = Blue;
    citys_colors[Moscow] = Black;
    citys_colors[Mumbai] = Black;
    citys_colors[NewYork] = Blue;
    citys_colors[Osaka] = Red;
    citys_colors[Paris] = Blue;
    citys_colors[Riyadh] = Black;
    citys_colors[SanFrancisco] = Blue;
    citys_colors[Santiago] = Yellow;
    citys_colors[SaoPaulo] = Yellow;
    citys_colors[Seoul] = Red;
    citys_colors[Shanghai] = Red;
    citys_colors[StPetersburg] = Blue;
    citys_colors[Sydney] = Red;
    citys_colors[Taipei] = Red;
    citys_colors[Tehran] = Black;
    citys_colors[Tokyo] = Red;
    citys_colors[Washington] = Blue;
        
}

/**
 * @brief operator[] for changing disease level in city c
 * 
 * @param c 
 * @return int& 
 */
int& Board::operator[](City c){
    return disease_level[c];
}

/**
 * @brief operator[] to retrieve the disease level of city c
 * 
 * @param c 
 * @return const int 
 */
// const int Board::operator[](City c) const{
//     return disease_level.at(c);
// }

const bool Board::is_clean(){
    for(auto& city: this->disease_level){
        if(city.second){
            return false;
        }
    }
    return true;
}

void Board::remove_cure(){
    for(size_t i = 0; i < 4; i++){
        _cure_found[i] = false;
    }
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