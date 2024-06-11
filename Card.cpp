#include "Card.hpp"
#include <string>
Card::Card(){}
Card::Card(const std::string &p_nameOfCard)
{
    nameOfCard = p_nameOfCard;
}

std::string Card::getName()
{
    return nameOfCard;
}
void Card::setExplanation(std::string p_description)
{
    this->description = description;
}