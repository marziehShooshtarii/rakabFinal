#include "uiInput.hpp"
Rectangle uiInput::getTextBoxRec()
{
    return textBoxRec;
}
std::string uiInput::getUIPlayerName()
{
    return UIPlayerName;
}
std::vector <std::string> uiInput::getAllUIPlayerNames()
{
    return allUIPlayerNames;
}
void uiInput::initializeTextBoxRec()
{
    textBoxRec = {100,220,250,50};
}