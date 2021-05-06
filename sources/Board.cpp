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
    for(int c = (int)City::Algiers; c<= (int)City::Washington; c++){
        disease_level[(City)c] = 0;
    }
    for(size_t i = 0; i < 4; i++){
        _cure_found[i] = false;
    }
    City city;
    for(size_t i = (int)City::Algiers; i <= (int)City::Washington; i++){
        _cards.insert(i);
        stations[(City)i] = false;
    }

    _neighbors[City::Algiers].insert({City::Madrid, City::Paris, City::Istanbul, City::Cairo});
    _neighbors[City::Atlanta].insert({City::Chicago, City::Miami, City::Washington});
    _neighbors[City::Baghdad].insert({City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi});
    _neighbors[City::Bangkok].insert({City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong});
    _neighbors[City::Beijing].insert({City::Shanghai, City::Seoul});
    _neighbors[City::Bogota].insert({City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires});
    _neighbors[City::BuenosAires].insert({City::Bogota, City::SaoPaulo});
    _neighbors[City::Cairo].insert({City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh});
    _neighbors[City::Chennai].insert({City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta});
    _neighbors[City::Chicago].insert({City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal});
    _neighbors[City::Delhi].insert({City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata});
    _neighbors[City::Essen].insert({City::London, City::Paris, City::Milan, City::StPetersburg});
    _neighbors[City::HoChiMinhCity].insert({City::Jakarta, City::Bangkok, City::HongKong, City::Manila});
    _neighbors[City::HongKong].insert({City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei});
    _neighbors[City::Istanbul].insert({City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow});
    _neighbors[City::Jakarta].insert({City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney});
    _neighbors[City::Johannesburg].insert({City::Kinshasa, City::Khartoum});
    _neighbors[City::Karachi].insert({City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi});
    _neighbors[City::Khartoum].insert({City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg});
    _neighbors[City::Kinshasa].insert({City::Lagos, City::Khartoum, City::Johannesburg});
    _neighbors[City::Kolkata].insert({City::Delhi, City::Chennai, City::Bangkok, City::HongKong});
    _neighbors[City::Lagos].insert({City::SaoPaulo, City::Khartoum, City::Kinshasa});
    _neighbors[City::Lima].insert({City::MexicoCity, City::Bogota, City::Santiago});
    _neighbors[City::London].insert({City::NewYork, City::Madrid, City::Essen, City::Paris});
    _neighbors[City::LosAngeles].insert({City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney});
    _neighbors[City::Madrid].insert({City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers});
    _neighbors[City::Manila].insert({City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney});
    _neighbors[City::MexicoCity].insert({City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota});
    _neighbors[City::Miami].insert({City::Atlanta, City::MexicoCity, City::Washington, City::Bogota});
    _neighbors[City::Milan].insert({City::Essen, City::Paris, City::Istanbul});
    _neighbors[City::Montreal].insert({City::Chicago, City::Washington, City::NewYork});
    _neighbors[City::Moscow].insert({City::StPetersburg, City::Istanbul, City::Tehran});
    _neighbors[City::Mumbai].insert({City::Karachi, City::Delhi, City::Chennai});
    _neighbors[City::NewYork].insert({City::Montreal, City::Washington, City::London, City::Madrid});
    _neighbors[City::Osaka].insert({City::Taipei, City::Tokyo});
    _neighbors[City::Paris].insert({City::Algiers, City::Essen, City::Madrid, City::Milan, City::London});
    _neighbors[City::Riyadh].insert({City::Baghdad, City::Cairo, City::Karachi});
    _neighbors[City::SanFrancisco].insert({City::LosAngeles, City::Chicago, City::Tokyo, City::Manila});
    _neighbors[City::Santiago].insert({City::Lima});
    _neighbors[City::SaoPaulo].insert({City::Bogota, City::BuenosAires, City::Lagos, City::Madrid});
    _neighbors[City::Seoul].insert({City::Beijing, City::Shanghai, City::Tokyo});
    _neighbors[City::Shanghai].insert({City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo});
    _neighbors[City::StPetersburg].insert({City::Essen, City::Istanbul, City::Moscow});
    _neighbors[City::Sydney].insert({City::Jakarta, City::Manila, City::LosAngeles});
    _neighbors[City::Taipei].insert({City::Shanghai, City::HongKong, City::Osaka, City::Manila});
    _neighbors[City::Tehran].insert({City::Baghdad, City::Moscow, City::Karachi, City::Delhi});
    _neighbors[City::Tokyo].insert({City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco});
    _neighbors[City::Washington].insert({City::Atlanta, City::NewYork, City::Montreal, City::Miami}); 
    
    citys_colors[City::Algiers] = Color::Black;
    citys_colors[City::Atlanta] = Color::Blue;
    citys_colors[City::Baghdad] = Color::Black;
    citys_colors[City::Bangkok] = Color::Red;
    citys_colors[City::Beijing] = Color::Red;
    citys_colors[City::Bogota] = Color::Yellow;
    citys_colors[City::BuenosAires] = Color::Yellow;
    citys_colors[City::Cairo] = Color::Black;
    citys_colors[City::Chennai] = Color::Black;
    citys_colors[City::Chicago] = Color::Blue;
    citys_colors[City::Delhi] = Color::Black;
    citys_colors[City::Essen] = Color::Blue;
    citys_colors[City::HoChiMinhCity] = Color::Red;
    citys_colors[City::HongKong] = Color::Red;
    citys_colors[City::Istanbul] = Color::Black;
    citys_colors[City::Jakarta] = Color::Red;
    citys_colors[City::Johannesburg] = Color::Yellow;;
    citys_colors[City::Karachi] = Color::Black;
    citys_colors[City::Khartoum] = Color::Yellow;
    citys_colors[City::Kinshasa] = Color::Yellow;
    citys_colors[City::Kolkata] = Color::Black;
    citys_colors[City::Lagos] = Color::Yellow;
    citys_colors[City::Lima] = Color::Yellow;
    citys_colors[City::London] = Color::Blue;
    citys_colors[City::LosAngeles] = Color::Yellow;
    citys_colors[City::Madrid] = Color::Blue;
    citys_colors[City::Manila] = Color::Red;
    citys_colors[City::MexicoCity] = Color::Yellow;
    citys_colors[City::Miami] = Color::Yellow;
    citys_colors[City::Milan] = Color::Blue;
    citys_colors[City::Montreal] = Color::Blue;
    citys_colors[City::Moscow] = Color::Black;
    citys_colors[City::Mumbai] = Color::Black;
    citys_colors[City::NewYork] = Color::Blue;
    citys_colors[City::Osaka] = Color::Red;
    citys_colors[City::Paris] = Color::Blue;
    citys_colors[City::Riyadh] = Color::Black;
    citys_colors[City::SanFrancisco] = Color::Blue;
    citys_colors[City::Santiago] = Color::Yellow;
    citys_colors[City::SaoPaulo] = Color::Yellow;
    citys_colors[City::Seoul] = Color::Red;
    citys_colors[City::Shanghai] = Color::Red;
    citys_colors[City::StPetersburg] = Color::Blue;
    citys_colors[City::Sydney] = Color::Red;
    citys_colors[City::Taipei] = Color::Red;
    citys_colors[City::Tehran] = Color::Black;
    citys_colors[City::Tokyo] = Color::Red;
    citys_colors[City::Washington] = Color::Blue;
        
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

void Board::remove_cures(){
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
    os << "disease levels: " << endl;
    for(auto& city: b.disease_level){
        os << '(' << (int)city.first << ',' << (int)city.second << ')';
    }
    os<<endl;
    os << "cures found:" << endl;
    for (size_t i = 0; i < 4; i++)
    {
        os << boolalpha << "(" << i << "," << b.is_cure_found((Color)i) << ") ";
    }
    
    return os;
}