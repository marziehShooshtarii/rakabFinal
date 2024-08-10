#include <cstring>
#include <raylib.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "uiInput.hpp"
uiInput::uiInput(){
    
}
uiInput::uiInput(float x, float y, float width, float height)
{
    textBox = {x, y, width, height};
    text[0] = '\0';
    letterCount = 0;
    active = false;
    mouseOnText = false;
}

uiInput::~uiInput(){}
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
    Color selectedColor = {50, 180, 180, 225};
    DrawRectangleRec(textBox, {20, 205, 200 , 225});
    DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, (mouseOnText) ? selectedColor : DARKGRAY);
    DrawTextEx(font, text, (Vector2){textBox.x + 5, textBox.y + 8}, font.baseSize, 1, BLACK);

    if (mouseOnText && active && (letterCount < MAX_INPUT_CHARS))
    {
        if (((framesCounter / 20) % 2) == 0)
            DrawText("_", (int)textBox.x + 8 + MeasureText(text, font.baseSize), (int)textBox.y + 12, font.baseSize, BLACK);
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
    textBoxName.insert(textBoxName.end(), text, text + letterCount); // -1 to avoid copying the null terminator
}

std::vector<char> uiInput::getTextBoxName()
{
    return textBoxName;
}

void uiInput::convertTextToString()
{
    for (int i = 0; i < strlen(text); i++)
    {
        nameConversion += text[i];
    }
}
std::string uiInput::getTextBoxStringName()
{
    return nameConversion;
}
void uiInput::convertNumberToInteger()
{
    ageConversion = std::atoi(text);
}
int uiInput::getTextBoxIntNumber()
{
    return ageConversion;
}