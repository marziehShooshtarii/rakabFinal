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

    while (1)
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
    }
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
    while (1)
    {
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
        for (int idx = 1; idx < 3; ++idx)
        {
            Color selectedColor = WHITE;
            if (CheckCollisionPointRec(mousePssitionIdentity, playerNumberButtons[idx].getRectangle()))
            {
                selectedColor = WHITE;
            }
            else
            {
                selectedColor = RED;
            }

            DrawTextEx(fontMenu, this->playerNumberButtons[idx].title, (Vector2){this->playerNumberButtons[idx].getRectangle().x + 10, this->playerNumberButtons[idx].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        }
        EndDrawing();
    }
    return -1; // anything execpt the player numbers
}

void UI::initializePlayerNumberButton()
{
    playerNumberButtons[0] = (Button){(Rectangle){50, 220, 120, 50}, "choose the player numbers:", false};
    playerNumberButtons[1] = (Button){(Rectangle){50, 290, 120, 50}, "3 players", false};
    playerNumberButtons[2] = (Button){(Rectangle){50, 360, 120, 50}, "4 players", false};
}

void UI::initializeConfirmPlayerDataButton(float x , float y , float width , float hight)
{
    // rectConfirmPlayerData = {500, 900, 200, 100};
    // ConfirmPlayerData = (Button){(Rectangle){950, 350, 180, 50}, "confirm", false};
    ConfirmPlayerData = (Button){(Rectangle){x, y, width, hight}, "confirm", false};
    // ConfirmPlayerData[1] = (Button){(Rectangle){600, 250, 120, 50}, "confirm", false};
    // ConfirmPlayerData[2] = (Button){(Rectangle){600, 350, 120, 50}, "confirm", false};
}
// bool UI::displayConfirmPlayerDataButton()
// {
//     initializeConfirmPlayerDataButton();
//     // while (1)
//     // {
//     Vector2 mousePssitionIdentity = GetMousePosition();
//     bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
//     std::cout << mousePressedIdentity << std::endl;

//     if (ConfirmPlayerData[0].ifPressed(mousePssitionIdentity, mousePressedIdentity))
//     {
//         return true;
//     }
//     if (ConfirmPlayerData[1].ifPressed(mousePssitionIdentity, mousePressedIdentity))
//     {
//         return true;
//     }
//     if (ConfirmPlayerData[2].ifPressed(mousePssitionIdentity, mousePressedIdentity))
//     {
//         return true;
//     }

//     // BeginDrawing();
//     // ClearBackground(WHITE);
//     // DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);

//     Color selectedColor = WHITE;
//     if (CheckCollisionPointRec(mousePssitionIdentity, ConfirmPlayerData[0].getRectangle()))
//     {
//         selectedColor = WHITE;
//     }
//     else
//     {
//         selectedColor = RED;
//     }

//     DrawTextEx(fontMenu, this->ConfirmPlayerData[0].title, (Vector2){this->ConfirmPlayerData[0].getRectangle().x + 10, this->ConfirmPlayerData[0].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
//     std::cout << "tah displayConfirmPlayerDataButton" << std::endl;
//     // EndDrawing();
//     // }
//     return false;
// }

void UI::initializeIdentityMenu()
{
    backgroundIdentityMenu = LoadTexture("../assets/b_6.png");
}
// void UI::inputNumberOfPlayers()
// {
//     bool mouseOnText
// }
/*bool UI::Textbox()
{
    uiInput input;
    int letterCount = 0;
    int framesCounter = 0;
    while (1)
    {
        input.initializeTextBoxRec();
        char playerName[50];
        for (int i = 0; i < 50; i++)
        {
            playerName[i] = input.getUIPlayerName(i);
        }
        bool mouseOnText = false;
        if (CheckCollisionPointRec(GetMousePosition(), input.getTextBoxRec()))
        {
            mouseOnText = true;
        }
        else
        {
            mouseOnText = false;
        }
        if (mouseOnText)
        {
            std::cout << "02222222222222" << std::endl;
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            std::cout << "get key pressed " << GetCharPressed() << std::endl;
            int key = GetCharPressed();
            int counter = 0;
            while (key > 0)
            {
                std::cout << "011111111111111111" << std::endl;
                counter++;
                std::cout << "033333333333" << std::endl;
                if ((key >= 32) && (key <= 125) && (letterCount < 50))
                {
                    std::cout << "0 " << (char)key << std::endl;
                    input.setUIPlayerName(letterCount, (char)key);
                    std::cout << "one " << (char)key << std::endl;
                    input.setUIPlayerName(letterCount + 1, '\0');
                    std::cout << "tow " << (char)key << std::endl;
                    letterCount++;
                    std::cout << letterCount << std::endl;
                }

                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0)
                    letterCount = 0;
                input.setUIPlayerName(letterCount, '\0');
            }
            if (IsKeyPressed(KEY_ENTER))
            {
                std::cout << "Enter key pressed" << input.getFullName() << std::endl;
                input.resetInput();
                letterCount = 0;
            }
            if (IsKeyPressed(KEY_ENTER))
            {
                ClearBackground(WHITE);
                return true;
            }
        }
        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText)
            framesCounter++;
        else
            framesCounter = 0;
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTextEx(fontMenu, "PLACE MOUSE OVER INPUT BOX!", (Vector2){240, 140}, fontMenu.baseSize, 1, RED);

        DrawRectangleRec(input.getTextBoxRec(), LIGHTGRAY);
        if (mouseOnText)
            // DrawRectangle((int)input.getTextBoxRec().x,(int)input.getTextBoxRec().y,(int)input.getTextBoxRec().width, (int)input.getTextBoxRec().height, RED);
            DrawRectangleLines((int)input.getTextBoxRec().x, (int)input.getTextBoxRec().y, (int)input.getTextBoxRec().width, (int)input.getTextBoxRec().height, RED);
        else
            DrawRectangleLines((int)input.getTextBoxRec().x, (int)input.getTextBoxRec().y, (int)input.getTextBoxRec().width, (int)input.getTextBoxRec().height, MAROON);
        // DrawTextEx(fontMenu, "", (Vector2){(float)input.getTextBoxRec().x + 5, (float)input.getTextBoxRec().y + 8}, fontMenu.baseSize, 1, RED);
        // DrawText(input.getFullName(), (int)input.getTextBoxRec().x + 5, (int)input.getTextBoxRec().y + 8, 40, MAROON);
        DrawTextEx(fontMenu, input.getFullName(), (Vector2){(float)input.getTextBoxRec().x + 5, (float)input.getTextBoxRec().y + 8}, fontMenu.baseSize, 1, DARKGRAY);
        DrawTextEx(fontMenu, TextFormat("player name: %i/%i", letterCount, 50), (Vector2){315, 250}, fontMenu.baseSize, 1, DARKGRAY);
        // DrawText(TextFormat("player name: %i/%i", letterCount, 50), 315, 250, 20, DARKGRAY);

        if (mouseOnText)
        {
            if (letterCount < 50)
            {
                // Draw blinking underscore char
                if (((framesCounter / 20) % 2) == 0)
                    DrawText("_", (int)input.getTextBoxRec().x + 8 + MeasureText(playerName, 40), (int)input.getTextBoxRec().y + 12, 40, WHITE);
            }
            else
                DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
        }

        EndDrawing();
    }
}*/
void UI::AddTextBox(float x, float y, float width, float height)
{
    textBoxes.emplace_back(x, y, width, height);
}
void UI::textBoxUpdate()
{
    Vector2 mousePoint = GetMousePosition();

    for (auto &textBox : textBoxes)
    {
        textBox.IsMouseOnText(mousePoint);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            textBox.SetActive(textBox.IsMouseOnText(mousePoint));
        }
        textBox.Update();
    }
}
void UI::textBoxDraw(Font font, int framesCounter)
{
    for (auto &textBox : textBoxes)
    {
        textBox.Draw(font, framesCounter);
    }
}

