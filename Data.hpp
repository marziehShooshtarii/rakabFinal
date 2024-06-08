#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"

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

#endif // !DATA_H