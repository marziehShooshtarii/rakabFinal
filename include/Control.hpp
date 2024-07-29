#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "Map.hpp"
#include "Data.hpp"
#include "Army.hpp"
#include "Tabl_zan.hpp"
#include "Bahar.hpp"
#include "Shah_dokht.hpp"
#include "Help.hpp"
#include "Shirzan.hpp"
#include "Zemestan.hpp"
#include "UI.hpp"

class Control
{
public:
    Control();
    ~Control()
    {
        save.close();
        for (auto p : armyAndSpecialCards)
        {
            delete p;
        }
        armyAndSpecialCards.clear();
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
    bool determinWinnerOfWar();
    std::string findMaxScoreCard();
    void initializeSpecialCards();
    void effectOfMatarsak(Card played, int index);
    int findSelectedCardForMatarsak(std::string, int index);
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
    bool checkProcessOfEndingWar();
    bool ifMaxScoreCardIsInHandForRishSefid(std::string, std::vector<Card> playedCards);
    void rishSefidEffect(std::vector<Card>);
    bool checkForRishSefid(std::vector<Card>);
    int shirzanCount(std::vector<Card> playedCardForShirzan);
    bool checkShirzenForCertianPlayer();
    void choiceForPeaceSign();
    bool checkForPeaceSign();
    bool validateSpecialCardsForMatarsak();
    void savePlayerInfo(int index);
    void savePlayedCardsInfo(int index);
    void savePlayerCardsInfo(int index);
    void saveBaharVSZemestan();
    void saveSigns();
    void saveStarterPlayer(int);
    void savePlayerStates(int index);
    bool saveAllInfo(int);
    void menu();
    void saveReadPlayerInfo(int index);
    void saveReadPlayerStates(int index);
    void saveReadPlayedCardsInfo(int index);
    void saveReadPlayerCardsInfo(int index);
    void saveReadBaharVSZemestan();
    void saveReadSigns();
    void saveReadStarterPlayerAndSelectedCard();
    void saveReadAllInfo();
    // bool is_empty(std::fstream& File);
    bool isFileEmpty(const std::string &filename);
    void StartNewGame();
    void initializingNumberOfSavedGames();
    bool determinNumberOfSavedGame();
    void setNameForUI(std::vector<char>);
    void setAgeForUI(std::vector<char>);
    void setNameFromUI(char names[]);
    void run();

private:
    std::vector<Player> players;
    getData identity;
    std ::unordered_map<std::string, int> deck;
    std ::vector<Card> allCards;
    int randomCard;
    Card playerCard[10];
    int starterPlayer = 0;
    std::string warzone = "bella";
    Card selectedCard;
    std::string cardName;
    int turn = 1;
    std::vector<Card *> armyAndSpecialCards;
    int maxScore = -1;
    int counterNeighbores = 0;
    std::string winnerOfGame;
    int winner = -1; //can't be the numbers which may be the player's order
    std::vector<Card> baharVSzemestan;
    std::string peaceSign;
    int numberOfwars = 0;// for controling peace sign
    std::vector<int>orderOfRishSefids;
    std::fstream save;
    std::string newOrContinue;
    std::vector <std::string> numberOfSavedGames; //having more than one saved game
    int whichSavedGame;
    UI ui;
};