#include <unistd.h>
#include "Control.hpp"

Control::Control() {}
void Control::startOfWarMassage()
{
    std::cout << "press enter to start the war ";
}
void Control::displayStarterPlayer()
{
    std::cin.ignore();
    std::cout << identity.getName(starterPlayer) << " please choose the warzone ";
    std::cin >> warzone;
    while (!searchForExistingStates(warzone))
    {
        displayStarterPlayer();
    }
}
void Control::displayWarzone()
{
    std::cout << "the selected warzone is " << warzone << " get ready for a war!!\n";
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
         system("CLS");
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
            randomCard = rand() % 89;
            players[j].setPlayerCard(allCards[randomCard]);
        }
    }
}
void Control::validateIdentity()
{
    identity.setPlayerNumber();
    identity.setData();
    system("CLS");
}
void Control::shuffelingCards()
{
    random_shuffle(allCards.begin(), allCards.end());
}
void Control::displayStartOfWar()
{
    std::cout << starterPlayer << "start the war by pressing enter" << std::endl;
}
bool Control::playingInput()
{
    while (1)
    {
        startOfWarMassage();
        displayStarterPlayer();
        displayWarzone();
        displayOwenedStates();
        for (int c = 0; c < identity.getPlayerNumber(); c++)
        {
            players[c].setIfPassed(false);
        }
        winner = -3;

        while (checkIfAllPlayersPassed())
        {
            int indexControler = identity.getPlayerNumber();

            for (size_t i = starterPlayer; i < indexControler;)
            {

                if (!checkIfCertianPlayerPassed(i))
                {
                    for (int d = 0; d < identity.getPlayerNumber(); d++)
                        displayPlayedCards(d);

                    std::cout << players[i].getName() << " it's your turn " << "\n\tplease chose your card from the list or pass or ask for help :\n " << "\t\n";
                    displayPlayingCards(i);
                    int checkSelectedCard = cinSelectedCard(i);

                    playingCards(i, checkSelectedCard);
                }
                i++;
                std::cout << std::endl;
                std::cin.ignore();
                if (i == identity.getPlayerNumber())
                {
                    i = 0;
                    indexControler = starterPlayer;
                }
                system("CLS");
            }
            system("CLS");
            controlTurn();
        }
        determinWinnerOfWar();
        players[starterPlayer].setOwenedStates(warzone);
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
        for (int s = 0; s < identity.getPlayerNumber(); s++)
        {
            for (int n = 0; n < players[s].getNumberOfPlayedCards(); n++)
            {
                players[s].erasePlayedCard(n);
            }
        }
        for (int q = 0; q < identity.getPlayerNumber(); q++)
        {
            if (players[q].getNumberOfOwenedStates() > 2)
            {
                if (checkWin(q))
                    return true;
            }
        }
    }
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
    if (cardName == "pass")
    {
        players[index].setIfPassed(true);
        checkIfCertianPlayerPassed(index);
        return false;
    }
    if (checkSelectedCard == 2)
    {
        system("CLS");
        help(cinTypeOfHelp());
        std::cin.ignore();
        displayPlayingCards(index);
        playingCards(index, cinSelectedCard(index));
        return true;
    }
    if (checkSelectedCard != 3)
        return true;

    if (searchForExistingCards(index, selectedCard))
    {
        for (int h = 0; h < 10; h++)
        {
            if ((players[index].getPlayerCard(h)) == selectedCard)
            {
                if (selectedCard.getName() == "bahar" || selectedCard.getName() == "zemestan")
                {
                    baharVSzemestan.push_back(selectedCard);
                }
                players[index].setPlayedCard(selectedCard);
                players[index].eraseCard(h);
                break;
            }
        }
    }
    else
    {
        std::cout << "the choosen card is not your's!\nplease choose a valid card from the list:\n";
        displayPlayingCards(index);
        playingCards(index, cinSelectedCard(index));
    }
    return true;
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
        cardName = "pass";
        return 1;
    }
    if (cardName == "help")
    {
        return 2;
    }
    if (!checkMatarsakPlayed(index))
    {
        selectedCard.setName(cardName);
        return 3;
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
            std::cout << "please choose the card that you want to get back." << std::endl;
            for (int i = 0; i < players[index].getNumberOfPlayedCards(); i++)
            {
                std::cout << players[index].getPlayedCard(i).getName() << std::endl;
            }
            std::cin >> cardName;
            selectedCardForMatarsak.setName(cardName);
            effectOfMatarsak(selectedCardForMatarsak, index);
        }
        return true;
    }
    return false;
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
bool Control ::ifMaxScoreCardIsInHand(int index)
{
    for (int i = 0; i < players[index].getNumberOfPlayedCards(); i++)
    {
        if (findMaxScoreCard() == players[index].getPlayedCard(i).getName())
        {
            return true;
        }
    }
    return false;
}
std::string Control::determinWinnerOfWar()
{
    std::vector<int> scorsAtEndOfWar(identity.getPlayerNumber());
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        scorsAtEndOfWar[i] = 0;
    }
    int winnerScore = 0;
    winner = -3;
    for (int i = 0; i < identity.getPlayerNumber(); i++)
    {
        int repeatForEachCard[2] = {countTabl_zan(i), countShir_dokht(i)};
        for (int j = 0; j < players[i].getNumberOfPlayedCards(); j++)
        {

            scorsAtEndOfWar[i] = army.increasScore(players[i].getPlayedCard(j).getName(), scorsAtEndOfWar[i]);
        }

        if (baharVSzemestan.size() > 0)
        {
            if (baharVSzemestan[baharVSzemestan.size() - 1].getName() == "bahar")
            {
                Bahar bahar;
                findMaxScoreCard();
                if (ifMaxScoreCardIsInHand(i))
                {
                    scorsAtEndOfWar[i] = bahar.effectOfCard(maxScore);
                }
            }
            else
            {
                for (int r = 0; r < identity.getPlayerNumber(); r++)
                {

                    scorsAtEndOfWar[r] = players[r].getNumberOfPlayedCards() - countAllSpecialCards(i);
                }
            }
        }
        for (int k = 0; k < specialCards.size(); k++)
        {
            for (int g = 0; g < repeatForEachCard[k]; g++)
            {
                scorsAtEndOfWar[i] = specialCards[k]->effectOfCard(scorsAtEndOfWar[i]);
            }
        }
        if (scorsAtEndOfWar[i] > winnerScore)
        {
            winnerScore = scorsAtEndOfWar[i];
            winner = i;
        }

    }
    std::cout << "winner - > " << players[winner].getName() << std::endl;
    std::cin.ignore();
    system("CLS");
    starterPlayer = winner;
    int temp = winner;
    winner = -3;
    return players[temp].getName();
}
void Control::initializeSpecialCards()
{
    Tabl_zan *t = new Tabl_zan();
    Shah_dokht *s = new Shah_dokht();
    specialCards.push_back(t);
    specialCards.push_back(s);
}

