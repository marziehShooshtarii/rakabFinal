#include <unistd.h>
#include "Control.hpp"

Control::Control()
{
    // for (int i= 0 ; i < identity.getPlayerNumber() ; i++)
    // {
    //     players
    // }
}
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
        std::cout << "margggggggggggggggggggggggggggggggggggggggggg" << std::endl;
        std::cout << "size of vector - > " << players[j].getNumberOfOwenedStates();
        for (int i = 0; i < (10 + players[j].getNumberOfOwenedStates()); i++)
        {
            std::cout << "to for random pakhsh kardan 0 " << std::endl;
            randomCard = rand() % 89;
            std::cout << "to for random pakhsh kardan 1 " << std::endl;
            // playerCard[i] = allCards[randomCard];
            // adam.setPlayerCard(allCards[randomCard])
            players[j].setPlayerCard(allCards[randomCard]);
            std::cout << "to for random pakhsh kardan 2 " << std::endl;
        }
        std::cout << "biron for random pakhsh kardan 3 " << std::endl;
        // for (const auto &card : playerCard)
        //     std::cout << card << " ";
        // std::cout << std::endl;
    }
    std::cout << "biron for asli random pakhsh kardan 4 " << std::endl;
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
        // randomCardSet();
        //  std::cout<<"oni ke kharabe 0 - > "<<players[q].getNumberOfOwenedStates()<<std::endl;
        //  std::cin.ignore();
        displayStarterPlayer();
        displayWarzone();
        for (int c = 0; c < identity.getPlayerNumber(); c++)
        {
            players[c].setIfPassed(false);
        }
        winner = -3;

        while (checkIfAllPlayersPassed())
        {
            int indexControler = identity.getPlayerNumber();
            // std::cin.ignore();
            for (size_t i = starterPlayer; i < indexControler;)
            {

                if (!checkIfCertianPlayerPassed(i))
                {
                    std::cout << players[i].getName() << " it's your turn " << "\n\tplease chose your card from the list or pass:\n " << "\t\n";
                    // for (int k = 0; k < 10; k++)
                    // {
                    //     std::cout << (players[i].getPlayerCard(k).getName()) << " ";
                    // }
                    displayPlayingCards(i);
                    bool checkformatarsak = cinSelectedCard(i);

                    if (playingCards(i, checkformatarsak))
                    {

                        displayPlayingCards(i);
                        // for (int k = 0; k < 10 - turn; k++)
                        // {
                        //     std::cout << (players[i].getPlayerCard(k).getName()) << " ";
                        // }

                        // for (int r = 0; r < players[i].getNumberOfPlayedCards(); r++)
                        // {
                        //     // std::cout << "turn - > " << turn << std::endl;
                        //     std::cout << "\nthe cards on the floor: " << players[i].getPlayedCard(r).getName() << " ";
                        //     // std::cout << "\nthe number of cards on the floor: " << players[i].getNumberOfPlayedCards() << " ";
                        // }
                        displayPlayedCards(i);
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
        for (int a = 0; a < players[starterPlayer].getNumberOfOwenedStates(); a++)
        {
            std::cout << "players[winner].getOwenedStates(a) -> " << players[starterPlayer].getOwenedStates(a) << " " << std::endl;
            std::cout << "players[winner].getname() - > " << players[starterPlayer].getName() << " " << std::endl;
            std::cout << "players[winner].getColors() -> " << players[starterPlayer].getColor() << std::endl;
        }
        // starterPlayer = winner;
        // winner = -3;
        //  setPlayers();
        // int count = 0;
        // std :: cout << "count - > " <<
        for (int s = 0; s < identity.getPlayerNumber(); s++)
        {
            for (int n = 0; n < players[s].getNumberOfPlayedCards(); n++)
            {
                players[s].erasePlayedCard(n);
                std::cout << "cards eraased " << std::endl;
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
void Control::displayPlayingCards(int index)
{
    for (int k = 0; k < players[index].getNumberOfPlayerCards(); k++)
    {
        std::cout << (players[index].getPlayerCard(k).getName()) << " ";
    }
}
bool Control::playingCards(int index, bool checkForMatarsak)
{
    if (cardName == "pass")
    {
        players[index].setIfPassed(true);
        checkIfCertianPlayerPassed(index);
        return false;
    }
    if (!checkForMatarsak)
        return true;

    if (searchForExistingCards(index, selectedCard))
    {
        // std :: cout << "card name in playing card func - >" << cardName << std::endl;
        // std :: cout << "selected card in playing card func - >" << selectedCard.getName() << std::endl;
        for (int h = 0; h < 10; h++)
        {
            std ::cout << "helooooooooooooooooooo" << std::endl;
            std ::cout << "selected card - > " << selectedCard.getName() << std::endl;
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
        std::cout << "selected card - > " << selectedCard.getName() << std::endl
                  << "card Name - > " << cardName << std::endl;
        playingCards(index , cinSelectedCard(index));
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
    for (int i = 0; i < players[index].getNumberOfPlayedCards(); i++)
    {
        std::cout << "the cards on the floor: \n"
                  << players[index].getPlayedCard(i).getName() << std::endl;
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
bool Control::cinSelectedCard(int index)
{
    std::cin >> cardName;
    if (cardName == "pass")
    {
        cardName = "pass";
        return false;
    }
    if (!checkMatarsakPlayed(index))
    {
        selectedCard.setName(cardName);
        return true;
    }
    return false;
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
            // std::cout << "selectedCardForMatarsak - > " << selectedCardForMatarsak.getName() << std::endl;
            effectOfMatarsak(selectedCardForMatarsak, index);
            // cardName = "matarsak";
        }
        return true;
        // std :: cout << "not returned" << std::endl;
    }
    return false;
}
void Control::effectOfMatarsak(Card played, int index)
{
    Card matarsakCard; // for accessing Card member functions
    matarsakCard.setName("matarsak");
    std ::cout << "played card - >" << played.getName() << std::endl;
    std ::cout << "matarsak card - >" << matarsakCard.getName() << std::endl;
    players[index].setPlayerCard(played);
    players[index].erasePlayedCard(findSelectedCardForMatarsak(cardName, index));
    // std :: cout << "after matarsak played cards on floor1\n";
    // displayPlayedCards(index);
    // std ::cout << std::endl;
    // displayPlayingCards(index);
    players[index].setPlayedCard(matarsakCard);
    // // std :: cout << "after matarsak played cards on floor2\n";
    // displayPlayedCards(index);
    // std ::cout << std::endl;
    // std :: cout << "after matarsak playing cards in hand\n";
    // displayPlayingCards(index);
    players[index].eraseCard(findMatarsak(index));
}
int Control ::findMatarsak(int i)
{
    // for (int i = 0; i < identity.getPlayerNumber(); i++)
    // {
    for (int j = 0; j < players[i].getNumberOfPlayerCards(); j++)
    {
        if (players[i].getPlayerCard(j).getName() == "matarsak")
        {
            std::cout << "find matarsak -> " << j << std::endl;
            return j;
        }
    }
    // }
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
        int repeatForEachCard[4] = {0, countTabl_zan(i), 0, countShir_dokht(i)};
        for (int j = 0; j < players[i].getNumberOfPlayedCards(); j++)
        {

            scorsAtEndOfWar[i] = army.increasScore(players[i].getPlayedCard(j).getName(), scorsAtEndOfWar[i]);
        }

        for (int k = 0; k < specialCards.size(); k++)
        {
            std::cout << "k -> " << k << std::endl;

            if (baharVSzemestan.size() > 0)
            {
                if (baharVSzemestan[baharVSzemestan.size() - 1].getName() == "bahar")
                {

                    findMaxScoreCard();
                    if (ifMaxScoreCardIsInHand(i))
                    {
                        scorsAtEndOfWar[i] = specialCards[2]->effectOfCard(maxScore);
                    }
                }
                else
                {
                    for (int r = 0; r < identity.getPlayerNumber(); r++)
                    {

                        scorsAtEndOfWar[r] = players[r].getNumberOfPlayedCards();
                    }
                }
            }
            for (int g = 0; g < repeatForEachCard[k]; g++)
            {

                // if (k == 2 && ifMaxScoreCardIsInHand(i))
                // {
                // }
                // else if (k == 0)
                // {
                //     for (int r = 0; r < identity.getPlayerNumber(); r++)
                //     {
                //        scorsAtEndOfWar[i] = players[r].getNumberOfPlayedCards();
                //     }
                // }

                scorsAtEndOfWar[i] = specialCards[k]->effectOfCard(scorsAtEndOfWar[i]);
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
    // std::cout << "-> inja" << std::endl;
    Zemestan *z = new Zemestan();
    Tabl_zan *t = new Tabl_zan();
    Bahar *b = new Bahar();
    Shah_dokht *s = new Shah_dokht();

    specialCards.push_back(z);
    specialCards.push_back(t);
    specialCards.push_back(b);
    specialCards.push_back(s);

    // std::cout << "-> inja" << std::endl;
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
        if (players[index].getPlayedCard(j).getName() == "shah_dokht")
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
    // std::cout << "checkingTheNeighborhoodOfTwoStates 1- >" << std::endl;
    // if (players[index].getNumberOfOwenedStates() > 2)
    // {
    map.initializeStates();
    map2.initializeStates();
    map2.setMapStates();
    initializeMapInControl();

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
        // std::cout << "checkWin 4 -> " << std::endl;
        winnerOfGame = players[index].getName();
        // std::cout << "winnerOfGame -> " << winnerOfGame;
        // std::cout << "true" << std::endl;
        return true;
    }
    // std::cout << "checkWin 5 -> " << std::endl;
    // std::cout << "false" << std::endl;
    return false;
}
void Control::initializeMapInControl()
{
    Map map;
    map.initializeStates();
    map.setMapStates();
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
int main()
{
    srand(unsigned(time(NULL)));
    Control c;
    Zemestan z;
    Tabl_zan t;
    Bahar b;
    Shah_dokht s;
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
