#include "Player.hpp"

Player::Player() {}
Player::Player(int p_numberOfPlayers)
{
    if (p_numberOfPlayers >= 3 && p_numberOfPlayers <= 6)
        // this->numberOfPlayers = numberOfPlayers;
        setNumberOfPlayers(p_numberOfPlayers);
}
Player::Player(int p_age, std::string p_name, std::string p_color, bool P_ifPassed)
{
    this->age = p_age;
    this->color = p_color;
    this->name = p_name;
    this->ifPassed = P_ifPassed;
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
Card Player::getPlayerCard(int i)
{
    // for (int i = 0; i < 30; i++)
    // {
    //     std::cout << playerCardList[i] << " ";
    // }
    return playerCardList[i];
    // std::cout << "asghar ahgha";
}
void Player::setPlayerCard(Card p_playerCard)
{
    playerCardList.push_back(p_playerCard);
}
void Player::setIfPassed(bool P_ifPassed)
{
    this ->ifPassed = P_ifPassed;
}
bool Player::getIfPassed()
{
    return ifPassed;
}
// void Player::setOwenedStates(std::string state)
// {
//     owenedStates.push_back(state);
// }
// std::string Player ::getOwenedStates(int i)
// {
//     return owenedStates[i];
// }
// int Player::getNumberOfOwenedStates ()
// {
//     return owenedStates.size();
// }
void Player::setPlayedCard(Card p_playedCard)
{
    playedCardList.push_back(p_playedCard);
}
Card Player::getPlayedCard(int i)
{
    return playedCardList[i];
}
void Player::eraseCard(int i)
{
    playerCardList.erase(playerCardList.begin() + i);
}
int Player::getNumberOfPlayedCards()
{
    return playedCardList.size();
}
// int Player ::countTabl_zan()
// {
//     for(int i = 0; i < playedCardList.size(); i++)
//     {
//         if (playedCardList[i])
//     }
//     playedCardList.getPlayedCard().count(playedCardList.begin(),playedCardList.end(),"tabl_zan")
// }
    // int main ()
    // {
    //     std::vector <Player> adam;
    //     adam.push_back(Player (4)) ;
    //     std::cout << adam[0].getNumberOfPlayer();
    // }
