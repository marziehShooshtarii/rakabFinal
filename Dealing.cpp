#include "Dealing.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
dealingCards::dealingCards() {}
bool dealingCards::setDealing()
{
    dealingFile.open("Dealing.txt", std::ios::in);
    if (!dealingFile.is_open())
    {
        std ::cerr << "Error opening the file!" << std::endl;
        return 1;
    }
    for (int i = 0; i < 15; i++)
    {
        dealingFile >> Land;
        mapLand[i] = Land;
    }
}
void dealingCards::setPlayerCard()
{
    int numberOfLeftCard = 0;
    for (size_t i = 0; i < 10 && numberOfLeftCard <= 10; i++)
    {
        randomCard = rand() % 15;
        int numberOfCard = rand() % 10 + 1;
        if (numberOfCard <= validNumberOfCards[randomCard])
        {
            for (int i = numberOfLeftCard; i < numberOfCard; i++)
            {
                playerCard[i] = mapLand[randomCard];
            }
            numberOfLeftCard = numberOfCard;
        }
    }
    for (int i = 0; i < 10; i++)
        std::cout << playerCard[i] << " ";
}
bool dealingCards::setValidNumberOfCards()
{

    valueCard.open("valueCard.txt", std::ios::in);
    if (!valueCard.is_open())
    {
        std ::cerr << "Error opening the file!" << std::endl;
        return 1;
    }
    for (int i = 0; i < 15; i++)
    {
        int value;
        valueCard >> value;
        validNumberOfCards[i] = value;
    }
}

int main()
{
    srand(unsigned(time(NULL)));
    dealingCards r;
    r.setValidNumberOfCards();
    r.setDealing();
    r.setPlayerCard();
    return 1;
}