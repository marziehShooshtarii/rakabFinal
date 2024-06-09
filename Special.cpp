#include "Special.hpp"
Special::Special(std::string name) : Card (name)
{
}
void Special::setName(std::string name)
{
    Card::setName(name);
}
void Special::setNumberOfCard(int numberOfCard)
{
    Card::setNumberOfCard(numberOfCard);
}