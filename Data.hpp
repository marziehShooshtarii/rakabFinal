#ifndef DATA_H
#define DATA_H
#include <iostream>
#include "Player.hpp"
class getData
{
public:
    getData();
    int getAge(int i);
    std::string getName(int i);
    std::string getColor(int i);
    void setData();
    int getPlayerNumber();
    void setPlayerNumber();
    void selectColorForPleyer();
    std::string getColorForPlayer(int i);
    void eraseColorForPlayer(int i);
    void getPlayerSelectedColor(int i);
    void setPlayerName();
    void setAgeOfPlayers();
    int validateColor(std::string color);
    void displayColor(int i);

private:
    std::string PlayerName;
    std::string playerColor;
    std::vector<Player> players;
    std::vector<std::string> colorShow;
    int playerAge;
    int playerNumber;
};

#endif