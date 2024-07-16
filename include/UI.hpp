#ifndef UI_HPP
#define UI_HPP
#include <string>
#include "raylib.h"
#include "Button.hpp"
// #define windowWidth = 600
// #define windowHeight = 800
//Font fontMenu = LoadFont("C:\rakabFinal\assets\KaushanScript-Regular.ttf");
class UI
{
public:
    UI();
    ~UI();
    void initializRec();
    //bool ifPressed(Vector2 mousePos, bool mousePressed);
    void drawRectUI();
    void displayMenuBackground();
    std::string menuGameLoop();
    void unloadingTexture();
    // void initializeFontMenu();
    void initializeBackgroundMenu();
    void initializeButtons();
    void displayIdentityMenu();
private:
    const char* menuButtonsTitle[4];
    int windowWidth = 600;
    int windowHeight = 800;
    Rectangle rect;
    Font fontMenu;//first menu font
    Texture2D backgroundMenu;//menu background
    Texture2D backgroundIdentityMenu;//identity menu background
    Button menuButtons[4];//buttons displayed in the menu
    // bool ifPressed(Vector2 mousePos, bool mousePressed);

    // std::cout << "test" << std::endl;
    //     InitWindow(windowWidth, windowHeight, "game");
    //     SetTargetFPS(60);
    //     Font font = LoadFont("../assets/KaushanScript-Regular.ttf");
    //     Texture2D background = LoadTexture("../assets/tunel for menu.png");
    //     Vector2 position;

    //     while (WindowShouldClose() == false)
    //     {
    //         Vector2 mousePssition = GetMousePosition();
    //         bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    //         if (ifPressed(mousePssition,mousePressed))
    //         {
    //             std::cout<<"new game"<<std::endl;
    //         }

    //         BeginDrawing();
    //         ClearBackground(WHITE);
    //         DrawTexture(background, 0, 0, WHITE);
    //         DrawTextEx(font,"button",(Vector2){rect.x+10,rect.y+10},font.baseSize,1,RED);

    //         EndDrawing();
    //     }
    //     UnloadTexture(background);
    //     CloseWindow();
    //     bool ifPressed(Vector2 mousePos, bool mousePressed)
    // {
    //     DrawRectangleRec(rect, DARKGREEN);
    //     DrawRectangleLinesEx(rect, 3, DARKGRAY);
    //     int measuringTextWidth = MeasureText("new game", 22);
    //     DrawText("new game", rect.x + rect.width / 2 - measuringTextWidth / 2, rect.y + rect.height / 2 - 10, 22, WHITE);
    //     if (CheckCollisionPointRec(mousePos, rect) && mousePressed)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
};
#endif