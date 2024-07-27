#ifndef UIINPUT_HPP
#define UIINPUT_HPP
#include "raylib.h"
#include <string>
#include <vector>
class uiInput
{
private :
    char UIPlayerName[50];
    std::vector <char> allUIPlayerNames;
    Rectangle textBoxRec;
public:
    char getUIPlayerName(int index);
    std::vector <char> getAllUIPlayerNames();
    Rectangle getTextBoxRec();
    void initializeTextBoxRec();
    void setUIPlayerName(int index,char);

};
#endif 