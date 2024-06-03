#ifndef DEALING_HPP
#define DEALING_HPP
#include "Army.cpp"
#include "Special.cpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
class dealingCards
{
public:
dealingCards();
    bool setDealing();
    void setPlayerCard();
    //void DeciedCard();
    bool setValidNumberOfCards();
private:
    std::vector<armyCard> armyDeck;
    std::vector<Special> specialDeck;
    std::unordered_map<int, std::string> mapLand;
    std::ifstream dealingFile;
    std::ifstream valueCard;
    std::string playerCard[10];
    std::string Land;
    int randomCard;
    // Special s;
    // armyCard a;
    int validNumberOfCards [15];
};
#endif