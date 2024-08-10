#include <bits/stdc++.h>
#include "Map.hpp"
Map::Map()
{
    initializeStates();
    setMapStates();
}
bool Map::setMapStates()
{
    readMapFile.open("../src/matrix.txt", std::ios::in);
    if (!readMapFile.is_open())
    {
        std ::cerr << "Error opening the file!" << std::endl;
        return 1;
    }
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            readMapFile >> neighborMap[i][j];
        }
    }

    return 0;
}

void Map::initializeStates()
{
    states =
        {
            {"bella", 0},
            {"caline", 1},
            {"lia", 2}, // the state's position is changed
            {"atela", 3},
            {"dimase", 4},
            {"olivadi", 5},
            {"enna", 6}, // the state's position is changed
            {"armento", 7},
            {"morina", 8},
            {"talmone", 9},
            {"elinia", 10},
            {"rollo", 11},
            {"pladaci", 12},
            {"borge", 13},
            {"alora", 14}, // new state added

        };
}
int Map::searchInStates(std::string str)
{
    return states.at(str);
}
int Map::getNeighborMap(int i, int j)
{
    return neighborMap[i][j];
}

bool Map::ifElementExists(std::string str)
{

    if (states.find(str) == states.end())
    {
        return false;
    }
    return true;
}

std::string Map::findKey(int value)
{
    std::string_view key;
    auto it = states.begin();
    std::cout << it->second << std::endl;
    while (it != states.end())
    {

        if (it->second == value)
        {
            return it->first;
        }
        it++;
    }
}
