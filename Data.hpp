#include <iostream>
#include <vector>
#include <string>
#include "Player.cpp"
class getData {
    public:
    void setPlayerNumber();
    private:
    int playerAge;
    std::string PlayerName;
    std::string playerColor;
    std::vector<Player> players;
    int playerNumber;
};