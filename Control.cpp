#include <unistd.h>
#include "Control.hpp"

Control::Control() {}
void Control::displayStarterPlayer()
{
    std::cout << "press enter to start the war ";
    std::cin.ignore();
    std::cout << identity.getName(starterPlayer) << " please choose the warzone";
    std::cin >> warzone;
}
void Control::displayWarzone()
{
    std::cout << "the selected warzone is " << warzone << " get ready for a war!!\n";
}
int Control::determinMinAge()
{

    std::cout << "getPlayerNumber ->" << identity.getPlayerNumber() << std::endl;
    int min = identity.getAge(0);
    for (int i = 1; i < identity.getPlayerNumber(); i++)
    {
        if (min > identity.getAge(i))
        {
            min = identity.getAge(i);
            starterPlayer = i;
        }
        std::cout << "i ->" << i << std::endl;
    }
    std::cout << "starterPlayer ->" << starterPlayer << std::endl;
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
        // sleep (5);
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

    // for (auto f : allCards)
    //     std::cout << f.getName() << "\n";
}
// void Control::setCardScores()
// {
//     cardsScore =
//         {
//             {"bahar", 0},
//             {"zemestan", 0},
//             {"matarsak", 0},
//             {"tabl_zan", 0},
//             {"shah_dokht", 0},
//             {"sarbaz_1", 1},
//             {"sarbaz_2", 2},
//             {"sarbaz_3", 3},
//             {"sarbaz_4", 4},
//             {"sarbaz_5", 5},
//             {"sarbaz_6", 6},
//             {"sarbaz_10", 10},
//         };
// }
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

        for (int i = 0; i < 10; i++)
        {

            randomCard = rand() % 89;
            playerCard[i] = allCards[randomCard];
            // adam.setPlayerCard(allCards[randomCard])
            players[j].setPlayerCard(allCards[randomCard]);
        }
        // for (const auto &card : playerCard)
        //     std::cout << card << " ";
        // std::cout << std::endl;
    }
    // for (size_t i = 0; i < identity.getPlayerNumber() * 10; i += 10)
    // {
    //     for (int j = i; j < i + 10; j++)
    //     {
    //         players[i].push_back(adam.getPlayerCard(j));
    //     }
    // }
    // for (int g=0 ; g < identity.getPlayerNumber() * 10 ; g ++)
    // {
    //     std::cout << players[g] << " ";
    // }
    // for (size_t k = 0; k < numberOfPlayer; k++)
    // {
    //     std::cout <<adam.getPlayerCard() << " ";
    // }
    // adam.getAge();
}

void Control::validateIdentity()
{
    identity.setPlayerNumber();
    identity.setData();
    std::cout << identity.getPlayerNumber() << std::endl;
}
void Control::shuffelingCards()
{
    random_shuffle(allCards.begin(), allCards.end());
}
// bool Control::winCheck()
// {
//     if (adam.getNumberOfOwenedStates() > 3)
//     {

//     }
// }
void Control::displayStartOfWar()
{
    std::cout << starterPlayer << "start the war by pressing enter" << std::endl;
}
bool Control::playingInput()

