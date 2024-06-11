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
    std::string getPlayerCard (int i);
    std::string getName();
    std::string getColor();
    void setNumberOfPlayers(int numberOfPlayer);
    void setPlayerCard(std::string playerCard);
    int getNumberOfPlayer();
    int getAge();
    void setOwenedStates(std::string);
    std::string getOwenedStates(int i);

private:
    int age;
    int numberOfPlayers;
    std::vector <std::string> playerCardList;
    std::string name;
    std::string color;
    std::string card;
    std::vector<std::string> owenedStates;
};
#endif
