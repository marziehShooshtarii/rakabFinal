#include <iostream>
#include "UI.hpp"

UI::UI()
{

    InitWindow(windowWidth, windowHeight, "game");
    std::cout << "88888777" << std::endl;
    fontMenu = LoadFont("../assets/KaushanScript-Regular.ttf");
    backgroundMenu = LoadTexture("../assets/b1.png");
    backgroundIdentityMenu = LoadTexture("../assets/b_6.png");
    // initializeFontMenu();
    // initializeBackgroundMenu();
    std::cout << "7777" << std::endl;
    // initializRec();
    initializeButtons();
    // initializePlayerNumberButton();
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
    // if (CheckCollisionPointRec(mousePssition, menuButtons[0].getRectangle()))
    //     menuButtons[0].setStatus(true);
    // else
    //     menuButtons[0].setStatus(false);
    // for (int i = 0; i < 4; i++)
    // {
        if (menuButtons[0].ifPressed(mousePssition, mousePressed))
        {
            std::cout << "new game" << std::endl;
            return "n"; // new game
        }
        if (menuButtons[1].ifPressed(mousePssition, mousePressed))
        {
            std::cout << "load" << std::endl;
            return "c"; // continue previous game
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
    // }

    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(backgroundMenu, 0, 0, WHITE);
    for (int i = 0; i < 4; i++)
    {
        Color selectedColor = WHITE;
        if (menuButtons[i].getStatus())
        {
            selectedColor = WHITE;
        }
        else
            selectedColor = RED;
        DrawTextEx(fontMenu, menuButtons[i].title, (Vector2){menuButtons[i].getRectangle().x + 10, menuButtons[i].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
    }
    // drawRectUI();
    EndDrawing();
    return "a";
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
    UnloadTexture(backgroundIdentityMenu);
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

int UI::displayPlayerNumberButton()
{
    initializePlayerNumberButton();
    Vector2 mousePssitionIdentity = GetMousePosition();
    bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    std::cout << mousePressedIdentity << std::endl;
    std::cout << "1111111111" << std::endl;
    // for (int i = 0; i < 4; i++)
    // {
        if (playerNumberButtons[1].ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            std::cout << "player 3" << std::endl;
            return 3; // number of players
        }
        if (playerNumberButtons[2].ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            std::cout << "player 4" << std::endl;
            return 4; // number of players
        }
    // }
    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);
    std::cout << "cout 1" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        DrawTextEx(fontMenu, playerNumberButtons[i].title, (Vector2){playerNumberButtons[i].getRectangle().x + 10, playerNumberButtons[i].getRectangle().y + 10}, fontMenu.baseSize, 1, RED);
        std::cout << "playerNumber" << std::endl;
    }
    EndDrawing();
    return -1; // anything execpt the player numbers
}

void UI::initializePlayerNumberButton()
{
    playerNumberButtons[0] = (Button){(Rectangle){50, 220, 120, 50}, "choose the player numbers:", false};
    playerNumberButtons[1] = (Button){(Rectangle){50, 290, 120, 50}, "3 players", false};
    playerNumberButtons[2] = (Button){(Rectangle){50, 360, 120, 50}, "4 players", false};
}

void UI::initializeIdentityMenu()
{
    backgroundIdentityMenu = LoadTexture("../assets/b_6.png");
}
