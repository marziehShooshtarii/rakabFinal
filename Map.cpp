#include <fstream>
#include <iostream>
#include "Map.hpp"
bool Map::setMapStates()
{
    readMapFile.open("matrix.txt", std::ios::in);
    if (!readMapFile.is_open())
    {
        std ::cerr << "Error opening the file!" << std::endl;
        return 1;
    }
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            readMapFile >> neighborMap[i][j];
        }
    }
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            std::cout << neighborMap[i][j] <<std::endl;
        }
    }
    return 0;
}
int main (){
    Map map;
    map.setMapStates();
    return 0;
}