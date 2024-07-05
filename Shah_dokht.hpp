#ifndef SHAH_DOKHT_HPP
#define SHAH_DOKHT_HPP
#include "Special.hpp"
class Shah_dokht : public Special
{
public:
    virtual int effectOfCard(std::vector<Card>,int score) override;
    
};

#endif