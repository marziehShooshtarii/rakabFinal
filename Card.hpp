#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <unordered_map>
class Card
{
public:
    Card();
    Card(const std::string &p_nameOfCard);
    std::string getName();
    void setName(std::string p_name);
    bool operator==(const Card &c);
    std ::unordered_map<std::string, int> cardsScore;
    void setCardScores();
    int searchInCardScore(std::string str);

private:

    std::string nameOfCard;
};
#endif
