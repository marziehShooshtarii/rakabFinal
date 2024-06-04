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
    for (size_t i = 0; i < 10; i++)
    {
        randomCard = rand() % 107;
        playerCard[i] = allCards[randomCard];
    }
    for (const auto &card : playerCard)
        std::cout << card << " ";
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
    r.randomCardSet();
    return 1;
}