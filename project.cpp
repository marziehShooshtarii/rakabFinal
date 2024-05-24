#include <iostream>
#include <fstream>
using namespace std;
class Map
{
public:
    int setMapFromFile()
    {
        mapFile.open("map.txt", ios::in);
        if (!mapFile.is_open())
        {
            cerr << "Error opening the file!" << endl;
            return 1;
        }
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                
                mapFile >> map[i][j];
                cout << map[i][j] << endl;
            }
        }
        
        return 0;
    }
    void printMap()
    {
        for (int i = 0; i < 7; i++)
        {

            for (int j = 0; j < 5; j++)
            {
                cout << map[i][j];
            }
        }
    }

private:
    string map[7][5];
    ifstream mapFile;
    struct mapStates
    {

    };
};
int main()
{
    Map m;
    m.setMapFromFile();
    m.printMap();
    return 0;
}
