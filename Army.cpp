#include "Army.hpp"
// armyCard::armyCard(std::string name) : Card (name){};



// void armyCard::SetNumberOfCard ()
// {
//     if (getScore () == 1)
//         Card::setNumberOfCard (10);
//     else 
//         Card::setNumberOfCard(8);    
// }
int armyCard::increasScore(std::string str,int score)
{
    return score + cardsScore.at(str);
}
