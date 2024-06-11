#ifndef CARD_HPP
#define CARD_HPP
#include <string>
class Card
{
public:
    Card ();
    Card(const std::string& p_nameOfCard);
    virtual int getCharacter()
    {
        return characteristic;
    }
    virtual void setCharacter(int value)
    {
        characteristic = value;
    }
    void setExplanation(std::string p_description);
    std::string getName();

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
