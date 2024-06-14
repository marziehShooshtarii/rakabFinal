#include <iostream>
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
    setCardScores();
    std::cout << "score army - > " << score  << std::endl;
    std::cout << "string army - > " << str << std::endl;
    std::cout << "cardsScore.at(str) army - > " << cardsScore.at(str) << std::endl;
    return (score + cardsScore.at(str));
}
