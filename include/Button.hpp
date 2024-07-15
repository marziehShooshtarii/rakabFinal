#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "raylib.h"
class Button
{
    public:
    Button();
    Button(Rectangle,const char*,bool);
    bool ifPressed(Vector2 mousePos, bool mousePressed);
    Rectangle getRectangle();
    bool getStatus();
    const char* title;
private:
    //Vector2 possition;
    Rectangle rectButton;
    bool status;//if it's pressed 
};
#endif
