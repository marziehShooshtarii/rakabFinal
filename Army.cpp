#include <iostream>
#include "Army.hpp"
int armyCard::increasScore(std::string str, int score)
{
    setCardScores();
    return (score + cardsScore.at(str));
}
