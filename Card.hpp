#ifndef CARD_HPP
#define CARD_HPP
#include <string>
class Card
{
public:
    Card(std::string nameOfCard);
    int getNumberOfCard();
    virtual int getCharacter()
    {
        return characteristic;
    }
    virtual void setCharacter(int value)
    {
        characteristic = value;
    }
    int getCharacter();
    int getNumberOfCard();
    void setNumberOfCard(int numberOfCard);
    void setCharacter(int value);
    void setExplanation(std::string description);
    std::string getName();
    void setName(std::string nameOfCard);

private:
    int numberOfCard;
    int characteristic;
    int score;
    std::string typeOfCard;
    std::string nameOfCard;
    std::string explanation;
    std::string description;
};
#endif
