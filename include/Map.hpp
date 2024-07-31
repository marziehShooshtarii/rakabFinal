#ifndef MAP_HPP
#define MAP_HPP
#include <fstream>
#include <unordered_map>
#include <iostream>
class Map
{
public:
    Map();
    bool setMapStates();
    void initializeStates();
    int searchInStates(std::string);
    int getNeighborMap(int i, int j);
    bool ifElementExists(std::string str);

private:
    std::unordered_map<std::string, int> states;

    bool neighborMap[15][15];
    std ::ifstream readMapFile;
};

#endif