#include "Button.hpp"
bool Button::ifPressed(Vector2 mousePos, bool mousePressed)
{
    // drawRectUI();
    if (CheckCollisionPointRec(mousePos, rectButton) && mousePressed)
    {
        return true;
    }
    return false;
}
Button::Button(Rectangle p_rect, const char *p_title, bool p_status)
{
    rectButton = p_rect;
    title = p_title;
    status = p_status;
}
Rectangle Button::getRectangle()
{
    return rectButton;
}
bool Button::getStatus()
{
    return status;
}
Button::Button()
{
}