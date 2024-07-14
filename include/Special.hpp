#ifndef SPEACIAL_HPP
#define SPEACIAL_HPP
#include <vector>
#include "Card.hpp"
class Special : public Card
{
private:
public:
    virtual int effectOfCard( std::vector<Card>,int score) = 0;
};
#endif