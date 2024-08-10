#include <unistd.h>
#include "Control.hpp"
#include <filesystem>
Control::Control()
{
    initializingNumberOfSavedGames();
}
void Control::startOfWarMassage()
{
    std::cout << "press enter to start the war ";
}
void Control::displayStarterPlayer()
{
    std::cin.ignore();
    std::cout << identity.getName(starterPlayer) << " please choose the warzone ";
    std::cin >> warzone;
    std::cout << identity.getName(starterPlayer) << " please choose the good luck number: ";
    std::cin >> goodLuckNumber;
    std::cout << identity.getName(starterPlayer) << " please choose the bad luck number: ";
    std::cin >> badLuckNumber;
    while (!searchForExistingStates(warzone))
    {
        displayStarterPlayer();
    }
    checkForPeaceSign();
}
bool Control::checkForPeaceSign()
{
    if (numberOfwars > 0)
    {
        if (warzone == peaceSign)
        {
            std::cout << "you can't choose this state as warzone,the peace sign has been placed in this state.";
            displayStarterPlayer();
            return false;
        }
        return true;
    }
    return true;
}
void Control::displayWarzone()
{
    if (newOrContinue == "n")
        std::cout << "the selected warzone is " << warzone << " get ready for a war!!\n";
    else if (newOrContinue == "c")
        std::cout << "the warzone was " << warzone << " get ready for the rest of war!!\n";
    else
        std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
}
void Control ::displayOwenedStates()
{
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        std::cout << "@" << players[i].getName() << " : ";
        for (int j = 0; j < players[i].getNumberOfOwenedStates(); j++)
        {
            std::cout << players[i].getOwenedStates(j);
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
}
int Control::determinMinAge()
{
    int min = identity.getAge(0);
    for (int i = 1; i < identity.getPlayerNumber(); i++)
    {
        if (min > identity.getAge(i))
        {
            min = identity.getAge(i);
            starterPlayer = i;
            TurnControl = i; // starterPlayer that can be changed
        }
    }
    return starterPlayer;
}
void Control::diplayBeggingOfTheGame()
{
    std::cout << "Are you ready?!\n\tLets start the game\n";
    std::cin.ignore();
    for (size_t i = 0; i < identity.getPlayerNumber();)
    {
        std::cout << "player number " << i + 1 << "s turn " << i + 1 << "\n\tpass the laptop to player number " << i + 1 << "\t\n";
        std::cin.ignore();
        for (int k = 0; k < 10; k++)
        {
            std::cout << (players[i].getPlayerCard(k).getName()) << " ";
        }
        i++;
        std::cout << std::endl;
        std::cin.ignore();
        // system("CLS");
    }
}
void Control::dealingCards()
{
    deck = {
        {"bahar", 3},
        {"zemestan", 3},
        {"matarsak", 16},
        {"tabl_zan", 6},
        {"shah_dokht", 3},
        {"shirzan", 12},
        {"parcham_dar", 3},
        {"rish_sefid", 6},
        {"fok_sefid", 3},    // new card added
        {"rakhsh_sefid", 2}, // new card added
        {"sarbaz_1", 8},
        {"sarbaz_2", 10},
        {"sarbaz_3", 10},
        {"sarbaz_4", 10},
        {"sarbaz_5", 10},
        {"sarbaz_6", 10},
        {"sarbaz_10", 10},
    };
    for (const auto &pair : deck)
    {
        for (int i = 0; i < pair.second; ++i)
        {
            allCards.emplace_back(pair.first);
        }
    }
}
void Control::setPlayers()
{
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        players.push_back(Player(identity.getAge(i), identity.getName(i), identity.getColor(i), false));
    }
}
void Control::randomCardSet()
{

    setPlayers();

    for (int j = 0; j < identity.getPlayerNumber(); j++)
    {
        for (int i = 0; i < (10 + players[j].getNumberOfOwenedStates()); i++)
        {
            randomCard = rand() % 115;
            players[j].setPlayerCard(allCards[randomCard]);
        }
    }
    ifCardsAreSet = true;
}
void Control::validateIdentity()
{
    identity.setPlayerNumber();
    identity.setData();
    // system("CLS");
}
void Control::shuffelingCards()
{
    random_shuffle(allCards.begin(), allCards.end());
}
void Control::displayStartOfWar()
{
    std::cout << starterPlayer << "start the war by pressing enter" << std::endl;
}
int Control::playingInput()
{
    bool checkParchamDar = true;
    winner = -3;
    int indexControler = identity.getPlayerNumber();
    int i = TurnControl;

    checkSelectedCard = setPlayedCardsFromUI();
    if (checkSelectedCard == 8)
    {
        for (int j = 0; j < identity.getPlayerNumber(); j++)
            players[j].setIfPassed(true);
        checkProcessOfEndingWar();
        return 2;
    }
    if (checkSelectedCard != 5) // if player has played anything but parcham dar
    {
        if (playingCards(i, checkSelectedCard))
            return 4; // matarsak has been played
    }
    else
    {
        checkProcessOfEndingWar();
        for (int q = 0; q < identity.getPlayerNumber(); q++)
            players[q].setIfPassed(true);
        i = indexControler;
        checkParchamDar = false;
    }
    if (checkParchamDar)
        checkStatus = checkProcessOfEndingWar(); // to check the war status
    if (checkStatus == 1)
        return 1; // the winner of the game is determined
    numberOfwars++;
    if (checkStatus == 2)
        return 2; // the winner of a certain war is determined
    if (checkStatus == 3)
        return 3; // the next player has not passed yet
    if (checkStatus == 4)
        return 5; // there is no winner for this war
}
int Control::checkProcessOfEndingWar()
{
    if (!checkIfAllPlayersPassed())
    {
        if (checkSelectedCard == 8)
        {
            winner = TurnControl;
            starterPlayer = winner;
            players[winner].setOwenedStates(warzone);
            setOrderOfWinner();
        }
        else
        {
            if (determinWinnerOfWar())
                players[winner].setOwenedStates(warzone);
            else
                return 4; // there is no winner for this war
        }
        if (turn != 1)
        {
            if (checkIfItsTimeToDealHands())
            {
                for (int x = 0; x < players[lastPlayerWithRemainedCards()].getNumberOfPlayerCards(); x++)
                    players[lastPlayerWithRemainedCards()].eraseCard(x);
                shuffelingCards();
                randomCardSet();
                for (int t = 0; t < identity.getPlayerNumber(); t++)
                    displayPlayingCards(t);
            }
        }
        if (orderOfRishSefids.size() != 0) // if rish sefid has been played in the current war
            choiceForPeaceSign();

        for (int s = 0; s < identity.getPlayerNumber(); s++)
        {
            players[s].eraseAllPlayedCards();
        }
        turnHandlerAfterEachWar = 0;
        baharVSzemestan.clear();
        orderOfRishSefids.clear();
        winner = -1;
        for (int w = 0; w < identity.getPlayerNumber(); w++)
        {
            players[w].setIfPassed(false);
        }
        for (int q = 0; q < identity.getPlayerNumber(); q++)
        {
            if (players[q].getNumberOfOwenedStates() > 2)
            {
                if (checkWin(q))
                    return 1; // the winner of the game
            }
        }
        return 2; // the winner of a certain war
    }
    return 3; // not all the palyers have passed
}
void Control::setOrderOfWinner()
{
    orderOfWinners.push_back(winner);
}

