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
#include "Army.hpp"
#include "Special.hpp"
#include "Zemestan.hpp"
#include "Tabl_zan.hpp"
#include "Bahar.hpp"
#include "Shah_dokht.hpp"
// #include "Dealing.hpp"
class Control
{
public:
    Control();
    ~Control()
    {
        for (auto p : specialCards)
        {
            delete p;
        }
        specialCards.clear();
    }
    // Control(Zemestan z,Tabl_zan t,Bahar b,shir_dokht s)
    // {
    // std::cout <<"-> inja"<<std::endl;
    // // Zemestan z;
    // // Tabl_zan t;
    // // Bahar b;
    // // shir_dokht s;
    // specialCards[0] = &z;
    // specialCards[1] = &t;
    // specialCards[2] = &b;
    // specialCards[3] = &s;
    // std::cout <<"-> inja"<<std::endl;

    // }
    //     void initializeSpecialCards()
    // {

    // }
    void diplayBeggingOfTheGame();
    void dealingCards();
    void validateIdentity();
    void shuffelingCards();
    void randomCardSet();
    int determinMinAge();
    void displayStarterPlayer();
    void displayWarzone();
    bool winCheck();
    void setPlayers();
    void displayStartOfWar();
    bool cinSelectedCard(int index);
    bool playingInput();
    bool playingCards(int index);
    bool checkIfAllPlayersPassed();
    bool checkIfCertianPlayerPassed(int index);
    void controlTurn();
    std::string determinWinnerOfWar();
    // void setCardScores();
    std::string findMaxScoreCard();
    // int searchInCardScore(std::string str);
    //  ::unordered_map<std::string, int> cardsScore;
    //  int countTabl_zan(int index);
    //  int countBahar();
    //  int countShir_dokht();
    int countZemestan(int index);
    int countTabl_zan(int index);
    int countBahar(int index);
    int countShir_dokht(int index);
    // void setStringToSpecialCard();
    void initializeSpecialCards();
    void effectOfMatarsak(Card played, int index);
    int findSelectedCardForMatarsak(std::string, int index);
    // std ::unordered_map<std::string, int> cardsScore;
    // void setCardScores();
    // int searchInCardScore(std::string str);
    bool ifMaxScoreCardIsInHand(int index);
    bool checkWin(int index);
    void initializeMapInControl();
    bool checkingTheNeighborhoodOfTwoStates(int index,int first,int second);

private:
    std::vector<Player> players;
    // std::vector<Player> bazikonha;
    getData identity;
    // dealingCards playerDeck;
    // int numberOfPlayers = identity.getPlayerNumber();
    std ::unordered_map<std::string, int> deck;
    std ::vector<Card> allCards;
    Player adam;
    // Player adam2;
    int randomCard;
    Card playerCard[10];
    int starterPlayer = 0;
    std::string warzone = "bella";
    Card selectedCard;
    std::string cardName;
    int turn = 1;
    // std::vector<int> scorsAtEndOfWar = {0};
    // std::vector<Card>allPlayedCards;
    armyCard army;
    // void initializeSpecialCards();
    std::vector<Special *> specialCards;
    // std ::unordered_map<std::string, Card> stringToSpecialCard;
    int maxScore = 0;
    int counterNeighbores = 0;
    std::string winnerOfGame;
    int winner = -3;
    std::vector<Card> baharVSzemestan;
};