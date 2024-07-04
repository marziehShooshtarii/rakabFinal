#include <iostream>
#include "Data.hpp"
getData::getData()
{
    selectColorForPleyer();
}
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
            if (playerAge < 0)
            {
                std::cout << "your age can't be under 0 ; please enter a valid age" << std::endl;
                std::cin >> playerAge;
            }
            std::cout << "Enter the " << i + 1 << " player chosen color from the list:\n";
            displayColor(i);
            getPlayerSelectedColor(i);
            players.push_back(Player(playerAge, PlayerName, playerColor, false));
        }
    }
    else
    {
        std::cout << "invalid number of player!!!\ntry again:\t" << std::endl;
        setPlayerNumber();
        setData();
    }
}
int getData::getPlayerNumber()
{
    return playerNumber;
}
void getData::getPlayerSelectedColor(int i)
{
    std::cin >> playerColor;
    int checkColorPosition = validateColor(playerColor); //find the color in the vector
    if (checkColorPosition != -1)
    {
        eraseColorForPlayer(checkColorPosition);       
    }
    else if (checkColorPosition == -1)
    {
        std::cout << "the color you've chosen is invalid ; please try again." << std::endl;
        displayColor(i);
        getPlayerSelectedColor(i);
    }
}
void getData::displayColor(int i)
{
    for (int j = 0; j < colorShow.size(); j++)
    {
        std::cout << colorShow[j] << " ";
    }
    std::cout << std::endl;
}
int getData::validateColor(std::string color)
{
    //determin whether the color is valid or not
    for (int i = 0; i < colorShow.size(); i++)
    {
        if (colorShow[i] == color)
            return i;
    }
    return -1; //used for invalid colors
}
void getData::selectColorForPleyer()
{
    colorShow.push_back("blue");
    colorShow.push_back("red");
    colorShow.push_back("yellow");
    colorShow.push_back("gray");
    colorShow.push_back("perple");
    colorShow.push_back("green");
}
std::string getData::getColorForPlayer(int i)
{
    return colorShow[i];
}
void getData::eraseColorForPlayer(int i)
{
    colorShow.erase(colorShow.begin() + i);
}