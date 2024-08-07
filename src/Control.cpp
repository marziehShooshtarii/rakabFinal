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
    std::cout << "determinMinAge 1" << std::endl;
    int min = identity.getAge(0);
    std::cout << "determinMinAge 2" << std::endl;
    for (int i = 1; i < identity.getPlayerNumber(); i++)
    {
        std::cout << "determinMinAge 3" << std::endl;
        if (min > identity.getAge(i))
        {
            std::cout << "determinMinAge 4" << std::endl;
            min = identity.getAge(i);
            std::cout << "determinMinAge 5" << std::endl;
            starterPlayer = i;
            TurnControl = i; // starterPlayer that can be changed
        }
    }
    std::cout << "determinMinAge 5" << std::endl;
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
    std::cout << "aval deck" << std::endl;
    deck = {
        {"bahar", 3},
        {"zemestan", 3},
        {"matarsak", 16},
        {"tabl_zan", 6},
        {"shah_dokht", 3},
        {"shirzan", 12},
        {"parcham_dar", 3},
        {"rish_sefid", 6},
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
    std::cout << "akhar deck" << std::endl;
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
    std::cout << "after players" << std::endl;
    std::cout << "identity.getPlayerNumber() -> random card set" << identity.getPlayerNumber() << std::endl;
    std::cout << "player name - > " << players[0].getName() << std::endl;
    std::cout << "size vector owened states - > " << players[0].getNumberOfOwenedStates() << std::endl;

    // if (fistWarOfGame)
    // {
    //     for (int i = 0; i < identity.getPlayerNumber(); i++)
    //         players[i].eraseOwenedStates();
    // }

    for (int j = 0; j < identity.getPlayerNumber(); j++)
    {
        std::cout << "identity.getPlayerNumber() -> " << identity.getPlayerNumber() << std::endl;
        for (int i = 0; i < (10 + players[j].getNumberOfOwenedStates()); i++)
        {
            std::cout << "identity.getPlayerNumber() -> " << identity.getPlayerNumber() << std::endl;
            std::cout << "randomCardSet ghabl " << std::endl;
            randomCard = rand() % 110;
            std::cout << "randomCardSet bad " << std::endl;
            std::cout << "randomCard " << randomCard << std::endl;
            players[j].setPlayerCard(allCards[randomCard]);
        }
        std::cout << "bad for aval " << std::endl;
    }
    ifCardsAreSet = true;
    std::cout << "bad for dovoom " << std::endl;
}
void Control::validateIdentity()
{
    identity.setPlayerNumber();
    identity.setData();
    // system("CLS");
}
void Control::shuffelingCards()
{
    std::cout << "too shuffle " << std::endl;
    random_shuffle(allCards.begin(), allCards.end());
    std::cout << "tah shuffle " << std::endl;
}
void Control::displayStartOfWar()
{
    std::cout << starterPlayer << "start the war by pressing enter" << std::endl;
}
int Control::playingInput()
{
    std::cout << "safewe" << std::endl;
    // while (1)
    // {
    std::cout << "aval while playing" << std::endl;
    if (newOrContinue == "n")
    {
        std::cout << "to while mosavi n playing" << std::endl;
        startOfWarMassage();
        std::cout << "bade start neew war mohtaram " << std::endl;
        // displayStarterPlayer();
    }
    std::cout << "ghabl flag ghashng " << std::endl;
    // displayWarzone();
    // displayOwenedStates();
    bool checkParchamDar = true;
    int checkSelectedCard = -1; // differentiate from the card played
    std::cout << " checkSelectedCard " << checkSelectedCard << std::endl;
    // if (newOrContinue == "n")
    // {
    //     for (int c = 0; c < identity.getPlayerNumber(); c++)
    //     {
    //         players[c].setIfPassed(false);
    //     }
    // }
    winner = -3;
    // while (checkIfAllPlayersPassed())
    // {
    std::cout << "to while dovoms" << std::endl;
    int indexControler = identity.getPlayerNumber();
    std::cout << "to while indexcontrol " << indexControler << std::endl;
    int i = TurnControl;
    // for (int i = TurnControl; i < indexControler;)
    // {
    //     if (!checkIfCertianPlayerPassed(i))
    //     {
    std::cout << "aha " << i << std::endl;
    std::cout << "aha2 " << TurnControl << std::endl;

    // for (int d = 0; d < identity.getPlayerNumber(); d++)
    //     displayPlayedCards(d);
    std::cout << players[i].getName() << " it's your turn " << "\n\tplease chose your card from the list or pass or ask for help :\n " << "\t\n";
    displayPlayingCards(i);
    std::cout << "bade displayPlayingCards" << std::endl;
    // checkSelectedCard = cinSelectedCard(i);
    // TurnControl = i;
    checkSelectedCard = setPlayedCardsFromUI();
    std::cout << "checkSelectedCard -> " << checkSelectedCard << std::endl;
    if (checkSelectedCard != 5) // if player has played anything but parcham dar
    {
        std::cout << "4:05" << std::endl;
        if (playingCards(i, checkSelectedCard))
            return 4; // matarsak has been played
                      // playingCards(i, checkSelectedCard);
        std::cout << "4:06" << std::endl;
    }
    else
    {
        std::cout << "4:07" << std::endl;
        checkProcessOfEndingWar();
        std::cout << "4:08" << std::endl;
        for (int q = 0; q < identity.getPlayerNumber(); q++)
            players[q].setIfPassed(true);
        std::cout << "4:09" << std::endl;
        i = indexControler;
        checkParchamDar = false;
    }
    // }
    std::cout << "4:09" << std::endl;
    // i++;
    std::cout << std::endl;
    // std::cin.ignore();
    // if (i == identity.getPlayerNumber() && checkParchamDar == true)
    // {
    //     i = 0;
    //     indexControler = TurnControl;
    //     //     }
    //     //     // system("CLS");
    //     // }
    //     // system("CLS");
    //     controlTurn();
    // }
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

    // }
}
int Control::checkProcessOfEndingWar()
{
    if (!checkIfAllPlayersPassed())
    {

        if (determinWinnerOfWar())
            players[winner].setOwenedStates(warzone);
        else
            return 4; // there is no winner for this war
        std::cout << "after determining winner of war" << std::endl;
        winner = -1;
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
void Control::choiceForPeaceSign()
{
    std::cout << players[orderOfRishSefids[orderOfRishSefids.size() - 1]].getName() << " please choose the state you want to place your peace sign on.";
    // std::cin >> peaceSign;
    ui.displayWarzoneButton(players[orderOfRishSefids[orderOfRishSefids.size() - 1]].getName());
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
    if (checkSelectedCard == 6)
    {
        saveAllInfo(index);
        exit(0);
    }
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
    std::cout << "determinWinnerOfWar" << std::endl;
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
            std::cout << "in the zemestan" << std::endl;
            Zemestan winter;
            std::cout << "after class zemestan" << std::endl;
            winter.zemestanPlayed();
            std::cout << "after class zemestanplayed" << std::endl;
        }
    }
    std::cout << "bashe. " << identity.getPlayerNumber() << std::endl;
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        std::cout << "marg " << std::endl;
        for (int j = 0; j < players[i].getNumberOfPlayedCards(); j++)
        {
            std::cout << "turn control " << TurnControl << std::endl;
            // std::cout << ui.getPlayedCardsFromUI().size() << "aziiiiiiiiiiiz " << identity.getName(i)<< std::endl;
            std::cout << players[i].getNumberOfPlayedCards() << "aziiiiiiiiiiiz2 " << identity.getName(i) << std::endl;
            std::cout << "carta " << players[i].getPlayedCard(j).getName() << " " << identity.getName(i) << std::endl;
        }
    }
    std::cout << "after zemestan" << std::endl;
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        for (int j = 0; j < armyAndSpecialCards.size(); j++)
        {
            std::cout << "aval polymorphism" << armyAndSpecialCards.size() << std::endl;
            scorsAtEndOfWar[i] = armyAndSpecialCards[j]->effectOfCard(players[i].getAllPlayedCards(), scorsAtEndOfWar[i]);
            std::cout << "bad polymorphism" << std::endl;
            std::cout << "score -> " << scorsAtEndOfWar[i] << std::endl;
        }
        std::cout << "akhar polymorphism" << std::endl;

        if (scorsAtEndOfWar[i] % goodLuckNumber == 0)
            scorsAtEndOfWar[i] *= 2;

        if (scorsAtEndOfWar[i] % badLuckNumber == 0)
            scorsAtEndOfWar[i] = -1; // the player can't be the winner anyway

        std::cout << scorsAtEndOfWar[i] << " jan zizet" << std::endl;
        if (scorsAtEndOfWar[i] > winnerScore)
        {
            std::cout << "to score: " << winnerScore << std::endl;
            winnerScore = scorsAtEndOfWar[i];
            std::cout << "to score2: " << winnerScore << std::endl;
            winner = i;
        }
        std::cout << "to score3: " << winnerScore << std::endl;
    }
    int counterWinner = 0;
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        std::cout << "to score: " << winnerScore << std::endl;
        if (scorsAtEndOfWar[i] == winnerScore)
            counterWinner++;
        std::cout << "to score: " << winner << std::endl;
    }
    if (counterWinner > 1)
    {
        std::cout << "there is no winner for this war!! start a new war" << std::endl;
        return false; // there is no winner for this war
    }
    std::cout << "winner - > " << players[winner].getName() << std::endl;

    for (int d = 0; d < identity.getPlayerNumber(); d++)
        std::cout << identity.getName(d) << " -> " << scorsAtEndOfWar[d] << std::endl;
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        for (int j = 0; j < players[i].getNumberOfPlayedCards(); j++)
        {
            std::cout << identity.getName(i) << " -> " << players[i].getPlayedCard(j).getName() << " ";
        }
        std::cout << std::endl;
    }
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
        std::cout << "starter player - > " << starterPlayer << std::endl;
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
        std::cout << "winnerOfGame@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << winnerOfGame << std::endl;
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
void Control::saveStarterPlayer(int index)
{
    starterPlayer = index;
    save << "starter_player: " << starterPlayer << std::endl;
}
bool Control::saveAllInfo(int index)
{
    // save.open("save.txt", std::ios::in | std::ios::out);
    for (int i = 0; i < numberOfSavedGames.size(); i++)
    {
        std::cout << "i - > " << i << std::endl;
        //   if (!std::filesystem::exists(save))
        //     {
        //         /// NOTE: if file save folder isn't available this will create it
        //         std::filesystem::create_directory(save);
        //     }
        if (isFileEmpty(numberOfSavedGames[i]) == 1) // if file is empty
        {
            std::cout << "file if empty" << std::endl;
            std::cout << "numberOfSavedGames[i] - > " << numberOfSavedGames[i] << std::endl;
            save.open(numberOfSavedGames[i], std::ios::in | std::ios::out);
            if (!save.is_open())
            {
                std ::cerr << "Error opening the file!" << std::endl;
                return false;
            }
            std::cout << "1111111111111111111111" << std::endl;
            save << identity.getPlayerNumber() << std::endl;
            for (int i = 0; i < identity.getPlayerNumber(); i++)
            {
                std::cout << "22222222222222" << std::endl;
                savePlayerInfo(i);
                std::cout << "33333333333333" << std::endl;
                savePlayerStates(i);
                std::cout << "44444444444444" << std::endl;
                savePlayerCardsInfo(i);
                std::cout << "55555555555555" << std::endl;
                savePlayedCardsInfo(i);
                std::cout << "66666666666666666" << std::endl;
            }
            saveBaharVSZemestan();
            std::cout << "77777777777777" << std::endl;
            saveSigns();
            std::cout << "888888888888888" << std::endl;
            saveStarterPlayer(index);
            std::cout << "9999999999999" << std::endl;
            break;
        }
    }
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
    std::cout << "menu1" << std::endl;
    while (WindowShouldClose() == false /*&& exitGame == true /*&& exitPrevious == true*/)
    {
        // std::cout << "menu2" << std::endl;

        switch (uiStates)
        {
            std::cout << "menu3" << std::endl;
        case UIMenu:
        {
            std::cout << "menu4" << std::endl;
            newOrContinue = ui.menuGameLoop();
            if (newOrContinue == "n")
            {
                std::cout << "menu5" << std::endl;
                uiStates = UIplayerNumber;
            }
            if (newOrContinue == "c")
            {
                // uiStates = UIplayerNumber;
            }
            if (newOrContinue == "help")
            {
                // uiStates = UIplayerNumber;
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
        case threePlayerInput:
        {
            for (int i = 0; i < 3; i++)
            {
                ui.thripleTextBoxDraw();
                std::cout << "for text box" << i << std::endl;
                identity.setPlayerNameForSave(ui.getPlayerNameAndColorFromUI(i));
                identity.setPlayerAgeForSave(ui.getPlayerAgeAndLuckFromUI(i + 3));
                identity.setPlayerColorForSave(ui.getPlayerNameAndColorFromUI(i + 6));
                identity.setPlayerForSave();
            }
            std::cout << "threePlayerInput 2" << std::endl;
            uiStates = warzoneMap;
            break;
        }
        case fourPlayerInput:
        {
            for (int i = 0; i < 4; i++)
            {
                ui.quadrupleTextBoxDraw();
                std::cout << "for text box" << i << std::endl;
                identity.setPlayerNameForSave(ui.getPlayerNameAndColorFromUI(i));
                identity.setPlayerAgeForSave(ui.getPlayerAgeAndLuckFromUI(i + 4));
                identity.setPlayerColorForSave(ui.getPlayerNameAndColorFromUI(i + 8));
                identity.setPlayerForSave();
            }
            std::cout << "fourPlayerInput 2" << std::endl;
            uiStates = warzoneMap;
            break;
        }
        case warzoneMap:
        {
            std::cout << "warzone1" << std::endl;
            ui.displayMap(identity.getName(determinMinAge()));
            std::cout << "identity.getName(determinMinAge())" << identity.getName(determinMinAge()) << std::endl;
            std::cout << "warzone2" << std::endl;
            setWarzone(mapForUI.findKey(ui.displayWarzoneButton(identity.getName(determinMinAge())))); // setting warzone based on UI output
            std::cout << "warzone3" << std::endl;
            uiStates = luckAndBadLuckNumbers;
            std::cout << "warzone4" << std::endl;
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
            ui.displayCharectersAndNames(identity.getName(starterPlayer), identity.getName((starterPlayer + 1) % 3), identity.getName((starterPlayer + 2) % 3));
            uiStates = showSelectedWarzone;
            break;
        }
        case showSelectedWarzone:
        {
            ui.displaySelectedWarzone(warzone);
            for (int i = 0; i < (identity.getPlayerNumber()); i++)
            {
                std::cout << "karaye ajib3 - > " << i << identity.getAge(i) << std::endl;
                std::cout << "karaye ajib4 - > " << i << identity.getName(i) << std::endl;
                std::cout << "karaye ajib4 - > " << i << identity.getColor(i) << std::endl;
            }
            uiStates = displayPlayersCard;
            break;
        }
        case displayPlayersCard:
        {
            ui.displaycharactersCards(PlayerTurnHandler % (identity.getPlayerNumber()));
            if (!ifCardsAreSet)
                StartNewGame();
            std::cout << "ghable findTexture too control" << std::endl;

            if (PlayerTurnHandler < (identity.getPlayerNumber()))
                ui.findTexture(players[TurnControl].getAllPlayerCards(), TurnControl);

            std::cout << "ghable findTexture too control 2" << std::endl;

            if (PlayerTurnHandler < (identity.getPlayerNumber()) || players[TurnControl].getIfPassed() == false)
                players[TurnControl].setIfPassed(ui.renderTextureForCharacterOnGameTable(TurnControl));

            std::cout << "ifpassed too control" << identity.getName(TurnControl) << players[TurnControl].getIfPassed() << std::endl;
            // setPlayedCardsFromUI();
            std::cout << "az tabe miad biroon" << std::endl;
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
                std::cout << "aya too in if miofte" << std::endl;
                uiStates = warzoneMap;
                break;
            }

            if (returnPlayingInput != 3)
                uiStates = displayingWinner;
            else
            {
                TurnControl++;
                if (TurnControl == (identity.getPlayerNumber()))
                    TurnControl = 0;
                std::cout << "ghabl playing input aziz " << std::endl;
                if (uiNumberPlayers == 3)
                    uiStates = displayGameTableForThree;
                if (uiNumberPlayers == 4)
                    uiStates = displayGameTableForFour;
            }
            break;
        }
        case displayGameTableForThree:
        {
            turnHandlerAfterEachWar++;
            PlayerTurnHandler++;
            // if (PlayerTurnHandler == 3)
            //     PlayerTurnHandler = 0;
            ifExitTheGame = ui.displayGameTableAndCharactersForThree(PlayerTurnHandler, starterPlayer);
            if (ifExitTheGame)
                uiStates = controlExit;
            else
                uiStates = displayPlayersCard;
            // if (uiStates == PlayerTurnHandler)
            //     break;
            // else
            //     uiStates = statesControler.at(PlayerTurnHandler);
            break;
        }
        case displayGameTableForFour:
        {
            turnHandlerAfterEachWar++;
            PlayerTurnHandler++;
            // if (PlayerTurnHandler == 3)
            //     PlayerTurnHandler = 0;
            ifExitTheGame = ui.displayGameTableAndCharactersForFour(PlayerTurnHandler, starterPlayer);
            if (ifExitTheGame)
                uiStates = controlExit;
            else
                uiStates = displayPlayersCard;
            // if (uiStates == PlayerTurnHandler)
            //     break;
            // else
            //     uiStates = statesControler.at(PlayerTurnHandler);
            break;
        }

        case displayingWinner:
        {
            ui.eraseAllCardsAfterWar();
            std::cout << "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc" << std::endl;
            ui.displayWinner(starterPlayer, players[starterPlayer].getName());
            for (int i = 0; i < identity.getPlayerNumber(); i++)
                players[i].eraseAllPlayedCards();
            uiStates = warzoneMap;
            break;
        }
        case showValidCardsForMatarsak:
        {
            ui.validCardsForMatarsak();
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
        case UISaveInfo:
        {
            saveAllInfo(TurnControl);
            break;
        }
        case controlExit:
        {
            checkSaveGame = ui.ExitGameControl();
            if (checkSaveGame == 1)
                uiStates = UISaveInfo;
            break;
        }
        }
    }
    // std::cout << "do you want to start a new game or continue or previous game ? " << std::endl;
    // std::cin >> newOrContinue;
    // ui.displayMenuBackground();
    // // Map mapForUI;
    // std::cout << "c1" << std::endl;
    // bool exitGame = true;
    // bool exitPrevious = true;
    // ifCardsAreSet = false;
    // newOrContinue = ui.menuGameLoop();
    // int uiNumberPlayers = ui.displayPlayerNumberButton();
    // ui.initializeCardTextureAndName();
    // // ui.renderTextureForCharacterOnGame();
    // //  StartNewGame();

    // // ui.Textbox();
    // // ui.renderTextureForWarzoneMap();
    // while (WindowShouldClose() == false && exitGame == true /*&& exitPrevious == true*/)
    // {
    //     // for (int i = 0; i < 1; i++)
    //     if (newOrContinue == "n")
    //     {
    //         std::cout << "display " << std::endl;
    //         identity.setPlayerNumberForSave(uiNumberPlayers);
    //         if (uiNumberPlayers == 3)
    //         {
    //             std::cout << "uiNumberPlayers -> " << uiNumberPlayers << std::endl;
    //             std::cout << "identity.getPlayerNumber - > " << identity.getPlayerNumber() << std::endl;
    //             for (int i = 0; i < 3; i++)
    //             {
    //                 ui.thripleTextBoxDraw();
    //                 std::cout << "for text box" << i << std::endl;
    //                 identity.setPlayerNameForSave(ui.getPlayerNameAndColorFromUI(i));
    //                 identity.setPlayerAgeForSave(ui.getPlayerAgeAndLuckFromUI(i + 3));
    //                 identity.setPlayerColorForSave(ui.getPlayerNameAndColorFromUI(i + 6));
    //                 identity.setPlayerForSave();
    //                 // setNameForUI(ui.getNamesFromUI(i));
    //                 // setNameFromUI(ui.getFullNameFromUI(i));
    //                 // setNameFromUI(ui.thripleTextBoxDraw(i));
    //                 // ui.controlTransitionVectors(i);
    //                 // setAgeForUI(ui.getAgeFromUI(i + 3));
    //                 // ui.controlTransitionVectors(i + 3);
    //                 // std::cout << "size vector ui -> " << ui.getNamesFromUI(i).size() << std::endl;
    //                 // std::cout << "karaye ajib - > " << i << identity.getPlayerNameForUI() << std::endl;
    //                 // std::cout << "karaye ajib2 - > " << i << identity.getPlayerAgeForUI() << std::endl;
    //                 // std::cout << "size vector ui for age -> " << ui.getAgeFromUI(i).size() << std::endl;
    //                 // ui.Textbox();
    //             }
    //             for (int i = 0; i < 3; i++)
    //             {
    //                 std::cout << "karaye ajib3 - > " << i << identity.getAge(i) << std::endl;
    //                 std::cout << "karaye ajib4 - > " << i << identity.getName(i) << std::endl;
    //                 std::cout << "karaye ajib4 - > " << i << identity.getColor(i) << std::endl;
    //             }
    //             ui.displayMap(identity.getName(determinMinAge()));

    //             // exitPrevious = false;
    //             std::cout << "salam" << std::endl;
    //             setWarzone(mapForUI.findKey(ui.displayWarzoneButton(identity.getName(determinMinAge())))); // setting warzone based on UI output
    //             std ::cout << "test" << std::endl;
    //             ui.getLuckNumbers(identity.getName(starterPlayer));
    //             goodLuckNumber = ui.getPlayerAgeAndLuckFromUI(0);
    //             badLuckNumber = ui.getPlayerAgeAndLuckFromUI(1);
    //             ui.displayCharectersAndNames(identity.getName(0), identity.getName(1), identity.getName(2));
    //             ui.displaySelectedWarzone(warzone);
    //             ui.displayGameTable();
    //             // dealingCards();
    //             // shuffelingCards();
    //             // randomCardSet();
    //             if (!ifCardsAreSet)
    //                 StartNewGame();
    //             // diplayBeggingOfTheGame();
    //             std::cout << "ghable playingInput" << std::endl;
    //             // playingInput();
    //             std::cout << "ghable findTexture" << std::endl;
    //             // for (int k = 0; k < identity.getPlayerNumber(); k++)
    //             ui.findTexture(players[0].getAllPlayerCards());
    //             std::cout << "bade findTexture" << std::endl;

    //             ui.renderTextureForCharacterOnGame();
    //             std::cout << "bade renderTextureForCharacterOnGame" << std::endl;

    //             // exitGame = false;
    //         }
    //         if (uiNumberPlayers == 4)
    //         {
    //             ui.quadrupleTextBoxDraw();
    //             std::cout << "uiNumberPlayers -> " << uiNumberPlayers << std::endl;
    //             for (int i = 0; i < 4; i++)
    //             {
    //                 identity.setPlayerNameForSave(ui.getPlayerNameAndColorFromUI(i));
    //                 identity.setPlayerAgeForSave(ui.getPlayerAgeAndLuckFromUI(i + 4));
    //                 identity.setPlayerColorForSave(ui.getPlayerNameAndColorFromUI(i + 8));
    //                 identity.setPlayerForSave();
    //                 std::cout << "for text box" << std::endl;
    //                 // ui.Textbox();
    //                 // std::cout << "karaye ajib - > " << identity.getPlayerNameForUI() << std::endl;
    //             }
    //             for (int i = 0; i < 4; i++)
    //             {
    //                 std::cout << "karaye ajib3 - > " << i << identity.getAge(i) << std::endl;
    //                 std::cout << "karaye ajib4 - > " << i << identity.getName(i) << std::endl;
    //                 std::cout << "karaye ajib4 - > " << i << identity.getColor(i) << std::endl;
    //             }
    //             // exitPrevious = false;
    //             // exitGame = false;
    //         }
    //         std::cout << "good luck -> " << goodLuckNumber << std::endl;
    //         std::cout << "bad luck -> " << badLuckNumber << std::endl;
    //         std::cout << "after display " << std::endl;
    //         // exitGame = false;
    //     }
    //     if (newOrContinue == "c")
    //         exitGame = false;
    //     if (newOrContinue == "help")
    //         exitGame = false;
    //     if (newOrContinue == "exit")
    //         exitGame = false;
    // }
    // std::cout << "c2" << std::endl;
    // std::cout << "c3" << std::endl;
    // if (newOrContinue == "c")
    // {
    //     std::cout << "if c " << std::endl;
    //     // if (isFileEmpty("save.txt") == 1) // if tellg == 0 is true
    //     // {
    //     //     std::cout << "No previous game found." << std::endl;
    //     //     menu();
    //     // }
    //     determinNumberOfSavedGame();
    //     saveReadAllInfo();
    //     std::cout << "IN menu!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    //     // else
    //     //     saveReadAllInfo();
    // }
    // else if (newOrContinue == "n")
    // {
    //     // int uiNumberPlayers = ui.displayPlayerNumberButton();
    //     // if (uiNumberPlayers == 3)
    //     // {
    //     //     std::cout << "uiNumberPlayers -> " << uiNumberPlayers << std::endl;
    //     //     exitPrevious = false;
    //     //     // exitGame = false;
    //     // }
    //     // if (uiNumberPlayers == 4)
    //     // {
    //     //     std::cout << "uiNumberPlayers -> " << uiNumberPlayers << std::endl;
    //     //     exitPrevious = false;
    //     //     // exitGame = false;
    //     // }
    //     StartNewGame();
    // }
    ui.unloadingTexture();
    // else
    //     return;

    // std::cout << "Exit Menu" << std::endl;
}
int Control::setPlayedCardsFromUI()
{

    std::cout << "to played Cards from UI" << std::endl;
    if (players[TurnControl].getIfPassed() == false)
    {
        std::cout << "turn control azizam " << TurnControl << std::endl;
        std::cout << "players[TurnControl].getIfPassed() aziztaram " << players[TurnControl].getIfPassed() << std::endl;
        for (int i = (turnHandlerAfterEachWar / 3); i < ui.getPlayedCardsFromUI().size(); i++)
        {
            std::cout << "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii " << i << std::endl;
            std::cout << "hi " << identity.getName(TurnControl) << ui.getPlayedCardsFromUI().size() << std::endl;
            selectedCard.setName(ui.getPlayedCardsFromUI()[i]);
            players[TurnControl].setPlayedCard(selectedCard);
            eraseSelectedCard();
            std::cout << "lalala " << selectedCard.getName() << std::endl;
            if (selectedCard.getName() == "matarsak")
                return 4;
            if (selectedCard.getName() == "parcham_dar")
                return 5;
        }
        std::cout << "playerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr " << players[TurnControl].getNumberOfPlayedCards() << std::endl;
        return 3;
    }
    return 7;
    // for (int i = 0; i < players[TurnControl].getNumberOfPlayedCards(); i++)
    // {
    //     std::cout << "to control player aziz " << players[TurnControl].getNumberOfPlayedCards() << "cards " << identity.getName(TurnControl) << " " << players[TurnControl].getPlayedCard(i).getName() << std::endl;
    // }
}
void Control::eraseSelectedCard()
{
    for (int i = 0; i < players[TurnControl].getNumberOfPlayedCards(); i++)
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
    std::cout << "number of players " << identity.getPlayerNumber() << std::endl;
    std::string playerName;
    int playerAge;
    std::string playerColor;
    bool playerPosotion;
    save >> playerName >> playerAge >> playerColor >> playerPosotion;
    std::cout << "name of players- > " << playerName << std::endl;
    std::cout << "age of players- > " << playerAge << std::endl;
    std::cout << "color of players -> " << playerColor << std::endl;
    std::cout << "pass of players - > " << playerPosotion << std::endl;
    std::cout << "after of players" << std::endl;
    identity.setPlayerNameForSave(playerName);
    identity.setPlayerAgeForSave(playerAge);
    identity.setPlayerColorForSave(playerColor);
    identity.setPlayerForSave();
    players.push_back(Player(identity.getAge(index), identity.getName(index), identity.getColor(index), playerPosotion));
    std::cout << "name identity of players- > " << identity.getName(index) << std::endl;
    std::cout << "age identity of players - > " << identity.getAge(index) << std::endl;
    std::cout << "color identity of players -> " << identity.getColor(index) << std::endl;
    std::cout << "akhar identity of players" << std::endl;
}
void Control::saveReadPlayerStates(int index)
{
    std::string stringOwendStates;    // string persisting the states
    std::string stringNumberOfStates; // get the string containing the number of
    int numberOfStates;
    save >> stringNumberOfStates >> numberOfStates;
    save >> stringOwendStates;
    // save >> numberOfStates;
    // players[index].setOwenedStates(numberOfStates);
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
    std::cout << "number of played cards: " << numberOfPlayedCards << std::endl;
    save >> stringNumberOfCards >> numberOfPlayedCards;
    save >> stringPlayedCards;
    std::cout << "string of played cards: " << stringPlayedCards << std::endl;
    for (int i = 0; i < numberOfPlayedCards; i++)
    {
        save >> stringPlayedCards;
        std::cout << "played card " << i << stringPlayedCards << std::endl;
        players[index].setPlayedCard(stringPlayedCards);
        // std::cout << "players[index].getPlayedCard() -> " << players[index].getPlayedCard(i).getName()<< std::endl;
    }
}
void Control::saveReadPlayerCardsInfo(int index)
{
    std::string stringPlayerCards, stringNumbrOfCards;
    int numberOfCards;
    save >> stringNumbrOfCards;
    save >> numberOfCards;
    std::cout << "number of player cards: " << numberOfCards << std::endl;
    save >> stringPlayerCards;
    std::cout << "string of player cards: " << stringPlayerCards << std::endl;
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
void Control::saveReadSigns()
{
    std::string stringWarzone;
    std::string stringPeaceSign;
    save >> stringWarzone >> warzone >> stringPeaceSign >> peaceSign;
    std::cout << "warzone -> " << warzone << "peacesign -> " << peaceSign << std::endl;
}
void Control::saveReadStarterPlayerAndSelectedCard()
{
    std::string stringStarterPlayer;
    save >> stringStarterPlayer >> starterPlayer;
}
void Control::saveReadAllInfo()
{
    save.open(numberOfSavedGames[whichSavedGame - 1], std::ios::in | std::ios::out);
    if (!save.is_open())
    {
        std ::cerr << "Error opening the file!" << std::endl;
        return;
    }
    std::cout << "bad file khondan " << std::endl;
    int intPlayerNumber;
    save >> intPlayerNumber;
    // std::cout << "bad tedad bazikon khondan " << std::endl;
    identity.setPlayerNumberForSave(intPlayerNumber);
    std::cout << "identity.getPlayerNumberForSave -> " << identity.getPlayerNumber() << std::endl;
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        std::cout << "ghabl player info " << std::endl;
        saveReadPlayerInfo(i);
        std::cout << "bad player info " << std::endl;
        saveReadPlayerStates(i);
        std::cout << "ghabl player card " << std::endl;
        saveReadPlayerCardsInfo(i);
        std::cout << "ghabl played card " << std::endl;
        saveReadPlayedCardsInfo(i);
        std::cout << "player " << i << "tamoom shod\n\n"
                  << std::endl;
    }
    std::cout << "ghbl played bahar " << std::endl;
    saveReadBaharVSZemestan();
    std::cout << "ghbl played signs " << std::endl;
    saveReadSigns();
    std::cout << "ghbl played starter player " << std::endl;
    saveReadStarterPlayerAndSelectedCard();
}
void Control::StartNewGame()
{
    std::cout << "shoroe StartNewGame" << std::endl;
    if (!ifCardsAreSet)
    {
        // std::cout << "ghabl validate " << std::endl;
        // validateIdentity();
        std::cout << "ghabl dealing " << std::endl;
        dealingCards();
        std::cout << "ghabl shuffle" << std::endl;
        shuffelingCards();
        std::cout << "ghabl random" << std::endl;
        randomCardSet();
        std::cout << "ghable randomCardSet" << std::endl;
        // diplayBeggingOfTheGame();
        std::cout << "ghable determinMinAge" << std::endl;
        determinMinAge();
        std::cout << "bad random function" << std::endl;
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
void Control::run()
{
    initializeSpecialCards();
    menu();
    std::cout << "safewe" << std::endl;
    // playingInput();
}
