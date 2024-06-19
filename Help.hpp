#ifndef HELP_HPP
#define HELP_HPP
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <vector>
class Help
{
public:
    Help();
    bool setHelpOrders();
    std::string searchInHelps(std::string);

private:
    std::ifstream readHelpFile;
    std::unordered_map<std::string,std::string> help;
    std::string line;
    std::string key;
    std::string value;
};

#endif