#include "Dealing.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
dealingCards::dealingCards() {}
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
        for (size_t i = 0; i < 10; i++)
        {
            randomCard = rand() % 107;
            playerCard[i] = allCards[randomCard];
            Player adam;
            adam.controlPlayerCard(playerCard[i]);
            Players.push_back(adam);
        }

        for (const auto &card : playerCard)
            std::cout << card << " ";
        std::cout << std::endl;
    }
    // for (size_t i = 0; i < numberOfPlayer; i++)
    // {
    //     std::cout << Players[i];
    //     std::cout << std::endl;
    //     /* code */
    // }
}
void dealingCards::validateIdentity()
{
    identity.setPlayerNumber();
}
void dealingCards::shuffelingCards()
{
    random_shuffle(allCards.begin(), allCards.end());
}
int main()
{
    srand(unsigned(time(NULL)));
    dealingCards r;
    r.setDealing();
    r.shuffelingCards();
    r.validateIdentity();
    r.randomCardSet();
    return 1;
}