void Control::choiceForPeaceSign()
{
    Map mapForPeaceSign;
    std::cout << players[orderOfRishSefids[orderOfRishSefids.size() - 1]].getName() << " please choose the state you want to place your peace sign on.";
    peaceSign = mapForPeaceSign.findKey(ui.displayWarzoneForPeacsignButtons(players[orderOfRishSefids[orderOfRishSefids.size() - 1]].getName()));
}
void Control::displayPlayingCards(int index)
{
    for (int k = 0; k < players[index].getNumberOfPlayerCards(); k++)
    {
        std::cout << (players[index].getPlayerCard(k).getName()) << " ";
    }
}
bool Control::playingCards(int index, int checkSelectedCard)
{
    if (cardName == "pass") // if player has passed
    {
        players[index].setIfPassed(true);
        checkIfCertianPlayerPassed(index);
        return false;
    }
    if (checkSelectedCard == 6) // fok sefis has been played
    {
        for (int i = 0; i < identity.getPlayerNumber(); i++)
            players[i].eraseAllPlayedCards();

        ui.eraseAllCardsAfterWar();
        return false;
    }
    if (checkSelectedCard == 7)
        return false;

    if (checkSelectedCard == 2) // if player needs help
    {
        // system("CLS");
        help(cinTypeOfHelp());
        std::cin.ignore();
        displayPlayingCards(index);
        playingCards(index, cinSelectedCard(index));
        return false;
    }
    // if (checkSelectedCard == 6)
    // {
    //     saveAllInfo(index);
    //     exit(0);
    // }
    if (checkSelectedCard != 3) // if player has played matarsak
        return true;

    if (searchForExistingCards(index, selectedCard))
    {
        for (int h = 0; h < 10; h++)
        {
            if ((players[index].getPlayerCard(h)) == selectedCard)
            {
                if (selectedCard.getName() == "bahar" || selectedCard.getName() == "zemestan")
                {
                    baharVSzemestan.push_back(selectedCard); // for controling the most recent played bahar or zemestan
                }
                if (selectedCard.getName() == "rish_sefid")
                    orderOfRishSefids.push_back(index); // for controling the most recent player who played rish sefid
                // players[index].setPlayedCard(selectedCard);
                // players[index].eraseCard(h);
                break;
            }
        }
    }
    // else
    // {
    //     std::cout << "the choosen card is not your's!\nplease choose a valid card from the list:\n";
    //     displayPlayingCards(index);
    //     playingCards(index, cinSelectedCard(index));
    // }
    return false;
}
bool Control::searchForExistingCards(int index, Card searchingCard)
{
    for (int i = 0; i < players[index].getNumberOfPlayerCards(); i++)
    {
        if (searchingCard == players[index].getPlayerCard(i))
        {
            return true;
        }
    }
    return false;
}
void Control::displayPlayedCards(int index)
{
    if (players[index].getNumberOfPlayedCards() > 0)
    {
        std::cout << "- >" << players[index].getName() << " : ";
        for (int i = 0; i < players[index].getNumberOfPlayedCards(); i++)
        {
            std::cout << players[index].getPlayedCard(i).getName() << " ";
        }
        std::cout << "\n\n";
    }
}
bool Control::checkIfAllPlayersPassed()
{
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        if (players[i].getIfPassed() == false)
        {
            return true;
        }
    }
    return false;
}
int Control::cinSelectedCard(int index)
{
    std::cin >> cardName;
    if (cardName == "pass")
    {
        cardName = "pass"; // if player passed
        return 1;
    }
    if (cardName == "help")
    {
        return 2; // if player needs help
    }
    if (cardName == "parcham_dar")
    {
        return 5; // if player has played parcham dar
    }
    if (cardName == "save")
    {
        return 6; // if player wants to save the game
    }
    if (!checkMatarsakPlayed(index))
    {
        selectedCard.setName(cardName);
        return 3; // if player has played anything but matarsak
    }
    return 4;
}
bool Control::checkMatarsakPlayed(int index)
{
    Card selectedCardForMatarsak;
    if (cardName == "matarsak")
    {
        if (players[index].getNumberOfPlayedCards() == 0)
        {
            std::cout << "you can't play matarsak before playing any other cards.please choose another card." << std::endl;
            cinSelectedCard(index);
        }
        else
        {
            std::cout << "please choose the card that you want to get back from the list." << std::endl;
            for (int i = 0; i < players[index].getNumberOfPlayedCards(); i++)
            {
                std::cout << players[index].getPlayedCard(i).getName() << std::endl;
            }
            std::cin >> cardName;
            if (checkCardsForMatarsak(index))
            {
                selectedCardForMatarsak.setName(cardName);
                effectOfMatarsak(selectedCardForMatarsak, index);
            }
            else
            {
                cardName = "matarsak";
                checkMatarsakPlayed(index);
            }
        }
        return true;
    }
    return false;
}
bool Control::checkCardsForMatarsak(int index)
{
    for (int i = 0; i < players[index].getNumberOfPlayedCards(); i++)
    {
        if (cardName == players[index].getPlayedCard(i).getName())
        {
            if (!validateSpecialCardsForMatarsak())
            {
                std::cout << "you can't use matarsak on special cards." << std::endl;
                return false;
            }
            return true;
        }
    }
    std::cout << "invalid card." << std::endl;
    return false;
}
bool Control::validateSpecialCardsForMatarsak()
{
    if (cardName == "bahar" || cardName == "zemestan" || cardName == "rish_sefid" || cardName == "parcham_dar" || cardName == "tabl_zan" || cardName == "shirzan" || cardName == "shah_dokht")
        return false;
    return true;
}
void Control::effectOfMatarsak(Card played, int index)
{
    Card matarsakCard; // for accessing Card member functions
    matarsakCard.setName("matarsak");
    players[index].setPlayerCard(played);
    players[index].erasePlayedCard(findSelectedCardForMatarsak(cardName, index));
    players[index].setPlayedCard(matarsakCard);
    players[index].eraseCard(findMatarsak(index));
}
int Control ::findMatarsak(int i)
{
    for (int j = 0; j < players[i].getNumberOfPlayerCards(); j++)
    {
        if (players[i].getPlayerCard(j).getName() == "matarsak")
        {
            return j;
        }
    }
}
int Control ::findSelectedCardForMatarsak(std::string str, int index)
{
    for (int i = 0; i < players[index].getNumberOfPlayedCards(); i++)
    {
        if (str == players[index].getPlayedCard(i).getName())
        {
            return i;
        }
    }
}
bool Control::checkIfCertianPlayerPassed(int i)
{
    if (players[i].getIfPassed())
    {
        std::cout << players[i].getName() << " you can't play any cards; you have passe\npress ENTER and pass the lap top to the next player" << std::endl;
        return true;
    }
    return false;
}
void Control::controlTurn()
{
    turn++;
}
std ::string Control::findMaxScoreCard()
{
    Card card; // for accesing Card member functions
    std ::string maxScoreCardName;
    for (int k = 0; k < identity.getPlayerNumber(); k++)
    {
        if (players[k].getNumberOfPlayedCards() != 0)
        {
            maxScore = card.searchInCardScore(players[k].getPlayedCard(0).getName());
            maxScoreCardName = players[k].getPlayedCard(0).getName();
            break;
        }
    }
    for (int j = 0; j < identity.getPlayerNumber(); j++)
    {
        if (players[j].getNumberOfPlayedCards() == 0)
        {
            j++;
            if (j == identity.getPlayerNumber())
            {
                return maxScoreCardName;
            }
        }
        for (int i = 0; i < players[j].getNumberOfPlayedCards(); i++)
        {
            if (maxScore < card.searchInCardScore(players[j].getPlayedCard(i).getName()))
            {
                maxScore = card.searchInCardScore(players[j].getPlayedCard(i).getName());
                maxScoreCardName = players[j].getPlayedCard(i).getName();
            }
        }
    }
    return maxScoreCardName;
}
void Control::rishSefidEffect(std::vector<Card> cardsForRishSefid)
{
    std::string maxScoreForRishSefid = findMaxScoreCard();
    if (checkForRishSefid(cardsForRishSefid)) // in case rish sefid is found in a certain player's hand
    {
        for (int g = 0; g < identity.getPlayerNumber(); g++)
        {
            if (ifMaxScoreCardIsInHandForRishSefid(findMaxScoreCard(), players[g].getAllPlayedCards()))
            {
                for (int k = 0; k < players[g].getNumberOfPlayedCards(); k++)
                {
                    if (maxScoreForRishSefid == players[g].getPlayedCard(k).getName())
                    {
                        players[g].erasePlayedCard(k);
                    }
                }
            }
        }
    }
}
bool Control::checkForRishSefid(std::vector<Card> playedCardsForRishSefid)
{
    for (int i = 0; i < playedCardsForRishSefid.size(); i++)
    {
        if (playedCardsForRishSefid[i].getName() == "rish_sefid")
        {
            return true;
        }
    }
    return false; // in case rish sefid is not found in a certain player's hand
}
bool Control::determinWinnerOfWar()
{
    std::vector<int> scorsAtEndOfWar(identity.getPlayerNumber());
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        scorsAtEndOfWar[i] = 0;
    }
    int winnerScore = 0;
    winner = -1;
    // effect of rish_sefid as the first priority
    for (int q = 0; q < identity.getPlayerNumber(); q++)
    {
        rishSefidEffect(players[q].getAllPlayedCards());
    }
    // effect of bahar vs zemestan
    if (baharVSzemestan.size() > 0)
    {
        if (baharVSzemestan[baharVSzemestan.size() - 1].getName() == "bahar")
        {
            Bahar spring;
            spring.baharPlayed();
            spring.maxScoreForBahar(findMaxScoreCard());
        }
        else
        {
            Zemestan winter;
            winter.zemestanPlayed();
        }
    }

    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        for (int j = 0; j < armyAndSpecialCards.size(); j++)
        {
            scorsAtEndOfWar[i] = armyAndSpecialCards[j]->effectOfCard(players[i].getAllPlayedCards(), scorsAtEndOfWar[i]);
        }
        if (scorsAtEndOfWar[i] > 0)
        {
            if (scorsAtEndOfWar[i] % goodLuckNumber == 0)
                scorsAtEndOfWar[i] *= 2;

            if (scorsAtEndOfWar[i] % badLuckNumber == 0)
                scorsAtEndOfWar[i] = -1;
        } // the player can't be the winner anyway

        if (scorsAtEndOfWar[i] > winnerScore)
        {
            winnerScore = scorsAtEndOfWar[i];
            winner = i;
        }
    }
    int counterWinner = 0;
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        if (scorsAtEndOfWar[i] == winnerScore)
            counterWinner++;
    }
    if (counterWinner > 1)
    {
        std::cout << "there is no winner for this war!! start a new war" << std::endl;
        return false; // there is no winner for this war
    }
    setOrderOfWinner();

    // std::cin.ignore();
    // system("CLS");
    int counterBadLuck = 0;
    for (int k = 0; k < identity.getPlayerNumber(); k++)
    {
        if (scorsAtEndOfWar[k] == -1)
            counterBadLuck++;
    }
    if (counterBadLuck == identity.getPlayerNumber())
        return false;                    // there is no war for this war
    if (!checkShirzenForCertianPlayer()) // check if the number of shirzan's played is equal
    {
        starterPlayer = winner;
    }
    int temp = winner;
    // winner = -1;
    newOrContinue = "n";
    Zemestan z;
    z.endOfZemestan();
    // allInfo();
    return true;
}
bool Control::ifMaxScoreCardIsInHandForRishSefid(std::string rishSefidMaxScore, std::vector<Card> playedCards)
{
    for (int i = 0; i < playedCards.size(); i++)
    {
        if (rishSefidMaxScore == playedCards[i].getName())
        {
            return true;
        }
    }
    return false;
}
void Control::initializeSpecialCards()
{
    Army *army = new Army();
    Zemestan *zemestan = new Zemestan();
    Tabl_zan *tabl_zan = new Tabl_zan();
    Bahar *bahar = new Bahar();
    Shirzan *shirzan = new Shirzan();
    Shah_dokht *shah_dokht = new Shah_dokht();
    armyAndSpecialCards.push_back(army);
    armyAndSpecialCards.push_back(zemestan);
    armyAndSpecialCards.push_back(tabl_zan);
    armyAndSpecialCards.push_back(shah_dokht);
    armyAndSpecialCards.push_back(bahar); // recent spring effect
    armyAndSpecialCards.push_back(shirzan);
}
bool Control ::checkingTheNeighborhoodOfTwoStates(int index, int first, int second)
{
    Map map; // for accessing Map's member functions.
    if (map.getNeighborMap(map.searchInStates(players[index].getOwenedStates(first)), map.searchInStates(players[index].getOwenedStates(second))) == 1)
    {
        counterNeighbores++;
        return true;
    }
    return false;
}
bool Control ::checkWin(int index)
{

    for (int i = 0; i < players[index].getNumberOfOwenedStates() - 1; i++)
    {
        checkingTheNeighborhoodOfTwoStates(index, i, i + 1);
    }

    checkingTheNeighborhoodOfTwoStates(index, 0, players[index].getNumberOfOwenedStates() - 1);

    if (counterNeighbores == 3 || players[index].getNumberOfOwenedStates() == 5)
    {
        numberOfWinnerOfGame = index;
        winnerOfGame = players[index].getName();
        return true;
    }
    return false;
}
int Control::shirzanCount(std::vector<Card> playedCardForShirzan)
{
    int counter = 0;
    for (int i = 0; i < playedCardForShirzan.size(); i++)
    {
        if (playedCardForShirzan[i].getName() == "shirzan")
            counter++;
    }
    return counter;
}
bool Control::checkShirzenForCertianPlayer()
{
    std::vector<int> shirzanCounter(identity.getPlayerNumber());
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        shirzanCounter[i] = 0;
    }
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        shirzanCounter[i] = shirzanCount(players[i].getAllPlayedCards());
    }
    int maxShirzanInHand = shirzanCounter[0];
    starterPlayer = 0;
    int counterShirzanScore = 0;
    for (int i = 1; i < identity.getPlayerNumber(); i++)
    {
        if (maxShirzanInHand < shirzanCounter[i])
        {
            maxShirzanInHand = shirzanCounter[i];
            starterPlayer = i;
        }
    }
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        if (maxShirzanInHand == shirzanCounter[i])
            counterShirzanScore++;
    }
    if (counterShirzanScore > 1)
        return false;
    return true;
}
bool Control::checkIfItsTimeToDealHands()
{
    int counterFullHands = 0;
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        if (players[i].getNumberOfPlayerCards() != 0)
        {
            counterFullHands++;
        }
    }
    if (counterFullHands > 1)
    {
        return false;
    }
    return true;
}
int Control::lastPlayerWithRemainedCards()
{
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        if (players[i].getNumberOfPlayerCards() != 0)
        {
            return i;
        }
    }
}
bool Control::searchForExistingStates(std::string warzone)
{
    Map mapObj;
    if (!mapObj.ifElementExists(warzone))
    {
        std::cout << "invalid state.please enter a valid state " << std::endl;
        return false;
    }
    return true;
}

