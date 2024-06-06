#include "Data.hpp"
#include <vector>
#include <iostream>
int getData::getPlayerNumber()
{
    std::cout << "Enter the number of players in the game:" << std::endl;
    std::cin >> playerNumber;
    players.push_back(Player(playerNumber));
    return playerNumber;
}
void getData::setPlayerNumber()
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
        setPlayerNumber();
    }
    // for (int i=0 ; i < playerNumber ; i++)
    // {
    //         std::cout <<players[i].getAge() << std::endl;
    //         std::cout <<players[i].getName() << std::endl;
    //         std::cout <<players[i].getColor() << std::endl;

    // }
}
// int main()
// {
//     getData e;
//     std::vector <Player> players;
//     e.setPlayerNumber(players);
// }