#ifndef BAHAR_HPP
#define BAHAR_HPP
#include <vector>
#include "Special.hpp"
class Bahar : public Special
{
public:
 std::string effectOfBahar(std::vector<Card> played) 
    {
        // int maxScore = searchInCardScore(played[0].getName());
        // for (int i = 1; i < played.size(); i++)
        // {
        //     if (maxScore > searchInCardScore(played[i].getName()))
        //     {
        //         maxScore = searchInCardScore(played[i].getName());
        //     }
        // }
     
        // for (auto it = cardsScore)
        // std::cout<<maxScore->first;
    }
    int effectOfCard(int score)
    {
        return score+=3;
    }
};

#endif