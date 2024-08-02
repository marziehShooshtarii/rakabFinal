#include <iostream>
#include "UI.hpp"

UI::UI()
{

    InitWindow(windowWidth, windowHeight, "game");
    std::cout << "88888777" << std::endl;
    fontMenu = LoadFont("../assets/KaushanScript-Regular.ttf");
    gameFont = LoadFont("../assets/Future-TimeSplitters.otf");
    inputFont = LoadFont("../assets/SF-Atarian-System-Bold-Italic.ttf");
    backgroundMenu = LoadTexture("../assets/b1.png");
    backgroundIdentityMenu = LoadTexture("../assets/b_6.png");
    backgroundWarzoneMap = LoadTexture("../assets/warzone_map.png");
    charectersAndNames = LoadTexture("../assets/c1.png");
    selectedWarzoneBackground = LoadTexture("../assets/selected_warzone2.png");
    gameTable = LoadTexture("../assets/game_background.png");
    character1  = LoadTexture("../assets/gt1.png");
    character2  = LoadTexture("../assets/gt2.png");
    character3  = LoadTexture("../assets/gt3.png");
    character4  = LoadTexture("../assets/gt4.png");
   // renderTextureForGameTable = LoadRenderTexture(gameTable.width,gameTable.height);
    

    // foregroundWarzoneMap = LoadTexture("../assets/foreground_map.png");

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
    UnloadFont(gameFont);
    UnloadFont(inputFont);

    UnloadTexture(backgroundMenu);
    UnloadTexture(backgroundIdentityMenu);
    UnloadTexture(backgroundWarzoneMap);
    //UnloadTexture(foregroundWarzoneMap);
    UnloadTexture(charectersAndNames);
    UnloadTexture(selectedWarzoneBackground);
    UnloadTexture(gameTable);
    UnloadTexture(character1);
    UnloadTexture(character2);
    UnloadTexture(character3);
    UnloadTexture(character4);
    //UnloadRenderTexture(renderTextureForGameTable);

    
}
// void UI::unloadTextBox()
// {
//     for (int i= 0 ; i < textBoxes.size(); i++)
//     {
        
