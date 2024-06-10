#include "Player.hpp"

Player::Player() {}
Player::Player(int p_numberOfPlayers)
{
    if (p_numberOfPlayers >= 3 && p_numberOfPlayers <= 6)
        // this->numberOfPlayers = numberOfPlayers;
        setNumberOfPlayers(p_numberOfPlayers);
}
Player::Player(int p_age, std::string p_name, std::string p_color)
{
    this->age = p_age;
    this->color = p_color;
    this->name = p_name;
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
void Player::setNumberOfPlayers(int p_numberOfPlayer)
{
    this->numberOfPlayers = p_numberOfPlayer;
}
std::string Player::getPlayerCard()
{
    for (int i = 0; i < 30; i++)
    {
        std::cout << playerCardList[i] << " ";
    }
    // std::cout << "asghar ahgha";
}
void Player::controlPlayerCard(std::string p_playerCard)
{
    playerCardList.push_back(p_playerCard);
}

// int main ()
// {
//     std::vector <Player> adam;
//     adam.push_back(Player (4)) ;
//     std::cout << adam[0].getNumberOfPlayer();
// }
