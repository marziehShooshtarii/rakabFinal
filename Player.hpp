#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Card.hpp"

class Player
{
public:
    Player();
    Player(int numberOfPlayers);
    Player(int age, std::string name, std::string color);
    Card getPlayerCard (int i);
    std::string getName();
    std::string getColor();
    void setNumberOfPlayers(int numberOfPlayer);
    void setPlayerCard(Card playerCard);
    int getNumberOfPlayer();
    int getAge();
    // void setOwenedStates(std::string);
    // std::string getOwenedStates(int i);
    // int getNumberOfOwenedStates();
    

private:
    int age;
    int numberOfPlayers;
    std::vector <Card> playerCardList;
    std::string name;
    std::string color;
    std::string card;
    // std::vector<enum states> owenedStates;
};
#endif
