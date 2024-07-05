#ifndef ARMY_HPP
#define ARMY_HPP
#include "Card.hpp"
class Army : public Card
{
public:
    int increasScore(std::string, int score);
    virtual int effectOfCard(std::vector<Card>,int score) override;
};
#endif