bool UI::thripleTextBoxDraw()
{
    AddTextBox(100, 100, 200, 50);
    AddTextBox(100, 200, 200, 50);
    AddTextBox(100, 300, 200, 50);//three text boxes for player names
    AddTextBox(500, 100, 100, 50);
    AddTextBox(500, 200, 100, 50);
    AddTextBox(500, 300, 100, 50);//three text boxs for player ages
    AddTextBox(770, 100, 165, 50);
    AddTextBox(770, 200, 165, 50);
    AddTextBox(770, 300, 165, 50);//three text boxs for player selected color
    int framesCounter = 0;
    initializeConfirmPlayerDataButton(950, 350, 180, 50);
    while (1)
    {
        framesCounter++;

        textBoxUpdate();
        Vector2 mousePssitionConfirmation = GetMousePosition();
        bool mousePressedConfirmation = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        // std::cout << mousePressedComfermation << std::endl;
// std::cout <<playerIndex << "playerIndex" << std::endl;
        if (ConfirmPlayerData.ifPressed(mousePssitionConfirmation, mousePressedConfirmation))
        {
            return true;
        }
        // if (ConfirmPlayerData[1].ifPressed(mousePssitionConfirmation, mousePressedConfirmation))
        // {
        //     return true;
        // }
        // if (ConfirmPlayerData[2].ifPressed(mousePssitionConfirmation, mousePressedConfirmation))
        // {
        //     return true;
        // }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);
        DrawTextEx(fontMenu, "please enter your names:", (Vector2){100, 50}, fontMenu.baseSize, 1, BLACK);
        DrawTextEx(fontMenu, "please enter your ages:", (Vector2){450, 50}, fontMenu.baseSize, 1, BLACK);
        DrawTextEx(fontMenu, "please enter your color:", (Vector2){750, 50}, fontMenu.baseSize, 1, BLACK);
        textBoxDraw(fontMenu, framesCounter);
        // for (int index = 0; index < 3; index++)
        // {
            Color selectedColor = WHITE;
            if (CheckCollisionPointRec(mousePssitionConfirmation, ConfirmPlayerData.getRectangle()))
            {
                selectedColor = WHITE;
            }
            else
            {
                selectedColor = RED;
            }
            DrawTextEx(fontMenu, this->ConfirmPlayerData.title, (Vector2){this->ConfirmPlayerData.getRectangle().x + 10, this->ConfirmPlayerData.getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        // }
        // DrawTextEx(fontMenu, this->ConfirmPlayerData[1].title, (Vector2){this->ConfirmPlayerData[1].getRectangle().x + 10, this->ConfirmPlayerData[1].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        // DrawTextEx(fontMenu, this->ConfirmPlayerData[2].title, (Vector2){this->ConfirmPlayerData[2].getRectangle().x + 10, this->ConfirmPlayerData[2].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        std::cout << "tah displayConfirmPlayerDataButton" << std::endl;
        EndDrawing();
    }
}
bool UI::quadrupleTextBoxDraw()
{
    AddTextBox(100, 100, 200, 50);
    AddTextBox(100, 200, 200, 50);
    AddTextBox(100, 300, 200, 50);
    AddTextBox(100, 400, 200, 50);//four text boxs for player's names
    AddTextBox(500, 100, 100, 50);
    AddTextBox(500, 200, 100, 50);
    AddTextBox(500, 300, 100, 50);
    AddTextBox(500, 400, 100, 50);//four text boxs for player's ages
    AddTextBox(760, 100, 200, 50);
    AddTextBox(760, 200, 200, 50);
    AddTextBox(760, 300, 200, 50);
    AddTextBox(760, 400, 200, 50);//four text boxs for player's selected colors

    int framesCounter = 0;
    initializeConfirmPlayerDataButton(950, 450, 180, 50);
    while (1)
    {
        framesCounter++;

        textBoxUpdate();
        Vector2 mousePssitionConfirmation = GetMousePosition();
        bool mousePressedConfirmation = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        // std::cout << mousePressedComfermation << std::endl;

        if (ConfirmPlayerData.ifPressed(mousePssitionConfirmation, mousePressedConfirmation))
        {
            return true;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);
        DrawTextEx(fontMenu, "please enter your names:", (Vector2){100, 50}, fontMenu.baseSize, 1, BLACK);
        DrawTextEx(fontMenu, "please enter your ages:", (Vector2){500, 50}, fontMenu.baseSize, 1, BLACK);
        DrawTextEx(fontMenu, "please enter your color:", (Vector2){800, 50}, fontMenu.baseSize, 1, BLACK);
        textBoxDraw(fontMenu, framesCounter);
        Color selectedColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionConfirmation, ConfirmPlayerData.getRectangle()))
        {
            selectedColor = WHITE;
        }
        else
        {
            selectedColor = RED;
        }

        DrawTextEx(fontMenu, this->ConfirmPlayerData.title, (Vector2){this->ConfirmPlayerData.getRectangle().x + 10, this->ConfirmPlayerData.getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        EndDrawing();
    }
}

// std::vector<char> UI::getNamesFromUI(int playerIndex)
// {
//     textBoxes[playerIndex].transferPlayerNameToVector();
//     std::cout << "textBoxes[playerIndex].getTextBoxName(). -> " << textBoxes[playerIndex].getTextBoxName().size() << std::endl;
//     return textBoxes[playerIndex].getTextBoxName();
// }

// char * UI::getFullNameFromUI(int index)
// {
//     return textBoxes[index].getFullName();
// }

// std::vector<char> UI::getAgeFromUI(int playerAgeIndex)
// {
//     textBoxes[playerAgeIndex].transferPlayerNameToVector();
//     return textBoxes[playerAgeIndex].getTextBoxName();
// }

void UI::controlTransitionVectors(int playerTextBoxIndex)
{
    textBoxes[playerTextBoxIndex].transferPlayerNameToVector();
}
std::string UI::getPlayerNameAndColorFromUI(int playerTextBoxIndex)
{
    textBoxes[playerTextBoxIndex].convertTextToString(); //char array has been converted to string in uiInput
    return textBoxes[playerTextBoxIndex].getTextBoxStringName();
}
int UI::getPlayerAgeFromUI(int playerAgeIndex)
{
    textBoxes[playerAgeIndex].convertAgeToInteger();//char array has been converted to integer in uiInput
    return textBoxes[playerAgeIndex].getTextBoxIntAge();
}
