#include<iostream>
#include"Tabl_zan.hpp"
int Tabl_zan::effectOfCard(std::vector<Card>cards ,int score)
{
    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i].getName() == "tabl_zan")
        {
            // score *= 2;//pervios tablzan effect
            score *= 1.5;//recent tablzan effect 
        
        }
    }
    return score;
}