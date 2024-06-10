#include <iostream>
#include <vector>
#include "Map.hpp"
#include "Dealing.hpp"
class Control {
    public:
    void diplayBeggingOfTheGame();
    private:
    std::vector <Player> players;
    getData gettingData;
    dealingCards playerDeck;
    int numberOfPlayers = gettingData.getPlayerNumber();
};