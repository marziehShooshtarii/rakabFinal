#ifndef UIINPUT_HPP
#define UIINPUT_HPP
#include "raylib.h"
#include <string>
#include <vector>
class uiInput
{
public:
    uiInput(float x, float y, float width, float height);
    uiInput();
    ~uiInput();
    void Update();
    void Draw(Font font, int framesCounter);
    void SetActive(bool isActive);
    bool IsMouseOnText(Vector2 mousePoint);
    void transferPlayerNameToVector();
    std::vector <char> getTextBoxName();
    void resetTarsferedVector();
    void convertTextToString();
    std::string getTextBoxStringName();
    void convertNumberToInteger();
    int getTextBoxIntNumber();
    char *getFullName();
    // char getUIPlayerName(int index);
    // std::vector <char> getAllUIPlayerNames();
    // Rectangle getTextBoxRec();
    // void initializeTextBoxRec();
    // void setUIPlayerName(int index,char);
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
    std::vector<char> textBoxName;
    std::string nameConversion;//converting player name to string
    int ageConversion;//converting player age to integer
};
#endif