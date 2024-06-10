#include <time.h>
#include <stdlib.h>
#include <algorithm>
// #include "Player.hpp"
#include "Dealing.hpp"

dealingCards::dealingCards(){
    
}

bool dealingCards::setDealing()
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
        allCards.insert(allCards.end(), pair.second, pair.first);
    }
}
int dealingCards::randomCardSet()
{
    for (int j = 0; j < numberOfPlayer; j++)
    {
        for (int i=0 ; i < 10; i++)
        {
            randomCard = rand() % 89;
            // playerCard[i] = allCards[randomCard];
            adam.controlPlayerCard(allCards[randomCard]);
        }
        // for (const auto &card : playerCard)
        //     std::cout << card << " ";
        // std::cout << std::endl;
    }
    // for (size_t k = 0; k < numberOfPlayer; k++)
    // {
    //     std::cout <<adam.getPlayerCard() << " ";
    // }
    // adam.getPlayerCard();
}

void dealingCards::validateIdentity()
{
    identity.setPlayerNumber();
    identity.setData();
}
void dealingCards::shuffelingCards()
{
    random_shuffle(allCards.begin(), allCards.end());
}
// int main()
// {
//     srand(unsigned(time(NULL)));
//     dealingCards r;
//     r.setDealing();
//     r.shuffelingCards();
//     r.validateIdentity();
//     r.randomCardSet();
//     return 1;
// }