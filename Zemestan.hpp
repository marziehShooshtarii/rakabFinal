#ifndef ZEMESTAN_HPP
#define ZEMESTAN_HPP
#include "Special.hpp"
class Zemestan : public Special
{
public:
    virtual int effectOfCard(int score) override 
    {
        return score=1;
    }

};






#endif