{
    while (1)
    {

        // std::cout<<"oni ke kharabe 0 - > "<<players[q].getNumberOfOwenedStates()<<std::endl;
        // std::cin.ignore();
        displayStarterPlayer();
        displayWarzone();
        for (int c = 0; c < identity.getPlayerNumber(); c++)
        {
            players[c].setIfPassed(false);
        }
        winner = -3;

        std::cout << "ifPassed - > " << players[0].getIfPassed() << std::endl;
        std::cout << "kooft 1 - > " << std::endl;
        std::cout << "kooft 2 - > " << std::endl;
        while (checkIfAllPlayersPassed())
        {
            std::cout << "kooft 3 - > " << std::endl;
            int indexControler = identity.getPlayerNumber();
            // std::cin.ignore();
            for (size_t i = starterPlayer; i < indexControler;)
            {
                std::cout << "kooft 4 - > " << std::endl;
                if (!checkIfCertianPlayerPassed(i))
                {
                    std::cout << "kooft 5 - > " << std::endl;
                    std::cout << players[i].getName() << " it's your turn " << "\n\tplease chose your card from the list or pass:\n " << "\t\n";
                    for (int k = 0; k < 10; k++)
                    {
                        std::cout << (players[i].getPlayerCard(k).getName()) << " ";
                    }
                    cinSelectedCard(i);

                    if (playingCards(i))
                    {
                        for (int k = 0; k < 10 - turn; k++)
                        {
                            std::cout << (players[i].getPlayerCard(k).getName()) << " ";
                        }

                        for (int r = 0; r < players[i].getNumberOfPlayedCards(); r++)
                        {
                            std::cout << "turn - > " << turn << std::endl;
                            std::cout << "\nthe cards on the floor: " << players[i].getPlayedCard(r).getName() << " ";
                            std::cout << "\nthe number of cards on the floor: " << players[i].getNumberOfPlayedCards() << " ";
                        }
                    }
                }
                //}
                i++;
                std::cout << std::endl;
                std::cin.ignore();
                // system("CLS");
                if (i == identity.getPlayerNumber())
                {
                    i = 0;
                    indexControler = starterPlayer;
                }
            }
            controlTurn();
        }
        // std::cout<<"oni ke kharabe 2 - > "<<players[q].getNumberOfOwenedStates()<<std::endl;
        determinWinnerOfWar();
        std::cout << "starter Player -> " << starterPlayer << std::endl;
        players[starterPlayer].setOwenedStates(warzone);
        for (int a = 0; a < players[starterPlayer].getNumberOfOwenedStates(); a++)
        {
            std::cout << "players[winner].getOwenedStates(a) -> " << players[starterPlayer].getOwenedStates(a) << " " << std::endl;
            std::cout << "players[winner].getname() - > " << players[starterPlayer].getName() << " " << std::endl;
            std::cout << "players[winner].getColors() -> " << players[starterPlayer].getColor() << std::endl;
        }
        // starterPlayer = winner;
        // winner = -3;
        //  setPlayers();
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
            // checkWin(q);
            {
                if (checkWin(q))
                    return true;
            }
        }
        // checkWin(q);
    }
}

