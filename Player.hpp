<<<<<<< HEAD
#include <string>
class Player 
{
    public:
    Player(int Age, std::string Name, std::string COLOR);
    int getAge();
    std::string getName();
    std::string getColor();
    int getNumberOfPlayer();

private:
    int age;
    int numberOfPlayer;
    std::string name;
    std::string color;
};
=======
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include <iostream>
class Player
{
public:
    Player();
    Player(int numberOfPlayers);
    Player(int age, std::string name, std::string color);
    std::string getName();
    std::string getColor();
    void setNumberOfPlayers(int numberOfPlayer);
    void controlPlayerCard(std::string playerCard);
    void returnPlayerCard();
    int getNumberOfPlayer();
    int getAge();

private:
    int age;
    int numberOfPlayers;
    std::vector <std::string> playerCardList;
    std::string name;
    std::string color;
    std::string card;
};
#endif
>>>>>>> 10a37b3c6165781a99725dc5e57003351a18dfa0
