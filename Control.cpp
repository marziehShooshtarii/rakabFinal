#include "Control.hpp"
void Control::diplayBeggingOfTheGame()
{
    for (size_t i = 0; i < numberOfPlayers; i++)
    {
        playerDeck.validateIdentity();
        std::cout << "player number " << i+1 << "`s turn " << i << "\n\tpass the laptop to player number " << i << "\t";
        playerDeck.setDealing();
        playerDeck.shuffelingCards();
        playerDeck.randomCardSet();
        for (int j=0 ; j < numberOfPlayers * 10 ; j += 10)
        {
            for (int k=j ; k < j+10 ; k++)
            {
                std::cout << players[i].getPlayerCard(k);
            }
            std::cout << std:: endl;
        }
    }
}
int main ()
{
    Control c;
    c.diplayBeggingOfTheGame();
}
