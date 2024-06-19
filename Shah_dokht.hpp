#ifndef SHAH_DOKHT_HPP
#define SHAH_DOKHT_HPP
#include "Special.hpp"
class Shah_dokht : public Special
{
public:
    virtual int effectOfCard(int score) override
    {
        return score += 10;
    }
};

#endif