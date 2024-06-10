#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "Map.hpp"
#include "Player.hpp"
#include "Data.hpp"
// #include "Dealing.hpp"
class Control
{
public:
    void diplayBeggingOfTheGame();
    void dealingCards();
    void validateIdentity();
    void shuffelingCards();
    void randomCardSet();
    int determinMinAge();
    void displayStarterPlayer();


private:
    std::vector<std::string> players;
    std::vector<Player> bazikonha;
    getData identity;
    // dealingCards playerDeck;
    // int numberOfPlayers = identity.getPlayerNumber();
    std ::unordered_map<std ::string, int> deck;
    std ::vector<std::string> allCards;
    Player adam;
    int randomCard;
    std::string playerCard[10];
    int starterPlayer;
};