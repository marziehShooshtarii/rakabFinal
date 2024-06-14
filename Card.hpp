#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <unordered_map>
class Card
{
public:
    Card();
    Card(const std::string &p_nameOfCard);
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
    void setName(std::string p_name);
    bool operator==(const Card &c);

    // int searchInCardScore(std::string str);
    void kooft(int i);
    std ::unordered_map<std::string, int> cardsScore;
    void setCardScores();
    int searchInCardScore(std::string str);
    
    //std ::unordered_map<std::string, Card> stringToSpecialCard;
    //void setStringToSpecialCard();
   // void setSpacial();
    
private:
    // int numberOfCard;
    int characteristic;
    // int score;
    std::string typeOfCard;
    std::string nameOfCard;
    std::string explanation;
    std::string description;
   // std::vector<Special> special;
};
#endif