//     }
// }
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
void UI::initializeWarzoneButton(float x, float y, float width, float hight)
{

    // UIwarzone[0] = (Button){(Rectangle){100 + x, y, width, hight}, "test2", false}; // talmone
    //  for (int i = 0; i < 4; i++)
    //      UIwarzone[i] = (Button){(Rectangle){(i * 200) + x, y, width, hight}, "test1", false}; // elinia, rollo, pladaci, bella
    UIwarzone[0] = (Button){(Rectangle){790 + x, 145 + y, width, hight}, "bella", false};    // bella
    UIwarzone[1] = (Button){(Rectangle){870 + x, 270 + y, width, hight}, "calline", false};  // calline
    UIwarzone[2] = (Button){(Rectangle){850 + x, 393 + y, width, hight}, "enna", false};     // enna
    UIwarzone[3] = (Button){(Rectangle){940 + x, 550 + y, width, hight}, "atela", false};    // atela
    UIwarzone[4] = (Button){(Rectangle){710 + x, 520 + y, width, hight}, "dimase", false};   // dimase
    UIwarzone[5] = (Button){(Rectangle){550 + x, 540 + y, width, hight}, "olivadi", false};  // olivadi
    UIwarzone[6] = (Button){(Rectangle){430 + x, 572 + y, width, hight}, "lia", false};      // lia
    UIwarzone[7] = (Button){(Rectangle){420 + x, 450 + y, width, hight}, "armento", false};  // armento
    UIwarzone[8] = (Button){(Rectangle){550 + x, 200 + y, width, hight}, "morina", false};   // morina
    UIwarzone[9] = (Button){(Rectangle){270 + x, 190 + y, width, hight}, "talmone", false};  // talmone
    UIwarzone[10] = (Button){(Rectangle){150 + x, 160 + y, width, hight}, "elinia", false};  // elinia
    UIwarzone[11] = (Button){(Rectangle){370 + x, 120 + y, width, hight}, "rollo", false};   // rollo
    UIwarzone[12] = (Button){(Rectangle){610 + x, 140 + y, width, hight}, "pladaci", false}; // pladaci
    UIwarzone[13] = (Button){(Rectangle){654 + x, 310 + y, width, hight}, "borge", false};   // borge
    UIwarzone[14] = (Button){(Rectangle){700 + x, 617 + y, width, hight}, "alora", false};   // alora

    // UIwarzone[10] = (Button){(Rectangle){850 + x, 550 + y, width, hight}, "test6", false}; // atela
    //  for (int i = 9; i < 11; i++)
    //      UIwarzone[i] = (Button){(Rectangle){((i - 9) * 100) + x, 400 + y, width, hight}, "test", false};
    //  for (int i = 10; i < 13; i++)
    //      UIwarzone[i] = (Button){(Rectangle){((i - 5) * 100) + x, 550 + y, width, hight}, "test7", false}; // olivadi, dimase, atela
    //  for (int i = 14; i < 15; i++)
    //      UIwarzone[i] = (Button){(Rectangle){((i - 14) * 100) + x, 400 + y, width, hight}, "test", false};
    // UIwarzone[15] = (Button){(Rectangle){600 + x, 500 + y, width, hight}, "test9", false};
    //  for (int i = 0; i < 15; i++)
    //      UIwarzone[i] = (Button){(Rectangle){(i * 100) + x, y, width, hight}, "test", false};
}
void UI::renderTextureForWarzoneMap()
{
    RenderTexture2D target = LoadRenderTexture(windowWidth, windowHeight);
    BeginTextureMode(target);  // Start drawing to the render texture
    ClearBackground(RAYWHITE); // Clear the render texture with white
}
int UI::displayWarzoneButton(std::string starterPlayer)
{
    initializeWarzoneButton(50, 50, 120, 50);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        std::cout << mousePressedIdentity << std::endl;
        std::cout << "yek" << std::endl;
        for (int i = 0; i < 15; i++)
        {
            if (UIwarzone[i].ifPressed(mousePssitionIdentity, mousePressedIdentity))
            {
                std::cout << "warzone selected - > " << i << std::endl;
                return i; // number of the selected warzone according to states in Map.cpp
            }
        }

        BeginDrawing();
        DrawTexture(backgroundWarzoneMap, 0, 0, WHITE);
        // displayMap(starterPlayer);
        ClearBackground(RAYWHITE);
        for (int idx = 0; idx < 15; ++idx)
        {
            std::cout << "to for " << std::endl;
            Color selectedColor = WHITE;
            if (CheckCollisionPointRec(mousePssitionIdentity, UIwarzone[idx].getRectangle()))
            {
                selectedColor = WHITE;
            }
            else
            {
                selectedColor = RED;
            }

            DrawTextEx(fontMenu, this->UIwarzone[idx].title, (Vector2){this->UIwarzone[idx].getRectangle().x + 10, this->UIwarzone[idx].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
            std::cout << "tah for " << std::endl;
        }

        // EndTextureMode(); // Stop drawing to the render texture

        // Draw the render texture to the screen
        // DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);
        EndDrawing();
    }
    return -1;
}
void UI::initializePlayerNumberButton()
{
    playerNumberButtons[0] = (Button){(Rectangle){50, 220, 120, 50}, "choose the player numbers:", false};
    playerNumberButtons[1] = (Button){(Rectangle){50, 290, 120, 50}, "3 players", false};
    playerNumberButtons[2] = (Button){(Rectangle){50, 360, 120, 50}, "4 players", false};
}

void UI::initializeConfirmPlayerDataButton(float x, float y, float width, float hight)
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
void UI::initializeWarzoneMap()
{
    backgroundWarzoneMap = LoadTexture("../assets/map2.png");
}
bool UI::displayMap(std::string str)
{

    const char *playerWhoChoosesWarzone = str.c_str();
    while (1)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // DrawTexture(backgroundWarzoneMap, 0, 0, WHITE);
        // DrawTextureRec(foregroundWarzoneMap, {0, 0, (float)foregroundWarzoneMap.width, (float)foregroundWarzoneMap.height}, {190, 150}, WHITE);
        DrawText("starter player: ", 100, 15, 40, WHITE);
        DrawText(playerWhoChoosesWarzone, 500, 15, 40, WHITE);
        DrawText("please choose the warzone from the map below", 100, 50, 40, WHITE);
        EndDrawing();
        return 1;
    }
}
void UI::initializeNextButton(float x, float y, float width, float hight)
{
    next = (Button){(Rectangle){x, y, width, hight}, "next", false};
}
bool UI::displaySelectedWarzone(std::string UIWarzone)
{
    const char *selectedUIWarzone = UIWarzone.c_str();
    while (1)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(selectedWarzoneBackground, 0, 0, WHITE);
        DrawText("warzone : ", 80, 200, 40, BLACK);
        DrawText(selectedUIWarzone, 280, 200, 40, BLACK);
        DrawText("get ready for war!!!", 80, 235, 40, BLACK);
        EndDrawing();
        return 1;
    }
    return false;
}
bool UI::displayGameTable()
{
    while (1)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(character1, 0, 0, WHITE);
        //DrawTexture(renderTextureForGameTable.texture, windowWidth/2 - renderTextureForGameTable.texture.width / 2, windowWidth / 2 - renderTextureForGameTable.texture.height / 2, WHITE);

        EndDrawing();
        return 1;
    }
    return false;
}

