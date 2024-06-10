// #include <vector>
#include <iostream>
#include "Data.hpp"
void getData::setPlayerNumber()
{
    std::cout << "Enter the number of players in the game:" << std::endl;
    int number;
    std::cin >> number;
    this->playerNumber = number;
}
void getData::setData()
{
    if (playerNumber >= 3 && playerNumber <= 6)
    {
        for (size_t i = 0; i < playerNumber; i++)
        {
            std::cout << "Enter the " << i + 1 << " player name: ";
            std::cin >> PlayerName;
            std::cout << "Enter the " << i + 1 << " player age: ";
            std::cin >> playerAge;
            std::cout << "Enter the " << i + 1 << " player chosen color: ";
            std::cin >> playerColor;
            players.push_back(Player(playerAge, PlayerName, playerColor));
        }
    }
    else
    {
        std::cout << "invalid number of player!!!\ntry again:\t" << std::endl;
        setData();
    }
}
int getData::getPlayerNumber()
{
    return playerNumber;
}