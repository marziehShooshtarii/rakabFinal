#include <cstring>
// #include "uiInput.hpp"
// Rectangle uiInput::getTextBoxRec()
// {
//     return textBoxRec;
// }
// char uiInput::getUIPlayerName(int index)
// {
//     return UIPlayerName[index];
// }
// std::vector<char> uiInput::getAllUIPlayerNames()
// {
//     return allUIPlayerNames;
// }
// void uiInput::initializeTextBoxRec()
// {
//     textBoxRec = {300, 200, 250, 50};
// }
// void uiInput::setUIPlayerName(int index, char playerName)
// {
//     UIPlayerName[index] = playerName;
// }

// char *uiInput::getFullName()
// {
//     return UIPlayerName;
// }
// void uiInput::resetInput()
// {
//     for (int i = 0; i < 50; i++)
//     {
//         UIPlayerName[i] = '\0';
//     }
// }
#include <raylib.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "uiInput.hpp"
uiInput::uiInput(float x, float y, float width, float height)
{
    textBox = {x, y, width, height};
    text[0] = '\0';
    letterCount = 0;
    active = false;
    mouseOnText = false;
}

void uiInput::Update()
{
    if (active)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
            {
                text[letterCount] = (char)key;
                letterCount++;
                text[letterCount] = '\0'; // Add null terminator at the end of string.
            }
            key = GetCharPressed(); // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            letterCount--;
            if (letterCount < 0)
                letterCount = 0;
            text[letterCount] = '\0';
        }
    }
}

void uiInput::Draw(Font font, int framesCounter)
{
    DrawRectangleRec(textBox, LIGHTGRAY);
    DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, (mouseOnText) ? RED : MAROON);
    DrawTextEx(font, text, (Vector2){textBox.x + 5, textBox.y + 8}, font.baseSize, 1, DARKGRAY);

    if (mouseOnText && active && (letterCount < MAX_INPUT_CHARS))
    {
        if (((framesCounter / 20) % 2) == 0)
            DrawText("_", (int)textBox.x + 8 + MeasureText(text, font.baseSize), (int)textBox.y + 12, font.baseSize, DARKGRAY);
    }
}

void uiInput::SetActive(bool isActive)
{
    active = isActive;
}
bool uiInput::IsMouseOnText(Vector2 mousePoint)
{
    mouseOnText = CheckCollisionPointRec(mousePoint, textBox);
    return mouseOnText;
}
void uiInput::transferPlayerNameToVector()
{
    std::cout << "--------------------------------" << std::endl;
    // for (int h = 0; h < strlen(text); h++)
    // {
    //     textBoxName[h] = text[h];
    // }
    // std::cout<<std::strlen(text)<<"string"<<std::endl;
    //  std::cout << textBoxName.size()<<"  ghabl textBoxName.size()" <<std::endl;
     textBoxName.insert(textBoxName.end(), text, text + letterCount);// -1 to avoid copying the null terminator
    std::cout << textBoxName.size() << " textBoxName.size()" << std::endl;
    // for (int h = 0; h < textBoxName.size(); h++)
    // {
    //     std::cout << textBoxName[h] << std::endl;
    // }
}

std::vector<char> uiInput::getTextBoxName()
{
    // std::vector<char> textBoxNames(std::begin(text), std::end(text) - 1); // -1 to avoid copying the null terminator
    return textBoxName;
}

// void uiInput::resetTarsferedVector()
// {
//     textBoxName.clear();
// }

void uiInput::convertTextToString()
{
    for (int i = 0; i < strlen(text); i++)
    {
        std::cout << "name -> " << text[i] << std::endl;
        nameConversion += text[i];
    }
    std::cout << "tempNames -> " << nameConversion << std::endl;
}
std::string uiInput::getTextBoxStringName()
{
    return nameConversion;
}
void uiInput::convertAgeToInteger()
{
    ageConversion = std::atoi(text);
}
int uiInput::getTextBoxIntAge()
{
    return ageConversion;
}