#include <iostream>
#include "Bahar.hpp"
int Bahar ::effectOfCard(std::vector<Card> cards, int score)
{
    if (checkBaharPlayed)
    {
        if (ifMaxScoreCardIsInHand(cards))
            score += 3;
    }
    checkBaharPlayed = false;
    return score;
}
void Bahar::maxScoreForBahar(std::string str)
{
    baharMaxScore = str; // for accessing max score found in control
}
bool Bahar::ifMaxScoreCardIsInHand(std::vector<Card> cards)
{
    for (int i = 0; i < cards.size(); i++)
    {
        if (baharMaxScore == cards[i].getName())
        {
            return true;
        }
    }
    return false;
}
void Bahar::baharPlayed()
{
    checkBaharPlayed = true;
}