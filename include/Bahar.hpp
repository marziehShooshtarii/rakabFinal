#ifndef BAHAR_HPP
#define BAHAR_HPP
#include <vector>
#include "Special.hpp"
class Bahar :public Special
{
public:
    virtual int effectOfCard(std::vector<Card>,int score)override;
    void maxScoreForBahar(std::string);
    bool ifMaxScoreCardIsInHand(std::vector<Card>);
    void baharPlayed();
private:
    std::string baharMaxScore;
    bool checkBaharPlayed = false;
};


#endif