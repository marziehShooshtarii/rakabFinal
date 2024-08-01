#include "Player.hpp"
Player::Player() {}
// Player::Player(int p_numberOfPlayers)
// {
//     if (p_numberOfPlayers >= 3 && p_numberOfPlayers <= 6)
//         setNumberOfPlayers(p_numberOfPlayers);
// }
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

Card Player::getPlayerCard(int i)
{
    return playerCardList[i];
}
void Player::setPlayerCard(Card p_playerCard)
{
    playerCardList.push_back(p_playerCard);
}
void Player::setIfPassed(bool P_ifPassed)
{
    this->ifPassed = P_ifPassed;
}
bool Player::getIfPassed()
{
    return ifPassed;
}
void Player::setOwenedStates(std::string state)
{
    owenedStates.push_back(state);
}
std::string Player::getOwenedStates(int i)
{
    return owenedStates[i];
}
int Player::getNumberOfOwenedStates()
{
    return owenedStates.size();
}
void Player::setPlayedCard(Card p_playedCard)
{
    playedCardList.push_back(p_playedCard);
}
Card Player::getPlayedCard(int i)
{
    return playedCardList[i];
}
void Player::eraseCard(int index)
{
    playerCardList.erase(playerCardList.begin() + index);
}
int Player::getNumberOfPlayedCards()
{
    return playedCardList.size();
}
int Player::getNumberOfPlayerCards()
{
    return playerCardList.size();
}
void Player::erasePlayedCard(int index)
{
    playedCardList.erase(playedCardList.begin() + index);
}
void Player::eraseAllPlayedCards()
{
    playedCardList.clear();
}
void Player::setCharacter(Texture2D UICharacter)
{
    character = UICharacter;
}
std::vector<Card> Player::getAllPlayedCards()
{
    return playedCardList;
}
