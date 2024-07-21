#ifndef UIINPUT_HPP
#define UIINPUT_HPP
#include "raylib.h"
#include <string>
#include <vector>
class uiInput
{
private :
    std::string UIPlayerName;
    std::vector <std::string> allUIPlayerNames;
    Rectangle textBoxRec;
public:
    std::string getUIPlayerName();
    std::vector <std::string> getAllUIPlayerNames();
    Rectangle getTextBoxRec();
    void initializeTextBoxRec();

};
#endif 