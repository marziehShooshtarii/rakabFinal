#ifndef ARMY_HPP
#define ARMY_HPP
#include "Card.hpp"
class armyCard : public Card
{
public:
    // armyCard(std::string name);
    void setCharacter(int value) override
    {
        Card::setCharacter(value);
    }
    int getCharacter() override
    {
        return Card::getCharacter();
    }
    //    void SetNumberOfCard();
    int increasScore(std::string,int score);
};
#endif
