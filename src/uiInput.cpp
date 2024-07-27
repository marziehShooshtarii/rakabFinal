#include "uiInput.hpp"
Rectangle uiInput::getTextBoxRec()
{
    return textBoxRec;
}
char uiInput::getUIPlayerName(int index)
{
    return UIPlayerName[index];
}
std::vector<char> uiInput::getAllUIPlayerNames()
{
    return allUIPlayerNames;
}
void uiInput::initializeTextBoxRec()
{
    textBoxRec = {300, 200, 250, 50};
}
void uiInput::setUIPlayerName(int index, char playerName)
{
    UIPlayerName[index] = playerName;
}

char *uiInput::getFullName()
{
    return UIPlayerName;
}
void uiInput::resetInput()
{
    for (int i = 0; i < 50; i++)
    {
        UIPlayerName[i] = '\0';
    }
}