#include <iostream>
#include "Army.hpp"
int Army::increasScore(std::string str, int score)
{
    setCardScores();
    return (score + cardsScore.at(str));
}
int Army::effectOfCard(std::vector<Card> playedCards, int score)
{
    for (int i = 0; i < playedCards.size(); i++)
    {
        score = score + cardsScore.at(playedCards[i].getName());
    }
    return score;
}