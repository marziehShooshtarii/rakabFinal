#ifndef TABL_ZAN_HPP
#define TABL_ZAN_HPP
#include "Special.hpp"
class Tabl_zan : public Special
{
public:
    virtual int effectOfCard(int score) override
    {
        return score *= 2;
    }
};

#endif