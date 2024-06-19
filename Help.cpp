#include <sstream>
#include "Help.hpp"
Help ::Help()
{
    std::cout << "bala" << std::endl;
    setHelpOrders();
    std::cout << "paiin" << std::endl;
}
bool Help::setHelpOrders()
{
    //std::cout << "111111111111111111111111" << std::endl;
    readHelpFile.open("help.txt", std::ios::in);
    if (!readHelpFile.is_open())
    {
        std ::cerr << "Error opening the file!" << std::endl;
        return 1;
    }
    // for (int i = 0; i < 14; i++)
    // {
    //     for (int j = 0; j < 14; j++)
    //     {
    //         readHelpFile >> ;
    //     }
    // }
    // for (int i = 0; i < 14; i++)
    // {
    //     for (int j = 0; j < 14; j++)
    //     {
    //         std::cout << neighborMap[i][j] <<std::endl;
    //     }
    // }
   // std::cout << "222222222222222222222222" << std::endl;
    while (!readHelpFile.eof())
    {
        std::istringstream textHelp(line);
        readHelpFile >> key;
        std::cout <<key<<std::endl;
         std::getline(readHelpFile, line);
        //std::cout << "3333333333333333333333" << std::endl;
        //std::cout << "44444444444444444444" << std::endl;
        // std::string key{};
        // std::string value{};
        // textHelp(line);
        //std::cout << "555555555555555555555555555555555555" << std::endl;
        //std::vector <std::string >values;
        //  while (textHelp)
        //  {
       // std::cout << "666666666666666666666666666" << std::endl;
    //    for(int i = 0; i < 2 ;i++)
    //    {
    // for (int i = 0; i < 2; i++)

    //     readHelpFile >> values[i];
        //std::cout <<value<<std::endl;

      // }
        // values.push_back(value);
        // }
        //std::cout << "1321"<<values.size()<<std::endl;
        //std::cout << "77777777777777777777" << std::endl;
        //for(int i = 0; i < 2 ;i++)
        //std::vector<double> values{};
        help.insert({key, line});
        // for (auto itr = help.begin(); itr != help.end(); ++itr)
        // {
        //     std::cout << itr->first
        //               << '\t' << itr->second << '\n';
        // }
        // for (int i= 0; i < 2; i++)
        // {

        //std::cout << "sssssssssssssssssssssssssssssssssssssssssssssssssss" << help.at("help") << std::endl;
       // }
        //;
    }
    return 0;
}
std::string Help::searchInHelps( std::string str)
{
    //std::cout<<"qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"<<std::endl;
    return help.at(str);
}
//}