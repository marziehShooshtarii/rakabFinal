#ifndef BAHAR_HPP
#define BAHAR_HPP
#include <vector>
#include "Special.hpp"
class Bahar : public Special
{
public:

    int effectOfCard(int score)
    {
        return score+=3;
    }
};

#endif