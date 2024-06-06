#include "Player.hpp"
#include <iostream>
#include <vector>
Player::Player(){}
Player::Player(int numberOfPlayers)
{
    if (numberOfPlayers >= 3 && numberOfPlayers <= 6)
    // this->numberOfPlayers = numberOfPlayers;
       setNumberOfPlayers(numberOfPlayers);
}
Player::Player(int age, std::string name, std::string color)
{
    this->age = age;
    this->color = color;
    this->name = name;
}
int Player::getAge()
{
    return age;
}
std::string Player::getName()
{
    return name;
}
std::string Player::getColor()
{
    return color;
}
int Player::getNumberOfPlayer()
{
    return numberOfPlayers;
}
void Player::setNumberOfPlayers(int numberOfPlayer)
{
    this->numberOfPlayers = numberOfPlayer;
}
void Player::controlPlayerCard(std::string playerCard)
{
    playerCardList.push_back(playerCard);
}
void Player::returnPlayerCard()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << playerCardList[i]<< std::endl;
    }
    
}
// int main ()
// {
//     std::vector <Player> adam;
//     adam.push_back(Player (4)) ;
//     std::cout << adam[0].getNumberOfPlayer();
// }