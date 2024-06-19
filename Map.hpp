#ifndef MAP_HPP
#define MAP_HPP
#include <fstream>
#include <unordered_map>
#include <iostream>
class Map
{
public:
    // bool setMapStates();
    //void initializeStates();
    //int searchInStates(std::string);
    //int getNeighborMap(int i, int j);
    Map()
    {
        initializeStates();
        setMapStates();
    }
    bool setMapStates()
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
    // for (int i = 0; i < 14; i++)
    // {
    //     for (int j = 0; j < 14; j++)
    //     {
    //         std::cout << neighborMap[i][j] <<std::endl;
    //     }
    // }
    return 0;
}
// int main (){
//     Map map;
//     map.setMapStates();
//     return 0;
// }
void initializeStates()
{
    states = 
    {
        {"bella",0},
        {"caline",1},
        {"enna",2},
        {"atela",3},
        {"dimase",4},
        {"olivadi",5},
        {"lia",6},
        {"armento",7},
        {"morina",8},
        {"talmone",9},
        {"elinia",10},
        {"rollo",11},
        {"pladaci",12},
        {"borge",13},

    };


}
int searchInStates(std::string str)
{
    //std::cout <<"states.at(str) - >" << states.at(str) <<std::endl;
   return states.at(str);
}
int getNeighborMap(int i,int j)
{
    return neighborMap[i][j];
}
bool ifElementExists(std::string str)
{
    
    if (states.find(str)==states.end())
    {
        std::cout<<"aaaaaaaaaaa"<<std::endl;
        return false;
    }
    std::cout<<"aaaaaaaaaaa 2"<<std::endl;
    return true;
}

private:
std::unordered_map<std::string,int>states;

    bool neighborMap[14][14];
    std ::ifstream readMapFile;
    // Player owner;
};


#endif