void UI::renderTextureForCharacterOnGame()
{
    BeginTextureMode(renderTextureForGameTable);
    ClearBackground(BLANK);
    DrawTexture(gameTable ,0 ,0,WHITE);
    DrawTexture(character1 ,0 ,0,WHITE);
    EndTextureMode();
    
}

void UI::initializeCharacterNumber()
{
    characterNumber =
        {
            {0, character1},
            {1, character2},
            {2, character3},
            {3, character4},

        };
}

bool UI::displayCharectersAndNames(std::string name1, std::string name2, std::string name3)
{
    initializeNextButton(1100, 680, 120, 50);
    const char *playerName1 = name1.c_str();
    const char *playerName2 = name2.c_str();
    const char *playerName3 = name3.c_str();

    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        std::cout << mousePressedIdentity << std::endl;

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            std::cout << "too if " << std::endl;
            return true; // next button has been pressed
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(charectersAndNames, 0, 0, WHITE);

        DrawText(playerName1, 200, 40, 40, WHITE);
        DrawText(playerName2, 600, 40, 40, WHITE);
        DrawText(playerName3, 980, 40, 40, WHITE);

        Color selectedColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionIdentity, next.getRectangle()))
        {
            selectedColor = WHITE;
        }
        else
        {
            selectedColor = RED;
        }

        DrawTextEx(fontMenu, this->next.title, (Vector2){this->next.getRectangle().x + 10, this->next.getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);

        EndDrawing();
    }
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
void UI::clearTextBox()
{
    textBoxes.clear();
}
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

