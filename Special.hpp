#ifndef SPEACIAL_HPP
#define SPEACIAL_HPP
#include "Card.hpp"

class Special : public Card
{
private:
public:
    Special(std::string name);
    void setCharacter(int value) override
    {
        Card::setCharacter(value);
    }
    void setNumberOfCard(int value);
    void setName(std::string name);
    // int getPriority();
};
#endif