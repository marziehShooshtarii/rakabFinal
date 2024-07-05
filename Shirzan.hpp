#ifndef SHIRZAN_HPP
#define SHIRZAN_HPP
#include "Special.hpp"
class Shirzan :public Special
{
    public:
    virtual int effectOfCard(std::vector<Card>,int score)override;
};
#endif 