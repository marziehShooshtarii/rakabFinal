#include "Army.hpp"
armyCard::armyCard(std::string name) : Card (name){};

void armyCard::setCharacter (int value)
{
    Card::setCharacter(value);
}
int armyCard::getScore()
{
    return getCharacter();
}
void armyCard::SetNumberOfCard ()
{
    if (getScore () == 1)
        Card::setNumberOfCard (10);
    else 
        Card::setNumberOfCard(8);    
}
void armyCard::setName(std::string name)
{
    Card{name};
}

