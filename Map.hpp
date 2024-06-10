#ifndef MAP_HPP
#define MAP_HPP
#include <fstream>
class Map
{
public:
    bool setMapStates();
    // {
    //     for (int i = 0; i < 14; i++)
    //     {
    //         neighborMap [i][i] = 0;
    //     }

    // }
private:
    enum states
    {
        BELLA,
        CALIE,
        ENNA,
        ATELA,
        DIMASE,
        OLIVADI,
        LIA,
        ARMENTO,
        MORINA,
        TALMONE,
        ELINIA,
        ROLLO,
        PLADACI,
        BORGE
    };
    bool neighborMap[14][14];
    std ::ifstream readMapFile;
    // Player owner;
};

#endif