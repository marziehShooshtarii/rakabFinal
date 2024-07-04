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
#include "Help.hpp"
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
    void diplayBeggingOfTheGame();
    void dealingCards();
    void validateIdentity();
    void shuffelingCards();
    void randomCardSet();
    int determinMinAge();
    void displayStarterPlayer();
    void displayWarzone();
    void setPlayers();
    void displayStartOfWar();
    int cinSelectedCard(int index);
    bool playingInput();
    bool playingCards(int index, int checkForMatarsak);
    bool checkIfAllPlayersPassed();
    bool checkIfCertianPlayerPassed(int index);
    void controlTurn();
    std::string determinWinnerOfWar();
    std::string findMaxScoreCard();
    int countZemestan(int index);
    int countTabl_zan(int index);
    int countBahar(int index);
    int countShir_dokht(int index);
    int countMatarsak(int index);
    int countAllSpecialCards(int index);
    void initializeSpecialCards();
    void effectOfMatarsak(Card played, int index);
    int findSelectedCardForMatarsak(std::string, int index);
    bool ifMaxScoreCardIsInHand(int index);
    bool checkWin(int index);
    bool checkingTheNeighborhoodOfTwoStates(int index, int first, int second);
    void displayPlayingCards(int index);
    void displayPlayedCards(int index);
    bool searchForExistingCards(int index, Card searchingCard);
    bool searchForExistingStates(std::string);
    bool checkMatarsakPlayed(int index);
    bool checkIfItsTimeToDealHands();
    int lastPlayerWithRemainedCards();
    int findMatarsak(int i);
    void startOfWarMassage();
    std::string help(std::string);
    std::string cinTypeOfHelp();
    void displayOwenedStates();
    bool checkCardsForMatarsak(int index);
    void run();

private:
    std::vector<Player> players;
    getData identity;
    std ::unordered_map<std::string, int> deck;
    std ::vector<Card> allCards;
    Player adam;
    int randomCard;
    Card playerCard[10];
    int starterPlayer = 0;
    std::string warzone = "bella";
    Card selectedCard;
    std::string cardName;
    int turn = 1;
    armyCard army;
    std::vector<Special *> specialCards;
    int maxScore = -1;
    int counterNeighbores = 0;
    std::string winnerOfGame;
    int winner = -3;
    std::vector<Card> baharVSzemestan;
};