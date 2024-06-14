#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Card.hpp"

class Player
{
public:
    Player();
    Player(int numberOfPlayers);
    Player(int age, std::string name, std::string color, bool P_ifPassed);
    Card getPlayerCard(int i);
    std::string getName();
    std::string getColor();
    void setNumberOfPlayers(int numberOfPlayer);
    void setPlayerCard(Card P_playerCard);
    int getNumberOfPlayer();
    int getAge();
    void setPlayedCard(Card P_playedCard);
    Card getPlayedCard(int i);
    void eraseCard(int i);
    void setOwenedStates(std::string);
    std::string getOwenedStates(int i);
    int getNumberOfOwenedStates();
    void setIfPassed(bool P_ifPassed);
    bool getIfPassed();
    int getNumberOfPlayedCards();
    int getNumberOfPlayerCards();
    void erasePlayedCard(int index);

private:
    int age;
    int numberOfPlayers;
    std::vector<Card> playerCardList; // list of the cards each player has got in hand
    std::vector<Card> playedCardList; // list of cards played by the players
    std::vector<std::string> owenedStates;
    std::string name;
    std::string color;
    std::string card;
    bool ifPassed;
};
#endif
