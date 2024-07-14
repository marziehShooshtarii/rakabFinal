#include<iostream>
#include"Shah_dokht.hpp"
int Shah_dokht::effectOfCard(std::vector<Card> cards, int score)
{
    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i].getName() == "shah_dokht")
        {
            score+=10;
        }
    }
    return score;
}