std::string Control::help(std::string str)
{
    Help help;
    std::cout << str << " : " << help.searchInHelps(str) << std::endl;
    std::cin.ignore();
}
std::string Control::cinTypeOfHelp()
{
    std::string typeOfHelp;
    std::cout << "if you want general halp about the game enter 'general' and if you want help about a specific special card enter the card's name." << std::endl;
    std::cin >> typeOfHelp;
    return typeOfHelp;
}
void Control::savePlayerInfo(int index)
{
    // for (int i = 0; i < numberOfSavedGames.size(); i++)
    // {
    //     if (isFileEmpty(numberOfSavedGames[i]) == 1) // if file is empty
    //     {

    save << players[index].getName() << " " << players[index].getAge() << " " << players[index].getColor() << " " << players[index].getIfPassed() << std::endl;
    //     }
    // }
}
void Control::savePlayerStates(int index)
{
    save << "number_of_owned_states: " << players[index].getNumberOfOwenedStates() << std::endl;
    save << "owend_states: ";
    // if (players[index].getNumberOfOwenedStates() > 0)
    // {
    //     // save<< "numberOfOwenedStates: " << players[index].getNumberOfOwenedStates() <<std::endl;
    for (int j = 0; j < players[index].getNumberOfOwenedStates(); j++)
        save << players[index].getOwenedStates(j) << " ";
    save << std::endl;
    // }
}
void Control::savePlayedCardsInfo(int index)
{
    save << "played_cards_number: " << players[index].getNumberOfPlayedCards() << std::endl;
    save << "played_cards: ";
    for (int i = 0; i < players[index].getNumberOfPlayedCards(); i++)
    {
        save << players[index].getPlayedCard(i).getName() << " ";
    }
    for (int i = 0; i < players[index].getNumberOfPlayedCards(); i++)
    {
        std::cout << players[index].getPlayedCard(i).getName() << " ";
    }
    save << std::endl;
}
void Control::savePlayerCardsInfo(int index)
{
    save << "player_cards_number: " << players[index].getNumberOfPlayerCards() << std::endl;
    save << "player_cards: ";
    for (int i = 0; i < players[index].getNumberOfPlayerCards(); i++)
    {
        save << players[index].getPlayerCard(i).getName() << " ";
    }
    for (int i = 0; i < players[index].getNumberOfPlayerCards(); i++)
    {
        std::cout << players[index].getPlayerCard(i).getName() << " ";
    }
    save << std::endl;
}
void Control::saveBaharVSZemestan()
{
    save << "player_cards_number: " << baharVSzemestan.size() << std::endl;
    save << "baharVSzemestan: ";
    for (int i = 0; i < baharVSzemestan.size(); i++)
    {
        save << baharVSzemestan[i].getName() << " ";
    }
    save << std::endl;
}
void Control::saveSigns()
{
    save << "warzone: " << warzone << std::endl
         << "peace_sign: " << peaceSign << std::endl;
}
void Control::saveLuckNumbers()
{
    save << "good_luck_number: " << goodLuckNumber << std::endl;
    save << "bad_luck_number: " << badLuckNumber << std::endl;
}
void Control::saveStarterPlayer(int index)
{
    starterPlayer = index;
    save << "starter_player: " << starterPlayer << std::endl;
    save << "turn_control: " << TurnControl << std::endl;
    save << "turnHandlerAfterEachWar : " << turnHandlerAfterEachWar << std::endl;
    save << "PlayerTurnHandler : " << PlayerTurnHandler << std::endl;
}
bool Control::saveAllInfo(int index)
{
    // save.open("save.txt", std::ios::in | std::ios::out);
    // int counterOfSaveGame = 1;
    for (int i = 0; i < numberOfSavedGames.size(); i++)
    {
        //   if (!std::filesystem::exists(save))
        //     {
        //         /// NOTE: if file save folder isn't available this will create it
        //         std::filesystem::create_directory(save);
        //     }
        if (isFileEmpty(numberOfSavedGames[i]) == 1) // if file is empty
        {
            std::cout << "file if empty" << std::endl;
            save.open(numberOfSavedGames[i], std::ios::in | std::ios::out);
            if (!save.is_open())
            {
                std ::cerr << "Error opening the file!" << std::endl;
                return false;
            }
            save << identity.getPlayerNumber() << std::endl;
            for (int i = 0; i < identity.getPlayerNumber(); i++)
            {
                savePlayerInfo(i);
                savePlayerStates(i);
                savePlayerCardsInfo(i);
                savePlayedCardsInfo(i);
            }
            saveBaharVSZemestan();
            saveLuckNumbers();
            saveStarterPlayer(index);
            save << "if_Card_passed : " << true << std::endl;
            saveSigns();
            break;
        }
        // int indexControlerForSave = 4;
        // if (i == indexControlerForSave && counterOfSaveGame == 1)
        // {
        //     counterOfSaveGame--;
        //     i = 0;
        // }
        // if (counterOfSaveGame == 0)
        //     counterOfSaveGame = 1;
    }
    save.close();
}
bool Control::isFileEmpty(const std::string &filename)
{
    //
    // if (!file.is_open())
    // {
    //     std::cerr << "Could not open the file!" << std::endl;
    //     return false;
    // }

    // char c;
    // file.get(c);
    // bool d = c == file.eof();
    // std::cout << d << std::endl;
    // return c == file.eof();
    std::ifstream file(filename, std::ios::in | std::ios::ate);
    if (!file.is_open())
    {
        std::cerr << "Could not open the file!" << std::endl;
        return false;
    }
    return file.tellg() == 0;
}
// void Control::setNameForUI(std::vector<char> names)
// {
//     std::string tempNames;
//     std::cout << "size -> " << names.size() << std::endl;
//     for (int i = 0; i < names.size(); i++)
//     {
//         std::cout << "name -> " << names[i] << std::endl;
//         tempNames += names[i];
//     }
//     std::cout << "tempNames -> " << tempNames << std::endl;
//     identity.setPlayerNameForUI(tempNames);
// }
// void Control::setAgeForUI(std::vector<char> age)
// {
//     int tempAge;
//     char Age[age.size()];
//     std::cout << "size -> " << age.size() << std::endl;
//     for (int i = 0; i < age.size(); i++)
//     {
//         Age[i] = age[i];
//     }
//     tempAge = std::atoi(Age);
//     std::cout << "tempAge -> " << tempAge << std::endl;
//     identity.setPlayerAgeForUI(tempAge);
// }
// void Control::setNameFromUI(char names[])
// {
//     std::string tempNames;
//     // std::cout << "size -> " << names.size() << std::endl;
//     for (int i = 0; i < strlen(names); i++)
//     {
//         std::cout << "name -> " << names[i] << std::endl;
//         tempNames += names[i];
//     }
//     std::cout << "tempNames -> " << tempNames << std::endl;
//     identity.setPlayerNameForUI(tempNames);
// }
void Control::menu()
{
    Map mapForUI;
    ifCardsAreSet = false;
    UIStates uiStates;
    uiStates = UIMenu;
    while (WindowShouldClose() == false)
    {

        switch (uiStates)
        {
        case UIMenu:
        {
            newOrContinue = ui.menuGameLoop();
            if (newOrContinue == "n")
            {
                uiStates = UIplayerNumber;
            }
            if (newOrContinue == "c")
            {
                uiStates = UIWhichSavedGame;
            }
            if (newOrContinue == "help")
            {
                uiStates = generalHelp;
            }
            if (newOrContinue == "exit")
            {
                // uiStates = UIplayerNumber;
            }
            break;
        }
        case UIplayerNumber:
        {
            uiNumberPlayers = ui.displayPlayerNumberButton();
            if (uiNumberPlayers == 3)
            {
                identity.setPlayerNumberForSave(uiNumberPlayers);
                uiStates = threePlayerInput;
            }
            if (uiNumberPlayers == 4)
            {
                identity.setPlayerNumberForSave(uiNumberPlayers);
                uiStates = fourPlayerInput;
            }

            break;
        }
        case UIWhichSavedGame:
        {
            ifCardsAreSet = true;
            whichSavedGame = ui.displayOpenDropDownMenuForSavedGameNumber();
            uiStates = UISaveReadInfo;
            break;
        }
        case UISaveReadInfo:
        {
            saveReadAllInfo();
            uiStates = displayPlayersCard;
            break;
        }
        case threePlayerInput:
        {
            for (int i = 0; i < 3; i++)
            {
                if (displayIdentity == 0)
                    ui.thripleTextBoxDraw();
                UIPlayerName = ui.getPlayerNameAndColorFromUI(i);
                identity.setPlayerNameForSave(UIPlayerName);
                identity.setPlayerAgeForSave(ui.getPlayerAgeAndLuckFromUI(i + 3));
                selectedColor = ui.displayOpenDropDownMenuForColors(UIPlayerName);
                identity.setPlayerColorForSave(selectedColor);
                identity.setPlayerForSave();
                displayIdentity++;
            }
            displayIdentity = 0;

            uiStates = warzoneMap;
            break;
        }
        case fourPlayerInput:
        {
            for (int i = 0; i < 4; i++)
            {
                if (displayIdentity == 0)
                    ui.quadrupleTextBoxDraw();
                UIPlayerName = ui.getPlayerNameAndColorFromUI(i);
                identity.setPlayerNameForSave(UIPlayerName);
                identity.setPlayerAgeForSave(ui.getPlayerAgeAndLuckFromUI(i + 4));
                selectedColor = ui.displayOpenDropDownMenuForColors(UIPlayerName);
                identity.setPlayerColorForSave(selectedColor);
                identity.setPlayerForSave();
                displayIdentity++;
            }
            displayIdentity = 0;

            uiStates = warzoneMap;
            break;
        }
        case warzoneMap:
        {
            ui.displayMap(identity.getName(determinMinAge()));
            setWarzone(mapForUI.findKey(ui.displayWarzoneButton(identity.getName(determinMinAge())))); // setting warzone based on UI output
            uiStates = luckAndBadLuckNumbers;
            break;
        }
        case luckAndBadLuckNumbers:
        {
            ui.getLuckNumbers(identity.getName(starterPlayer));
            goodLuckNumber = ui.getPlayerAgeAndLuckFromUI(0);
            badLuckNumber = ui.getPlayerAgeAndLuckFromUI(1);
            uiStates = charactersIntro;
            break;
        }
        case charactersIntro:
        {
            if (identity.getPlayerNumber() == 3)
                ui.displayCharectersAndNamesForThree(identity.getName(starterPlayer), identity.getName((starterPlayer + 1) % 3), identity.getName((starterPlayer + 2) % 3));
            else
                ui.displayCharectersAndNamesForFour(identity.getName(starterPlayer), identity.getName((starterPlayer + 1) % 4), identity.getName((starterPlayer + 2) % 4), identity.getName((starterPlayer + 3) % 4));

            uiStates = showSelectedWarzone;
            break;
        }
        case showSelectedWarzone:
        {
            ui.displaySelectedWarzone(warzone);

            uiStates = displayPlayersCard;
            break;
        }
        case displayWarSigns:
        {
            initializeColorsForUI();
            allOwenedStatesForUI();
            calculateNumberOfWinners();
            ui.displayRenderWarSigns();
            ui.displayWarSigns(numberOfOwendStatesForEachPlayer, nameOfOwenedStates, orderOfWinners, numberOfWinners, colorsForUI, peaceSign);
            uiStates = warzoneMap;
            break;
        }
        case displayPlayersCard:
        {
            ui.displaycharactersCards(PlayerTurnHandler % (identity.getPlayerNumber()));
            if (numberOfDealingHandsAfterSaveGame == identity.getPlayerNumber())
                newOrContinue = "n";
            if (!ifCardsAreSet)
                StartNewGame();

            if (PlayerTurnHandler < (identity.getPlayerNumber()) || newOrContinue == "c")
            {
                ui.findTexture(players[TurnControl].getAllPlayerCards(), TurnControl);
                numberOfDealingHandsAfterSaveGame++;
            }

            if (PlayerTurnHandler < (identity.getPlayerNumber()) || players[TurnControl].getIfPassed() == false)
                players[TurnControl].setIfPassed(ui.renderTextureForCharacterOnGameTable(TurnControl));

            int returnPlayingInput = playingInput();
            if (returnPlayingInput == 1)
            {
                uiStates = displayWinnerOfGame;
                break;
            }
            if (returnPlayingInput == 4)
            {
                uiStates = showValidCardsForMatarsak;
                break;
            }
            if (returnPlayingInput == 5) // there is no winner for war
            {
                uiStates = noWinnerForWar;
                break;
            }

            if (returnPlayingInput != 3)
                uiStates = displayingWinner;
            else
            {
                TurnControl++;
                if (TurnControl == (identity.getPlayerNumber()))
                    TurnControl = 0;
                if (uiNumberPlayers == 3)
                    uiStates = displayGameTableForThree;
                if (uiNumberPlayers == 4)
                    uiStates = displayGameTableForFour;
            }
            break;
        }
        case noWinnerForWar:
        {
            ui.displayNoWinner();
            uiStates = warzoneMap;
            break;
        }
        case displayGameTableForThree:
        {
            turnHandlerAfterEachWar++;
            PlayerTurnHandler++;

            exitStatus = ui.displayGameTableAndCharactersForThree(PlayerTurnHandler, starterPlayer);
            if (exitStatus == 0)
                uiStates = controlExit;
            else if (exitStatus == 1)
                uiStates = displayPlayersCard;
            else if (exitStatus == 2)
                uiStates = specialHelp;

            break;
        }
        case displayGameTableForFour:
        {
            turnHandlerAfterEachWar++;
            PlayerTurnHandler++;

            exitStatus = ui.displayGameTableAndCharactersForFour(PlayerTurnHandler, starterPlayer);
            if (exitStatus == 0)
                uiStates = controlExit;
            else if (exitStatus == 1)
                uiStates = displayPlayersCard;
            else if (exitStatus == 2)
                uiStates = specialHelp;

            break;
        }

        case displayingWinner:
        {
            ui.eraseAllCardsAfterWar();
            ui.displayWinner(starterPlayer, players[starterPlayer].getName());
            for (int i = 0; i < identity.getPlayerNumber(); i++)
                players[i].eraseAllPlayedCards();
            uiStates = displayWarSigns;
            break;
        }
        case showValidCardsForMatarsak:
        {
            ui.displaycharactersCardsForMatarsak(PlayerTurnHandler % (identity.getPlayerNumber()));
            ui.validCardsForMatarsak();
            setPlayedCardsAfterMatarsak();
            if (uiNumberPlayers == 3)
                uiStates = displayGameTableForThree;
            if (uiNumberPlayers == 4)
                uiStates = displayGameTableForFour;
            break;
        }
        case displayWinnerOfGame:
        {
            ui.displayFinalWinner(numberOfWinnerOfGame, winnerOfGame);
            uiStates = UIMenu;
            break;
        }
        case specialHelp:
        {
            helpSelected = ui.helpGameControl();
            ui.displayHelp(helpChoice.searchInHelps(helpSelected));
            uiStates = displayPlayersCard;
            break;
        }
        case generalHelp:
        {
            ui.displayHelp(helpChoice.searchInHelps("general"));
            uiStates = UIplayerNumber;
            break;
        }
        case UISaveWriteInfo:
        {
            saveAllInfo(TurnControl);
            break;
        }
        case controlExit:
        {
            checkSaveGame = ui.ExitGameControl();
            if (checkSaveGame == 1)
                uiStates = UISaveWriteInfo;
            break;
        }
        }
    }

    ui.unloadingTexture();
}
int Control::setPlayedCardsFromUI()
{

    if (players[TurnControl].getIfPassed() == false)
    {
        for (int i = players[TurnControl].getNumberOfPlayedCards(); i < ui.getPlayedCardsFromUI().size(); i++)
        {
            selectedCard.setName(ui.getPlayedCardsFromUI()[i]);
            players[TurnControl].setPlayedCard(selectedCard);
            eraseSelectedCard();
            if (selectedCard.getName() == "matarsak")
                return 4;
            if (selectedCard.getName() == "parcham_dar")
                return 5;
            if (selectedCard.getName() == "fok_sefid")
                return 6;
            if (selectedCard.getName() == "rakhsh_sefid")
                return 8;
        }
        return 3;
    }
    return 7;
}
void Control::setPlayedCardsAfterMatarsak()
{
    if (players[TurnControl].getIfPassed() == false)
    {
        players[TurnControl].eraseAllPlayedCards();

        for (int i = 0; i < ui.getPlayedCardsFromUI().size(); i++)
        {

            selectedCard.setName(ui.getPlayedCardsFromUI()[i]);
            players[TurnControl].setPlayedCard(selectedCard);
        }
    }
}

