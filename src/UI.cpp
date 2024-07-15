#include <iostream>
#include "UI.hpp"
// int windowWidth = 600;
// int windowHeight = 800;
// Rectangle rect{windowHeight / 2 - 100, windowHeight / 2 - 50, 200, 100};
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
UI::UI()
{

    InitWindow(windowWidth, windowHeight, "game");
    std::cout << "88888777" << std::endl;
    fontMenu = LoadFont("C:\rakabFinal\assets\KaushanScript-Regular.ttf");
    // initializeFontMenu();
    initializeBackgroundMenu();
    std::cout << "7777" << std::endl;
    //initializRec();
    initializeButtons();
    // menuGameLoop(fontMenu);
}
void UI::initializRec()
{
    rect = {(float)windowHeight / 2 - 100, (float)windowHeight / 2 - 50, 200, 100};
}
// bool UI::ifPressed(Vector2 mousePos, bool mousePressed)
// {
//     drawRectUI();
//     if (CheckCollisionPointRec(mousePos, rect) && mousePressed)
//     {
//         return true;
//     }
//     return false;
// }
void UI::drawRectUI()
{
    DrawRectangleRec(rect, DARKGREEN);
    DrawRectangleLinesEx(rect, 3, DARKGRAY);
    int measuringTextWidth = MeasureText("n", 22);
    DrawText("n", rect.x + rect.width / 2 - measuringTextWidth / 2, rect.y + rect.height / 2 - 10, 22, WHITE);
}
void UI::displayMenuBackground()
{
    std::cout << "111111111111111111" << std::endl;
    std::cout << "2222222222222222" << std::endl;
    std::cout << "33333333333333333" << std::endl;

    // Vector2 position;
}
void UI::menuGameLoop()
{

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        Vector2 mousePssition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        for (int j = 0; j < 4; j++)
        {
            if (menuButtons[j].ifPressed(mousePssition, mousePressed))
            {
                std::cout << "new game" << std::endl;
            }

        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(backgroundMenu, 0, 0, WHITE);
        for (int i = 0; i < 4; i++)
            DrawTextEx(fontMenu, menuButtons[i].title, (Vector2){menuButtons[i].getRectangle().x + 10, menuButtons[i].getRectangle().y + 10}, fontMenu.baseSize, 1, RED);
        // drawRectUI();
        UnloadFont(fontMenu);
        UnloadTexture(backgroundMenu);
        EndDrawing();
    }
}

UI::~UI()
{
    CloseWindow();
}
void UI::unloadingTexture()
{
    UnloadTexture(backgroundMenu);
}
// void UI::initializeFontMenu()
// {
//     // fontMenu = LoadFont("C:\rakabFinal\assets\KaushanScript-Regular.ttf");
//     std::cout << "inja" << std::endl;
// }
void UI::initializeBackgroundMenu()
{
    backgroundMenu = LoadTexture("D:\adavanced\rakab\rakabFinal\assets\tunel for menu.png");
}
void UI::initializeButtons()
{
    menuButtons[0] = (Button){(Rectangle){50, 150, 120, 50}, "new game", false};
    menuButtons[1] = (Button){(Rectangle){50, 220, 120, 50}, "load game", false};
    menuButtons[2] = (Button){(Rectangle){50, 290, 120, 50}, "help", false};
    menuButtons[3] = (Button){(Rectangle){50, 360, 120, 50}, "exit", false};
}