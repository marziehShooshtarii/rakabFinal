#include <iostream>
#include "Army.hpp"
// armyCard::armyCard(std::string name) : Card (name){};
int armyCard::increasScore(std::string str,int score)
{
    setCardScores();
    return (score + cardsScore.at(str));
}