void Control::allOwenedStatesForUI()
{
    numberOfOwendStatesForEachPlayer.clear();
    nameOfOwenedStates.clear();
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        numberOfOwendStatesForEachPlayer.emplace_back(players[i].getNumberOfOwenedStates());
    }
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        for (int j = 0; j < players[i].getNumberOfOwenedStates(); j++)
        {
            nameOfOwenedStates.emplace_back(players[i].getOwenedStates(j));
        }
    }
}

void Control::eraseSelectedCard()
{
    for (int i = 0; i < players[TurnControl].getNumberOfPlayerCards(); i++)
    {
        if (players[TurnControl].getPlayerCard(i).getName() == selectedCard.getName())
            players[TurnControl].eraseCard(i);
    }
}

bool Control::determinNumberOfSavedGame()
{
    std::cout << "please enter the number of the saved game you want to continue." << std::endl;
    std::cin >> whichSavedGame;
    if (isFileEmpty(numberOfSavedGames[whichSavedGame - 1]) == 1) // if tellg == 0 is true meaning the file is empty.
    {
        std::cout << "No saved game found." << std::endl;
        menu();
        return false;
    }
    return true;
}
void Control::saveReadPlayerInfo(int index)
{
    // int numberOfPlayersForSave;
    std::string playerName;
    int playerAge;
    std::string playerColor;
    bool playerPosotion;
    save >> playerName >> playerAge >> playerColor >> playerPosotion;
    identity.setPlayerNameForSave(playerName);
    identity.setPlayerAgeForSave(playerAge);
    identity.setPlayerColorForSave(playerColor);
    identity.setPlayerForSave();
    players.push_back(Player(identity.getAge(index), identity.getName(index), identity.getColor(index), playerPosotion));
}
void Control::saveReadPlayerStates(int index)
{
    std::string stringOwendStates;    // string persisting the states
    std::string stringNumberOfStates; // get the string containing the number of
    int numberOfStates;
    save >> stringNumberOfStates >> numberOfStates;
    save >> stringOwendStates;

    for (int j = 0; j < numberOfStates; j++)
    {
        save >> stringOwendStates;
        players[index].setOwenedStates(stringOwendStates);
    }
}
void Control::saveReadPlayedCardsInfo(int index)
{
    std::string stringPlayedCards, stringNumberOfCards;
    int numberOfPlayedCards;
    save >> stringNumberOfCards >> numberOfPlayedCards;
    save >> stringPlayedCards;
    for (int i = 0; i < numberOfPlayedCards; i++)
    {
        save >> stringPlayedCards;
        players[index].setPlayedCard(stringPlayedCards);
    }
}
void Control::saveReadPlayerCardsInfo(int index)
{
    std::string stringPlayerCards, stringNumbrOfCards;
    int numberOfCards;
    save >> stringNumbrOfCards;
    save >> numberOfCards;
    save >> stringPlayerCards;
    for (int i = 0; i < numberOfCards; i++)
    {
        save >> stringPlayerCards;
        players[index].setPlayerCard(stringPlayerCards);
    }
}
void Control::saveReadBaharVSZemestan()
{
    std::string stringBaharVSzemestan;           // get the string representing the order of the cards
    std::string stringBaharVSzemestanCardsCount; // get the description which contains number of cards
    int baharVSzemestanCardsCount;
    save >> stringBaharVSzemestanCardsCount >> baharVSzemestanCardsCount;
    save >> stringBaharVSzemestan;
    for (int i = 0; i < baharVSzemestanCardsCount; i++)
    {
        save >> stringBaharVSzemestan;
        baharVSzemestan.push_back(stringBaharVSzemestan);
    }
}
void Control::saveReadLuckNumbers()
{
    std::string stringGoodLuckNumbers;
    std::string stringBadLuckNumbers;
    save >> stringGoodLuckNumbers >> goodLuckNumber;
    save >> stringBadLuckNumbers >> badLuckNumber;
}
void Control::saveReadSigns()
{
    std::string stringWarzone;
    std::string stringPeaceSign;
    save >> stringWarzone >> warzone >> stringPeaceSign >> peaceSign;
}
void Control::saveReadStarterPlayerAndSelectedCard()
{
    std::string stringStarterPlayer, stringTurnControl, stringTurnHandlerAfterEachWar, stringPlayerTurnHandler;
    save >> stringStarterPlayer >> starterPlayer;
    save >> stringTurnControl >> TurnControl;
    save >> stringTurnHandlerAfterEachWar >> turnHandlerAfterEachWar;
    save >> stringPlayerTurnHandler >> PlayerTurnHandler;
}
void Control::saveReadAllInfo()
{
    save.open(numberOfSavedGames[whichSavedGame], std::ios::in | std::ios::out);
    if (!save.is_open())
    {
        std ::cerr << "Error opening the file!" << std::endl;
        return;
    }
    int intPlayerNumber;
    save >> intPlayerNumber;
    uiNumberPlayers = intPlayerNumber;
    identity.setPlayerNumberForSave(intPlayerNumber);
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        saveReadPlayerInfo(i);
        saveReadPlayerStates(i);
        saveReadPlayerCardsInfo(i);
        saveReadPlayedCardsInfo(i);
    }
    saveReadBaharVSZemestan();
    saveReadLuckNumbers();
    saveReadStarterPlayerAndSelectedCard();
    bool stirngIfCardSet;
    save >> stirngIfCardSet >> ifCardsAreSet;
    saveReadSigns();
    save.close();
}
void Control::StartNewGame()
{
    if (!ifCardsAreSet)
    {
        // validateIdentity();
        dealingCards();
        shuffelingCards();
        randomCardSet();
        // diplayBeggingOfTheGame();
        determinMinAge();
    }
}
void Control::initializingNumberOfSavedGames()
{
    numberOfSavedGames.push_back("../src/save.txt");
    numberOfSavedGames.push_back("../src/save2.txt");
    numberOfSavedGames.push_back("../src/save3.txt");
    numberOfSavedGames.push_back("../src/save4.txt");
    numberOfSavedGames.push_back("../src/save5.txt");
}
void Control::setWarzone(std::string stateName)
{
    warzone = stateName;
}
void Control::calculateNumberOfWinners()
{

    numberOfWinners = 0;
    for (int j = 0; j < identity.getPlayerNumber(); j++)
    {
        for (int i = 0; i < orderOfWinners.size(); i++)
        {
            if (orderOfWinners[i] == j)
            {
                numberOfWinners++;
                // numberOfWins.push_back(numberOfWinsCounter);
                break;
            }
        }
    }
}
void Control::initializeColorsForUI()
{
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        colorsForUI.emplace_back(players[i].getColor());
    }
}
void Control::run()
{
    initializeSpecialCards();
    menu();
    // playingInput();
}
