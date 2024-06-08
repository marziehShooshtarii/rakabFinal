#ifndef ARMY_HPP
#define ARMY_HPP
#include "Card.hpp"
class armyCard : public Card
{
public:
void setCharacter ();
int getScore();
    armyCard(std::string name);
    void setCharacter(int value);
    int getScore();
    void SetNumberOfCard();
    void setName (std::string name);

};
#endif
