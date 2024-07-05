#include "Shirzan.hpp"
int Shirzan::effectOfCard(std::vector<Card> cards, int score)
{
    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i].getName() == "shirzan")
        {
            score++;
        }
    }
}