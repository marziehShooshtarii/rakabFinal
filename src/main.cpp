#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Control.hpp"
#include "raylib.h"

int windowWidth = 600;
int windowHeight = 800;
Rectangle rect{windowHeight / 2 - 100, windowHeight / 2 - 50, 200, 100};
bool ifPressed(Vector2 mousePos, bool mousePressed);
int main()
{
    InitWindow(windowWidth, windowHeight, "game");

    SetTargetFPS(60);
    Font font = LoadFont("../assets/KaushanScript-Regular.ttf");
    Texture2D background = LoadTexture("../assets/tunel for menu.png");
    Vector2 position;

    while (WindowShouldClose() == false)
    {
        //gggg
        Vector2 mousePssition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if (ifPressed(mousePssition,mousePressed))
        {
            std::cout<<"new game"<<std::endl;
        }
    
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(background, 0, 0, WHITE);
        DrawTextEx(font,"button",(Vector2){rect.x+10,rect.y+10},font.baseSize,1,RED);

        EndDrawing();
    }
    UnloadTexture(background);
    CloseWindow();
    // srand(unsigned(time(NULL)));
    // Control c;
    // c.run();
}
bool ifPressed(Vector2 mousePos, bool mousePressed)
{
    DrawRectangleRec(rect, DARKGREEN);
    DrawRectangleLinesEx(rect, 3, DARKGRAY);
    int measuringTextWidth = MeasureText("new game", 22);
    DrawText("new game", rect.x + rect.width / 2 - measuringTextWidth / 2, rect.y + rect.height / 2 - 10, 22, WHITE);
    if (CheckCollisionPointRec(mousePos, rect) && mousePressed)
    {
        return true;
    }
    return false;
}