bool UI::getLuckNumbers(std::string starterPlayer)
{
    clearTextBox();
    AddTextBox(180, 140, 100, 80);
    AddTextBox(500, 140, 100, 80);
    int framesCounter = 0;
    initializeConfirmPlayerDataButton(610, 200, 180, 50);
    const char *playerToStartWar = starterPlayer.c_str();
    while (1)
    {
        framesCounter++;
        textBoxUpdate();
        Vector2 mousePssitionConfirmation = GetMousePosition();
        bool mousePressedConfirmation = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if (ConfirmPlayerData.ifPressed(mousePssitionConfirmation, mousePressedConfirmation))
        {
            return true;
        }
        Color textColor = {249, 105, 14, 225}; // color Ecstasy created
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);
        // DrawText(playerToStartWar, 100, 50, 50, WHITE);
        // DrawText("you are the starter.", 100, 50, 50, WHITE);
        DrawTextEx(gameFont, playerToStartWar, (Vector2){100, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "you are the starter.", (Vector2){145, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter the good luck number:", (Vector2){100, 100}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter your bad luck number:", (Vector2){450, 100}, gameFont.baseSize, 1, textColor);
        // DrawTextEx(gameFont, "please enter your color:", (Vector2){750, 50}, gameFont.baseSize, 1, textColor);
        textBoxDraw(inputFont, framesCounter);
        // for (int index = 0; index < 3; index++)
        // {
        Color selectedColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionConfirmation, ConfirmPlayerData.getRectangle()))
        {
            selectedColor = WHITE;
        }
        else
        {
            selectedColor = /*RED*/ {242, 120, 75, 225}; // Crusta color created
        }
        DrawTextEx(gameFont, this->ConfirmPlayerData.title, (Vector2){this->ConfirmPlayerData.getRectangle().x + 10, this->ConfirmPlayerData.getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        // }
        // DrawTextEx(fontMenu, this->ConfirmPlayerData[1].title, (Vector2){this->ConfirmPlayerData[1].getRectangle().x + 10, this->ConfirmPlayerData[1].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        // DrawTextEx(fontMenu, this->ConfirmPlayerData[2].title, (Vector2){this->ConfirmPlayerData[2].getRectangle().x + 10, this->ConfirmPlayerData[2].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        // std::cout << "tah displayConfirmPlayerDataButton" << std::endl;
        EndDrawing();
    }
}
bool UI::thripleTextBoxDraw()
{
    AddTextBox(100, 100, 200, 50);
    AddTextBox(100, 200, 200, 50);
    AddTextBox(100, 300, 200, 50); // three text boxes for player names
    AddTextBox(500, 100, 100, 50);
    AddTextBox(500, 200, 100, 50);
    AddTextBox(500, 300, 100, 50); // three text boxs for player ages
    AddTextBox(770, 100, 165, 50);
    AddTextBox(770, 200, 165, 50);
    AddTextBox(770, 300, 165, 50); // three text boxs for player selected color
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
        Color textColor = {249, 105, 14, 225}; // color Ecstasy created
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);
        DrawTextEx(gameFont, "please enter your names:", (Vector2){100, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter your ages:", (Vector2){450, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter your color:", (Vector2){750, 50}, gameFont.baseSize, 1, textColor);
        textBoxDraw(inputFont, framesCounter);
        // for (int index = 0; index < 3; index++)
        // {
        Color selectedColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionConfirmation, ConfirmPlayerData.getRectangle()))
        {
            selectedColor = WHITE;
        }
        else
        {
            selectedColor = /*RED*/ {242, 120, 75, 225}; // Crusta color created
        }
        DrawTextEx(gameFont, this->ConfirmPlayerData.title, (Vector2){this->ConfirmPlayerData.getRectangle().x + 10, this->ConfirmPlayerData.getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        // }
        // DrawTextEx(fontMenu, this->ConfirmPlayerData[1].title, (Vector2){this->ConfirmPlayerData[1].getRectangle().x + 10, this->ConfirmPlayerData[1].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        // DrawTextEx(fontMenu, this->ConfirmPlayerData[2].title, (Vector2){this->ConfirmPlayerData[2].getRectangle().x + 10, this->ConfirmPlayerData[2].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        // std::cout << "tah displayConfirmPlayerDataButton" << std::endl;
        EndDrawing();
    }
}
bool UI::quadrupleTextBoxDraw()
{
    AddTextBox(100, 100, 200, 50);
    AddTextBox(100, 200, 200, 50);
    AddTextBox(100, 300, 200, 50);
    AddTextBox(100, 400, 200, 50); // four text boxs for player's names
    AddTextBox(500, 100, 100, 50);
    AddTextBox(500, 200, 100, 50);
    AddTextBox(500, 300, 100, 50);
    AddTextBox(500, 400, 100, 50); // four text boxs for player's ages
    AddTextBox(760, 100, 200, 50);
    AddTextBox(760, 200, 200, 50);
    AddTextBox(760, 300, 200, 50);
    AddTextBox(760, 400, 200, 50); // four text boxs for player's selected colors

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
        Color textColor = {249, 105, 14, 225}; // color Ecstasy created
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);
        DrawTextEx(gameFont, "please enter your names:", (Vector2){100, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter your ages:", (Vector2){470, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter your color:", (Vector2){800, 50}, gameFont.baseSize, 1, textColor);
        textBoxDraw(inputFont, framesCounter);
        Color selectedColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionConfirmation, ConfirmPlayerData.getRectangle()))
        {
            selectedColor = WHITE;
        }
        else
        {
            selectedColor = {242, 120, 75, 225}; // Crusta color created
        }

        DrawTextEx(gameFont, this->ConfirmPlayerData.title, (Vector2){this->ConfirmPlayerData.getRectangle().x + 10, this->ConfirmPlayerData.getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
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
    textBoxes[playerTextBoxIndex].convertTextToString(); // char array has been converted to string in uiInput
    return textBoxes[playerTextBoxIndex].getTextBoxStringName();
}
int UI::getPlayerAgeAndLuckFromUI(int playerAgeIndex)
{
    textBoxes[playerAgeIndex].convertNumberToInteger(); // char array has been converted to integer in uiInput
    return textBoxes[playerAgeIndex].getTextBoxIntNumber();
}
