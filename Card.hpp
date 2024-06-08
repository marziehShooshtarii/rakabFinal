<<<<<<< HEAD
=======
#ifndef CARD_HPP
#define CARD_HPP
>>>>>>> 10a37b3c6165781a99725dc5e57003351a18dfa0
#include <string>
class Card
{
public:
<<<<<<< HEAD
    int getCharacter();
    int getNumberOfCard();
    void setCharacter(int value);
=======
    Card(std::string nameOfCard);
    int getCharacter();
    int getNumberOfCard();
    void setNumberOfCard(int numberOfCard);
    void setCharacter(int value);
    void setExplanation(std::string description);
    std::string getName();
    void setName(std::string nameOfCard);
>>>>>>> 10a37b3c6165781a99725dc5e57003351a18dfa0

private:
    int numberOfCard;
    int characteristic;
    int score;
    std::string typeOfCard;
    std::string nameOfCard;
<<<<<<< HEAD
    std::string explanation;
};
=======
    std::string description;
};
#endif
>>>>>>> 10a37b3c6165781a99725dc5e57003351a18dfa0
