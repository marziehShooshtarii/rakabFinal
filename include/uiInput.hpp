#ifndef UIINPUT_HPP
#define UIINPUT_HPP
#include "raylib.h"
#include <string>
#include <vector>
class uiInput
{
public:
    uiInput(float x, float y, float width, float height);
    void Update();
    void Draw(Font font, int framesCounter);
    void SetActive(bool isActive);
    bool IsMouseOnText(Vector2 mousePoint);
    // char getUIPlayerName(int index);
    // std::vector <char> getAllUIPlayerNames();
    // Rectangle getTextBoxRec();
    // void initializeTextBoxRec();
    // void setUIPlayerName(int index,char);
    // char* getFullName();
    // void resetInput();
// private :
    // char UIPlayerName[50];
    // std::vector <char> allUIPlayerNames;
    // Rectangle textBoxRec;
private:
    static const int MAX_INPUT_CHARS = 50;
    Rectangle textBox;
    char text[MAX_INPUT_CHARS + 1];
    int letterCount;
    bool mouseOnText;
    bool active;

};
#endif 