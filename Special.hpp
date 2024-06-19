#ifndef SPEACIAL_HPP
#define SPEACIAL_HPP
#include <vector>
#include "Card.hpp"
class Special : public Card
{
private:
public:
    void setCharacter(int value) override
    {
        Card::setCharacter(value);
    }
    virtual int effectOfCard(int score) = 0;
};
#endif