int Control ::countTabl_zan(int index)
{
    int counter = 0;
    for (int j = 0; j < players[index].getNumberOfPlayedCards(); j++)
    {
        if (players[index].getPlayedCard(j).getName() == "tabl_zan")
        {
            counter++;
        }
    }
    return counter;
}
int Control ::countZemestan(int index)
{
    int counter = 0;
    for (int j = 0; j < players[index].getNumberOfPlayedCards(); j++)
    {
        if (players[index].getPlayedCard(j).getName() == "zemestan")
        {
            counter++;
        }
    }
    return counter;
}
int Control ::countBahar(int index)
{
    int counter = 0;
    for (int j = 0; j < players[index].getNumberOfPlayedCards(); j++)
    {
        if (players[index].getPlayedCard(j).getName() == "bahar")
        {
            counter++;
        }
    }
    return counter;
}
int Control ::countShir_dokht(int index)
{
    int counter = 0;
    for (int j = 0; j < players[index].getNumberOfPlayedCards(); j++)
    {
        if (players[index].getPlayedCard(j).getName() == "shah_dokht")
        {
            counter++;
        }
    }
    return counter;
}
int Control ::countMatarsak(int index)
{
    int counter = 0;
    for (int j = 0; j < players[index].getNumberOfPlayedCards(); j++)
    {
        if (players[index].getPlayedCard(j).getName() == "matarsak")
        {
            counter++;
        }
    }
    return counter;
}
int Control ::countAllSpecialCards(int index)
{
    return countBahar(index) + countMatarsak(index) + countShir_dokht(index) + countTabl_zan(index) + countZemestan(index);
}
bool Control ::checkingTheNeighborhoodOfTwoStates(int index, int first, int second)
{
    Map map; // for accessing Map's member functions.
    Map map2;
    if (map2.getNeighborMap(map2.searchInStates(players[index].getOwenedStates(first)), map2.searchInStates(players[index].getOwenedStates(second))) == 1)
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
        winnerOfGame = players[index].getName();
        return true;
    }
    return false;
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
void Control::run()
{
    initializeSpecialCards();
    validateIdentity();
    dealingCards();
    shuffelingCards();
    randomCardSet();
    diplayBeggingOfTheGame();
    determinMinAge();
    playingInput();
}