bool Control::playingCards(int index)
{
    if (cardName == "pass")
    {
        players[index].setIfPassed(true);
        checkIfCertianPlayerPassed(index);
        return false;
    }
    for (int h = 0; h < 10; h++)
    {
        if ((players[index].getPlayerCard(h)) == selectedCard)
        {
            players[index].setPlayedCard(selectedCard);
            players[index].eraseCard(h);
            break;
        }
    }
    return true;
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
bool Control::cinSelectedCard(int index)
{
    Card selectedCardForMatarsak;
    std::cin >> cardName;
    if (cardName == "pass")
    {
        cardName = "pass";
        return false;
    }
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
            std::cout << "selectedCardForMatarsak - > " << selectedCardForMatarsak.getName() << std::endl;
            effectOfMatarsak(selectedCardForMatarsak, index);
        }
        return false;
    }

    selectedCard.setName(cardName);
    return true;
}
void Control::effectOfMatarsak(Card played, int index)
{
    Card matarsakCard; // for accessing Card member functions
    matarsakCard.setName("matarsak");
    players[index].setPlayerCard(played);
    players[index].erasePlayedCard(findSelectedCardForMatarsak(cardName, index));
    players[index].setPlayedCard(matarsakCard);
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
    card.setCardScores();
    for (int j = 0; j < identity.getPlayerNumber(); j++)
    {
        if (players[j].getNumberOfPlayedCards() == 0)
        {
            return "1";
        }
        maxScore = card.searchInCardScore(players[j].getPlayedCard(0).getName());
        std::cout << "maxScore -> " << maxScore << std::endl;
        for (int i = 1; i < players[j].getNumberOfPlayedCards(); i++)
        {
            if (maxScore > card.searchInCardScore(players[j].getPlayedCard(i).getName()))
            {
                maxScore = card.searchInCardScore(players[j].getPlayedCard(i).getName());
                maxScoreCardName = players[j].getPlayedCard(i).getName();
            }
        }
    }
    return "9";
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
        int repeatForEachCard[4] = {countZemestan(i), countTabl_zan(i), countBahar(i), countShir_dokht(i)};
        for (int j = 0; j < players[i].getNumberOfPlayedCards(); j++)
        {

            scorsAtEndOfWar[i] = army.increasScore(players[i].getPlayedCard(j).getName(), scorsAtEndOfWar[i]);
        }

        for (int k = 0; k < specialCards.size(); k++)
        {
            std::cout << "k -> " << k << std::endl;

            for (int g = 0; g < repeatForEachCard[k]; g++)
            {
                findMaxScoreCard();

                if (k == 2 && ifMaxScoreCardIsInHand(i))
                {
                    scorsAtEndOfWar[i] = specialCards[k]->effectOfCard(maxScore);
                }
                else
                {
                    scorsAtEndOfWar[i] = specialCards[k]->effectOfCard(scorsAtEndOfWar[i]);
                }
            }
            // for (int g = 0; g < countTabl_zan(i) && k == 1 ; g++)
            // {
            // specialCards[k]->effectOfCard(scorsAtEndOfWar[i]);
            // }
            // for (int g = 0; g < countBahar(i) && k == 2 ; g++)
            // {
            // specialCards[k]->effectOfCard(scorsAtEndOfWar[i]);
            // }
            // for (int g = 0; g < countShir_dokht(i) && k == 3 ; g++)
            // {
            // specialCards[k]->effectOfCard(scorsAtEndOfWar[i]);
            // }
        }

        if (scorsAtEndOfWar[i] > winnerScore)
        {
            winnerScore = scorsAtEndOfWar[i];
            winner = i;
        }
    }
    std::cout << "winner - > " << winner << std::endl;
    std::cout << players[winner].getName() << "-> winner" << std::endl;
    // players[winner].setOwenedStates(warzone);
    std::cout << "oon koofti ke kharabe - > " << players[winner].getNumberOfOwenedStates() << std::endl;
    // for (int a = 0; a < players[winner].getNumberOfOwenedStates(); a++)
    // {
    //     std::cout << "players[winner].getOwenedStates(a) -> " << players[winner].getOwenedStates(a) << " " << std::endl;
    //     std::cout << "players[winner].getname() - > " << players[winner].getName()<< " " << std::endl;
    //     std::cout << "players[winner].getColors() -> " << players[winner].getColor() << std::endl;
    // }
    starterPlayer = winner;
    int temp = winner;
    winner = -3;

    return players[temp].getName();
}
void Control::initializeSpecialCards()
{
    std::cout << "-> inja" << std::endl;
    Zemestan *z = new Zemestan();
    Tabl_zan *t = new Tabl_zan();
    Bahar *b = new Bahar();
    Shir_dokht *s = new Shir_dokht();

    specialCards.push_back(z);
    specialCards.push_back(t);
    specialCards.push_back(b);
    specialCards.push_back(s);

    std::cout << "-> inja" << std::endl;
}
// int Control::searchInCardScore(std::string str)
// {
//     return cardsScore.at(str);
// }
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
        if (players[index].getPlayedCard(j).getName() == "shir_dokht")
        {
            counter++;
        }
    }
    return counter;
}
bool Control ::checkingTheNeighborhoodOfTwoStates(int index, int first, int second)
{
    Map map; // for accessing Map's member functions.
    Map map2;
    std::cout << "checkingTheNeighborhoodOfTwoStates 1- >" << std::endl;
    // if (players[index].getNumberOfOwenedStates() > 2)
    // {
    map.initializeStates();
    map2.initializeStates();
    map2.setMapStates();
    initializeMapInControl();
    // std::cout << "oooooooooooooooooooo " << map2.searchInStates("bella") << std::endl;
    // ;
    // std::cout << "players[index].getOwenedStates(first) -> " << players[index].getOwenedStates(first) << std::endl;
    // std::cout << "map2.searchInStates(players[index].getOwenedStates(first)) -> " << map2.searchInStates(players[index].getOwenedStates(first)) << std::endl;
    // std::cout << "players[index].getOwenedStates(second) -> " << players[index].getOwenedStates(second) << std::endl;
    // std::cout << "map2.searchInStates(players[index].getOwenedStates(second)) -> " << map2.searchInStates(players[index].getOwenedStates(second)) << std::endl;
    // std::cout << "map2.searchInStates(players[index].getOwenedStates(first)) -> " << map2.searchInStates(players[index].getOwenedStates(first)) << std::endl;
    // std::cout << "map2.searchInStates(players[index].getOwenedStates(second)) -> " << map2.searchInStates(players[index].getOwenedStates(second)) << std::endl;
    // std::cout << "gggggggggggggggggggg " << map2.getNeighborMap(0, 1) << std::endl;
    // std::cout << "gggggggggggggggggggg " << map2.getNeighborMap(1, 6) << std::endl;
    // std::cout << "gggggggggggggggggggg " << map2.getNeighborMap(0, 6) << std::endl;
    // std::cout << "map2.getNeighborMap(map2.searchInStates(players[index].getOwenedStates(first)), map2.searchInStates- > " << map2.getNeighborMap(map2.searchInStates(players[index].getOwenedStates(first)), map2.searchInStates(players[index].getOwenedStates(second))) << std::endl;
    if (map2.getNeighborMap(map2.searchInStates(players[index].getOwenedStates(first)), map2.searchInStates(players[index].getOwenedStates(second))) == 1)
    // std::cout << "checkingTheNeighborhoodOfTwoStates 2- >" << std::endl;
    {
        counterNeighbores++;
        std::cout << "hhhhhhhhhhhhhhhhhhhhhhhhh -> true" << std::endl;
        return true;
    }
    // }
    std::cout << "checkingTheNeighborhoodOfTwoStates 3- >" << std::endl;
    std::cout << "hhhhhhhhhhhhhhhhhhhhhhhhh -> false" << std::endl;
    return false;
}
bool Control ::checkWin(int index)
{
    std::cout << "oni ke kharabe 1 - > " << players[index].getNumberOfOwenedStates() << std::endl;
    std::cout << "checkWin 1 -> " << std::endl;
    for (int i = 0; i < players[index].getNumberOfOwenedStates() - 1; i++)
    {
        std::cout << "checkWin 2 -> " << std::endl;
        checkingTheNeighborhoodOfTwoStates(index, i, i + 1);
    }
    std::cout << "checkWin 3 -> " << std::endl;
    checkingTheNeighborhoodOfTwoStates(index, 0, players[index].getNumberOfOwenedStates() - 1);

    if (counterNeighbores == 3 || players[index].getNumberOfOwenedStates() == 5)
    {
        std::cout << "checkWin 4 -> " << std::endl;
        winnerOfGame = players[index].getName();
        std::cout << "winnerOfGame -> " << winnerOfGame;
        std::cout << "true" << std::endl;
        return true;
    }
    std::cout << "checkWin 5 -> " << std::endl;
    std::cout << "false" << std::endl;
    return false;
}
void Control::initializeMapInControl()
{
    Map map;
    map.initializeStates();
    map.setMapStates();
}

int main()
{
    srand(unsigned(time(NULL)));
    Control c;
    Zemestan z;
    Tabl_zan t;
    Bahar b;
    Shir_dokht s;
    c.initializeMapInControl();
    c.initializeSpecialCards();
    c.validateIdentity();
    // c.setPlayers();
    c.dealingCards();
    c.shuffelingCards();
    c.randomCardSet();
    c.diplayBeggingOfTheGame();
    c.determinMinAge();
    // c.displayStarterPlayer();
    // c.displayWarzone();
    c.playingInput();
}
