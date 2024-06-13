#ifndef SHIR_DOKHT_HPP
#define SHIR_DOKHT_HPP
#include "Special.hpp"
class shir_dokht : public Special
{
public:
    virtual int effectOfCard(int score) override 
    {
        return score+=10;
    }

};






#endif