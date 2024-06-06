#ifndef ARMY_HPP
#define ARMY_HPP
#include "Card.cpp"
class armyCard : public Card
{
public:
    armyCard(std::string name);
    void setCharacter(int value);
    int getScore();
    void SetNumberOfCard();
    void setName (std::string name);

private:
};
#endif