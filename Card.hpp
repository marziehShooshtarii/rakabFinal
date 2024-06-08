#include <string>
class Card
{
public:
    int getCharacter();
    int getNumberOfCard();
    void setCharacter(int value);

private:
    int numberOfCard;
    int characteristic;
    int score;
    std::string typeOfCard;
    std::string nameOfCard;
    std::string explanation;
};