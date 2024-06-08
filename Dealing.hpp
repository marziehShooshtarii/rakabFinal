<<<<<<< HEAD
#include "Card.cpp"
#include <vector>
class dealingCards
{
    private:
    std::vector <Card> deck;
};
=======
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
    int numberOfPlayer = identity.getPlayerNumber();
    int randomCard;
};
#endif
>>>>>>> 10a37b3c6165781a99725dc5e57003351a18dfa0
