#include "Card.hpp"
#include <string>
Card::Card(std::string nameOfCard)
{
    setName(nameOfCard);
}
int Card::getNumberOfCard()
{
    return numberOfCard;
}
void Card::setCharacter(int value)
{
    characteristic = value;
}
int Card::getCharacter()
{
    return characteristic;
}
std::string Card::getName()
{
    return nameOfCard;
}
void Card::setExplanation(std::string description)
{
    this->description = description;
}
void Card::setNumberOfCard (int numberOfCard)
{
    this->numberOfCard = numberOfCard;
}
void Card::setName(std::string nameofcard)
{
    this->nameOfCard = nameOfCard;
}