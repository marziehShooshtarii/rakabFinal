#ifndef DEALING_HPP
#define DEALING_HPP
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include "Data.hpp"
#include "Special.hpp"
#include "Army.hpp"

class dealingCards
{
public:
    dealingCards();
    bool setDealing();
    // void setPlayerCard();
    // bool setValidNumberOfCards();
    int randomCardSet();
    void shuffelingCards();
    void validateIdentity ();

private:
    std::vector<armyCard> armyDeck;
    std::vector<Special> specialDeck;
    std::vector<Player> Players;
    std ::vector<std::string> allCards;
    std ::unordered_map<std ::string, int> deck;
    std::ifstream dealingFile;
    std::string playerCard[10];
    getData identity;
    Player adam;
    int numberOfPlayer = identity.getPlayerNumber();
    int randomCard;
};
#endif
