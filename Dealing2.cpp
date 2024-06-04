#include "Dealing.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
dealingCards::dealingCards() {}
bool dealingCards::setDealing()
{
    std ::unordered_map<std ::string, int> deck = {
        {"bahar", 3},
        {"zemestan", 3},
        {"matarsak", 16},
        {"tabl_zan", 6},
        {"parchamdar", 3},
        {"shah_dokht", 3},
        {"sarbaz_1", 8},
        {"sarbaz_2", 10},
        {"sarbaz_3", 10},
        {"sarbaz_4", 10},
        {"sarbaz_5", 10},
        {"sarbaz_6", 10},
        {"sarbaz_10", 10},

    };
    std ::vector<std::string> allCards;
    for (const auto &pair : deck)
    {
        allCards.insert(allCards.end(), pair.second, pair.first);
    }
}

int main()
{
    srand(unsigned(time(NULL)));
    dealingCards r;
    // r.setValidNumberOfCards();
    r.setDealing();
    // r.setPlayerCard();
    return 1;
}