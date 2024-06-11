#include <unistd.h>
#include "Control.hpp"
// Player Control::getAge(int i)
// {
//     return bazikonha[i];
// }
 Control::Control(){}
void Control::displayStarterPlayer()
{
    std::cout <<identity.getName(starterPlayer) << " please choose the warzone";
    std::cin >> warzone;
}
void Control::dispalyWarzone()
{
    std:: cout << "the selected warzone is " << warzone << " get ready for a war!!\n";
}
int Control::determinMinAge()
{
    int min = identity.getAge(0);
    for (int i=1 ; i < identity.getPlayerNumber() ; i++)
    {
        if (min < identity.getAge(i))
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
    // std::cout << (identity.getPlayerNumber()) * 10 << std::endl;
    for (size_t i = 0; i < identity.getPlayerNumber();)
    {
        // for (int j = 0; j < (identity.getPlayerNumber()) * 10; j += 10)
        // {
            std::cout << "player number " << i + 1 << "s turn " << i + 1 << "\n\tpass the laptop to player number " << i + 1 << "\t\n";
            std::cin.ignore();
            // for (int g = 0; g < (identity.getPlayerNumber()); g++)
            // {
                for (int k = 0; k < 10; k++)
                {
                    std::cout << (players[i].getPlayerCard(k).getName()) << " ";
                }
            //}
            i++;
            std::cout << std::endl;
            // sleep (5);
            std::cin.ignore();
            system("CLS");
        //}
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

    
    for (const auto& pair : deck) {
            for (int i = 0; i < pair.second; ++i) {
                allCards.emplace_back(pair.first);
            }
        }

    for (auto f : allCards) 
        std::cout << f.getName() << "\n";

}
void Control::setPlayers()
{
    for (int i = 0; i < identity.getPlayerNumber() ; i++)
    {
        players.push_back(Player(identity.getAge(i), identity.getName(i), identity.getColor(i)));
    }
    
}
void Control::randomCardSet()
{
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

int main()
{
    srand(unsigned(time(NULL)));
    Control c;
    c.validateIdentity();
    c.setPlayers();
    c.dealingCards();
    c.shuffelingCards();
    c.randomCardSet();
    c.diplayBeggingOfTheGame();
    c.displayStarterPlayer();
    c.dispalyWarzone();
}
