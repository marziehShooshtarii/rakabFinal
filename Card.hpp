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
    std ::unordered_map<std::string, int> cardsScore;
    void setCardScores();
    int searchInCardScore(std::string str);

private:
    int characteristic;
    std::string typeOfCard;
    std::string nameOfCard;
    std::string explanation;
    std::string description;
};
#endif
