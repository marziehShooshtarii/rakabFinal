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
    virtual int effectOfCard(int score) = 0;

};
#endif