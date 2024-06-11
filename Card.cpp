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
    this->description = p_description;
}
void Card::setName(std::string p_name)
{
    this ->nameOfCard = p_name; 
}
bool Card::operator == (const Card &c){ 
            if (nameOfCard == c.nameOfCard ) 
                return true; 
            return false; 
        } 