#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "Map.hpp"
#include "Player.hpp"
#include "Data.hpp"
#include "Card.hpp"
// #include "Dealing.hpp"
class Control
{
public:
    Control();
    void diplayBeggingOfTheGame();
    void dealingCards();
    void validateIdentity();
    void shuffelingCards();
    void randomCardSet();
    int determinMinAge();
    void displayStarterPlayer();
    void dispalyWarzone();
    bool winCheck();
    void setPlayers();
    void displayStartOfWar();
    void cinSelectedCard();
    void playingCards();
private:
    std::vector<Player> players;
    //std::vector<Player> bazikonha;
    getData identity;
    // dealingCards playerDeck;
    // int numberOfPlayers = identity.getPlayerNumber();
    std ::unordered_map<std::string, int> deck;
    std ::vector<Card> allCards;
    Player adam;
    //Player adam2;
    int randomCard;
    Card playerCard[10];
    int starterPlayer;
    std::string warzone;
    Card selectedCard;
    std::string cardName;
};