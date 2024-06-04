#ifndef DEALING_HPP
#define DEALING_HPP
#include "Army.cpp"
#include "Special.cpp"
#include "Player.cpp"
#include "Data.cpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
class dealingCards
{
public:
    dealingCards();
    bool setDealing();
    // void setPlayerCard();
    // bool setValidNumberOfCards();
    int randomCardSet();
    void shuffelingCards();

private:
    std::vector<armyCard> armyDeck;
    std::vector<Special> specialDeck;
    std::vector<Player> Players;
    std ::vector<std::string> allCards;
    std::unordered_map<int, std::string> mapLand;
    std ::unordered_map<std ::string, int> deck;
    std::ifstream dealingFile;
    std::ifstream valueCard;
    std::string playerCard[10];
    std::string Land;
    int randomCard;
    int validNumberOfCards[15];
};
#endif