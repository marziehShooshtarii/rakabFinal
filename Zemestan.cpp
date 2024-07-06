#include <iostream>
#include "Zemestan.hpp"
bool Zemestan::checkZemestanPlayed(false);
int Zemestan::effectOfCard(std::vector<Card> cards, int score)
{
    std::cout<<"checkZemestanPlayed - >"<<checkZemestanPlayed<<std::endl;
    if (checkZemestanPlayed)
    {

        score = cards.size() - countAllSpecialCards(cards);
        std::cout << "score dar zemestan - >" << score << std::endl;
    }
    return score;
}
void Zemestan:: endOfZemestan()
{
   Zemestan:: checkZemestanPlayed = false;
}
void Zemestan::zemestanPlayed()
{
    Zemestan::checkZemestanPlayed = true;
}
int Zemestan ::countAllSpecialCards(std::vector<Card> cards)
{
    return countBahar(cards) + countMatarsak(cards) + countShir_dokht(cards) + countTabl_zan(cards) + countZemestan(cards) + countRish_sefid(cards) + countShirzan(cards) + countParcham_dar(cards);
}
int Zemestan ::countTabl_zan(std::vector<Card> cards)
{
    int counter = 0;
    for (int j = 0; j < cards.size(); j++)
    {
        if (cards[j].getName() == "tabl_zan")
        {
            counter++;
        }
    }
    return counter;
}
int Zemestan ::countZemestan(std::vector<Card> cards)
{
    int counter = 0;
    for (int j = 0; j < cards.size(); j++)
    {
        if (cards[j].getName() == "zemestan")
        {
            counter++;
        }
    }
    return counter;
}
int Zemestan ::countBahar(std::vector<Card> cards)
{
    int counter = 0;
    for (int j = 0; j < cards.size(); j++)
    {
        if (cards[j].getName() == "bahar")
        {
            counter++;
        }
    }
    return counter;
}
int Zemestan ::countShir_dokht(std::vector<Card> cards)
{
    int counter = 0;
    for (int j = 0; j < cards.size(); j++)
    {
        if (cards[j].getName() == "shah_dokht")
        {
            counter++;
        }
    }
    return counter;
}
int Zemestan ::countMatarsak(std::vector<Card> cards)
{
    int counter = 0;
    for (int j = 0; j < cards.size(); j++)
    {
        if (cards[j].getName() == "matarsak")
        {
            counter++;
        }
    }
    return counter;
}
int Zemestan ::countShirzan(std::vector<Card> cards)
{
    int counter = 0;
    for (int j = 0; j < cards.size(); j++)
    {
        if (cards[j].getName() == "shirzan")
        {
            counter++;
        }
    }
    return counter;
}
int Zemestan ::countRish_sefid(std::vector<Card> cards)
{
    int counter = 0;
    for (int j = 0; j < cards.size(); j++)
    {
        if (cards[j].getName() == "rish_sefid")
        {
            counter++;
        }
    }
    return counter;
}
int Zemestan ::countParcham_dar(std::vector<Card> cards)
{
    int counter = 0;
    for (int j = 0; j < cards.size(); j++)
    {
        if (cards[j].getName() == "rish_sefid")
        {
            counter++;
        }
    }
    return counter;
}