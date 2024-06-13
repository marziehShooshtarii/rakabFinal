#ifndef MATARSAK_HPP
#define MATARSAK_HPP
#include <vector>
#include "Special.hpp"

class Matarsak: public Special
{
public :
virtual void effectOfCard(std::vector<Card>played,int index,std::vector<Card> inHand) override
{
    inHand.push_back(played[index]);
    played.erase(played.begin()+index);

}
};




#endif