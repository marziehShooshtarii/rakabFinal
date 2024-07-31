#include <bits/stdc++.h>
#include "Map.hpp"
Map::Map()
{
    initializeStates();
    setMapStates();
}
bool Map::setMapStates()
{
    readMapFile.open("matrix.txt", std::ios::in);
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
            {"enna", 2},
            {"atela", 3},
            {"dimase", 4},
            {"olivadi", 5},
            {"lia", 6},
            {"armento", 7},
            {"morina", 8},
            {"talmone", 9},
            {"elinia", 10},
            {"rollo", 11},
            {"pladaci", 12},
            {"borge", 13},
            {"alora", 14},

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
    std::cout << value << std::endl;
    std::cout << "inja" << std::endl;
    std::string_view key;
    auto it = states.begin();
     //auto it = std::find_if(states.begin(),states.end(),[&key](const auto& value){return value.first == key;});
    std::cout << "inja2" << std::endl;
    std::cout << it->second<<std::endl;
    while (it != states.end())
    {

        std::cout << "inja3" << std::endl;
        std::cout << it->second <<std::endl;
        if (it->second == value)
        {
            std::cout << "inja4" << std::endl;
            std::cout<<"mohem - >>>>> "<<it->first<<std::endl;
            return it->first;
        }
        std::cout << "inja5" << std::endl;
    std::cout << value << std::endl;
    it++;
    }
    std::cout << "inja6" << std::endl;
}
