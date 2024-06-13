#ifndef SPEACIAL_HPP
#define SPEACIAL_HPP
#include <vector>
#include "Card.hpp"
class Special : public Card
{
private:
public:
    // Special(std::string name);
    void setCharacter(int value) override
    {
        Card::setCharacter(value);
    }
    // int getPriority();
    virtual void effectOfCard(std::vector<Card>played,int index,std::vector<Card> inHand) = 0;

};
#endif