#include <iostream>
#include <vector>
#include <string>
#include "Player.cpp"
class getData {
    public:
    void setPlayerNumber();
    int getPlayerNumber();
    private:
    std::string PlayerName;
    std::string playerColor;
    std::vector<Player> players;
    int playerAge;
    int playerNumber;
};