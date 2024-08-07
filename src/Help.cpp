#include <sstream>
#include "Help.hpp"
Help ::Help()
{
    setHelpOrders();
}
bool Help::setHelpOrders()
{
    readHelpFile.open("../src/help.txt", std::ios::in);
    if (!readHelpFile.is_open())
    {
        std ::cerr << "Error opening the file!" << std::endl;
        return 1;
    }
    while (!readHelpFile.eof())
    {
        for (int i = 0; i < 5; i++)
        {
            std::istringstream textHelp(line);
            readHelpFile >> key;
            std::getline(readHelpFile, line);
            help.insert({key, line});
        }
    }

    return 0;
}
std::string Help::searchInHelps(std::string str)
{
    return help.at(str);
}
