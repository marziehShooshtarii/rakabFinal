#include <iostream>
#include "UI.hpp"

UI::UI()
{

    InitWindow(windowWidth, windowHeight, "game");
    std::cout << "88888777" << std::endl;
    fontMenu = LoadFont("../assets/KaushanScript-Regular.ttf");
    backgroundMenu = LoadTexture("../assets/t.png");
    // initializeFontMenu();
    // initializeBackgroundMenu();
    std::cout << "7777" << std::endl;
    // initializRec();
    initializeButtons();
    // menuGameLoop();
    SetTargetFPS(60);
}
void UI::initializRec()
{
    rect = {(float)windowHeight / 2 - 100, (float)windowHeight / 2 - 50, 200, 100};
}

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
std::string UI::menuGameLoop()
{

    // while (WindowShouldClose() == false)
    // {
    Vector2 mousePssition = GetMousePosition();
    bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    // for (int j = 0; j < 4; j++)
    // {
    // if (menuButtons[j].ifPressed(mousePssition, mousePressed))
    // {
    //     std::cout << "new game" << std::endl;
    // }
    if (menuButtons[0].ifPressed(mousePssition, mousePressed))
    {
        std::cout << "new game" << std::endl;
        return "n";//new game
    }
    if (menuButtons[1].ifPressed(mousePssition, mousePressed))
    {
        std::cout << "load" << std::endl;
        return "c";//continue previous game
    }
    if (menuButtons[2].ifPressed(mousePssition, mousePressed))
    {
        std::cout << "help" << std::endl;
        return "help";
    }
    if (menuButtons[3].ifPressed(mousePssition, mousePressed))
    {
        std::cout << "exit" << std::endl;
        return "exit";
    }
    // }

    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(backgroundMenu, 0, 0, WHITE);
    for (int i = 0; i < 4; i++)
        DrawTextEx(fontMenu, menuButtons[i].title, (Vector2){menuButtons[i].getRectangle().x + 10, menuButtons[i].getRectangle().y + 10}, fontMenu.baseSize, 1, WHITE);
    // drawRectUI();
    EndDrawing();
    return "kooft";
    //}
}

UI::~UI()
{
    CloseWindow();
}
void UI::unloadingTexture()
{
    UnloadFont(fontMenu);
    UnloadTexture(backgroundMenu);
}

void UI::initializeBackgroundMenu()
{
    // backgroundMenu = LoadTexture("../assets/t.png");
}
void UI::initializeButtons()
{
    menuButtons[0] = (Button){(Rectangle){50, 150, 120, 50}, "new game", false};
    menuButtons[1] = (Button){(Rectangle){50, 220, 120, 50}, "load game", false};
    menuButtons[2] = (Button){(Rectangle){50, 290, 120, 50}, "help", false};
    menuButtons[3] = (Button){(Rectangle){50, 360, 120, 50}, "exit", false};
}

void UI::displayIdentityMenu()
{
    backgroundIdentityMenu = LoadTexture("../assets/t.png");
}
