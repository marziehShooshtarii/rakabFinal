#ifndef SPEACIAL_HPP
#define SPEACIAL_HPP
#include "Card.hpp"

class Special : public Card
{
private:
public:
    Special(std::string name);
    void setCharacter(int value);
    void setNumberOfCard(int value);
    void setName(std::string name);
    int getPriority();
    int shirDokht ();
    int tablZan();
    int zemestan();
    int bahar();
    int matarsak();
};
#endif