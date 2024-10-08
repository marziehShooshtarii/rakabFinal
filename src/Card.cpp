#include <string>
#include <iostream>
#include "Card.hpp"
Card::Card()
{
    setCardScores();
}
Card::Card(const std::string &p_nameOfCard)
{
    setCardScores();
    nameOfCard = p_nameOfCard;
}
std::string Card::getName()
{
    return nameOfCard;
}

void Card::setName(std::string p_name)
{
    this->nameOfCard = p_name;
}
bool Card::operator==(const Card &c)
{
    if (nameOfCard == c.nameOfCard)
        return true;
    return false;
}

void Card::setCardScores()
{
    cardsScore =
        {
            {"bahar", 0},
            {"zemestan", 0},
            {"matarsak", 0},
            {"tabl_zan", 0},
            {"shah_dokht", 0},
            {"shirzan", 0},
            {"rish_sefid", 0},
            {"parcham_dar", 0},
            {"fok_sefid", 0},
            {"rakhsh_sefid", 0},
            {"sarbaz_1", 1},
            {"sarbaz_2", 2},
            {"sarbaz_3", 3},
            {"sarbaz_4", 4},
            {"sarbaz_5", 5},
            {"sarbaz_6", 6},
            {"sarbaz_10", 10},
        };
}
int Card::searchInCardScore(std::string str)
{
    return cardsScore.at(str);
}
int Card::effectOfCard(std::vector<Card> playedCards, int score)
{
}
