#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <vector>
class Player
{
public:
    Player();
    Player(int numberOfPlayers);
    Player(int age, std::string name, std::string color);
    std::string getName();
    std::string getColor();
    void setNumberOfPlayers(int numberOfPlayer);
    void controlPlayerCard(std::string playerCard);
    void returnPlayerCard();
    int getNumberOfPlayer();
    int getAge();

private:
    int age;
    int numberOfPlayers;
    std::vector <std::string> playerCardList;
    std::string name;
    std::string color;
    std::string card;
};
#endif
