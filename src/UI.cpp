#include <iostream>
#include "UI.hpp"

UI::UI()
{

    InitWindow(windowWidth, windowHeight, "game");
    std::cout << "88888777" << std::endl;
    fontMenu = LoadFont("../assets/KaushanScript-Regular.ttf");
    gameFont = LoadFont("../assets/Future-TimeSplitters.otf");
    inputFont = LoadFont("../assets/SF-Atarian-System-Bold-Italic.ttf");
    backgroundMenu = LoadTexture("../assets/blueMenu.png");
    backgroundIdentityMenu = LoadTexture("../assets/b_6.png");
    backgroundWarzoneMap = LoadTexture("../assets/warzone_map.png");
    charectersAndNames = LoadTexture("../assets/charactersIntro.png");
    luckNumberBackground = LoadTexture("../assets/luck.png");
    selectedWarzoneBackground = LoadTexture("../assets/selected_warzone2.png");
    gameTable = LoadTexture("../assets/dark_table.png");
    character1 = LoadTexture("../assets/gt1_2.png");
    character2 = LoadTexture("../assets/gt2_2.png");
    character3 = LoadTexture("../assets/gt3_2.png");
    character4 = LoadTexture("../assets/gt3.png");
    cards[0] = LoadTexture("../assets/bahar.png");
    cards[1] = LoadTexture("../assets/zemestan.png");
    cards[2] = LoadTexture("../assets/matarsak.png");
    cards[3] = LoadTexture("../assets/tabl_zan.png");
    cards[4] = LoadTexture("../assets/shah_dokht.png");
    cards[5] = LoadTexture("../assets/shirzan.png");
    cards[6] = LoadTexture("../assets/rish_sefid.png");
    cards[7] = LoadTexture("../assets/parcham_dar.png");
    cards[8] = LoadTexture("../assets/s1.png");
    cards[9] = LoadTexture("../assets/s2.png");
    cards[10] = LoadTexture("../assets/s3.png");
    cards[11] = LoadTexture("../assets/s4.png");
    cards[12] = LoadTexture("../assets/s5.png");
    cards[13] = LoadTexture("../assets/s6.png");
    cards[14] = LoadTexture("../assets/s10.png");

    renderTextureForGameTable[0] = LoadRenderTexture(character1.width, character1.height);
    renderTextureForGameTable[1] = LoadRenderTexture(character2.width, character1.height);
    renderTextureForGameTable[2] = LoadRenderTexture(character3.width, character1.height);

    renderTextureForGameTableAndCharacters = LoadRenderTexture(gameTable.width, gameTable.height);
    initializeCardTextureAndName();
    initializePlayerCardsHandler();
    initializePlayedCardsHandler();
    initializeCharacterNumber();
    initializePlayedCardsFromUI();
    initializePlayerCardsFromUI();
    initializePlayedStringCard();
    for (int i = 0; i < 3; i++)
        ifPlayerPassed[i] = false;
    // temp = LoadImage("../assets/gt1.png");          // Load image
    // ImageFlipVertical(&temp);                       // Flip image vertically
    // Texture2D texture = LoadTextureFromImage(temp); // Load texture from image
    // UnloadImage(temp);                              // Unload image from RAM
    //  foregroundWarzoneMap = LoadTexture("../assets/foreground_map.png");

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
    // UnloadTexture(foregroundWarzoneMap);
    UnloadTexture(charectersAndNames);
    UnloadTexture(selectedWarzoneBackground);
    UnloadTexture(gameTable);
    UnloadTexture(character1);
    UnloadTexture(character2);
    UnloadTexture(character3);
    UnloadTexture(character4);
    for (int i = 0; i < 15; i++)
    {
        UnloadTexture(cards[i]);
    }
    // UnloadRenderTexture(renderTextureForGameTable);
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
        // std::cout << mousePressedIdentity << std::endl;
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
    UIwarzone[0] = (Button){(Rectangle){820 + x, 115 + y, width, hight}, "bella", false};    // bella
    UIwarzone[1] = (Button){(Rectangle){832 + x, 260 + y, width, hight}, "calline", false};  // calline
    UIwarzone[2] = (Button){(Rectangle){768 + x, 360 + y, width, hight}, "enna", false};     // lia
    UIwarzone[3] = (Button){(Rectangle){824 + x, 510 + y, width, hight}, "atela", false};    // atela
    UIwarzone[4] = (Button){(Rectangle){654 + x, 467 + y, width, hight}, "dimase", false};   // dimase
    UIwarzone[5] = (Button){(Rectangle){541 + x, 474 + y, width, hight}, "olivadi", false};  // olivadi
    UIwarzone[6] = (Button){(Rectangle){443 + x, 572 + y, width, hight}, "lia", false};      // enna
    UIwarzone[7] = (Button){(Rectangle){428 + x, 420 + y, width, hight}, "armento", false};  // armento
    UIwarzone[8] = (Button){(Rectangle){489 + x, 237 + y, width, hight}, "morina", false};   // morina
    UIwarzone[9] = (Button){(Rectangle){293 + x, 175 + y, width, hight}, "talmone", false};  // talmone
    UIwarzone[10] = (Button){(Rectangle){150 + x, 135 + y, width, hight}, "elinia", false};  // elinia
    UIwarzone[11] = (Button){(Rectangle){370 + x, 84 + y, width, hight}, "rollo", false};    // rollo
    UIwarzone[12] = (Button){(Rectangle){619 + x, 108 + y, width, hight}, "pladaci", false}; // pladaci
    UIwarzone[13] = (Button){(Rectangle){651 + x, 298 + y, width, hight}, "borge", false};   // borge
    UIwarzone[14] = (Button){(Rectangle){719 + x, 550 + y, width, hight}, "alora", false};   // alora

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
// void UI::renderTextureForWarzoneMap()
// {
//     RenderTexture2D target = LoadRenderTexture(windowWidth, windowHeight);
//     BeginTextureMode(target);  // Start drawing to the render texture
//     ClearBackground(RAYWHITE); // Clear the render texture with white
// }
int UI::displayWarzoneButton(std::string starterPlayer)
{
    initializeWarzoneButton(50, 50, 120, 50);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        // std::cout << mousePressedIdentity << std::endl;
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
            // std::cout << "to for " << std::endl;
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
            // std::cout << "tah for " << std::endl;
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
void UI::initializePassButton(float x, float y, float width, float hight)
{
    passPosition = (Button){(Rectangle){x, y, width, hight}, "pass", false};
}
bool UI::displaySelectedWarzone(std::string UIWarzone)
{
    initializeNextButton(1100, 680, 120, 50);
    const char *selectedUIWarzone = UIWarzone.c_str();
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        // std::cout << mousePressedIdentity << std::endl;

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            std::cout << "too if " << std::endl;
            return true; // next button has been pressed
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(selectedWarzoneBackground, 0, 0, WHITE);
        DrawText("warzone : ", 80, 200, 40, BLACK);
        DrawText(selectedUIWarzone, 280, 200, 40, BLACK);
        DrawText("get ready for war!!!", 80, 235, 40, BLACK);
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
        return 1;
    }
    return false;
}
void UI::displaycharactersCards(int turnHandler)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // DrawTexture(character1, 0, 0, WHITE);
    DrawTextureRec(renderTextureForGameTable[turnHandler].texture, (Rectangle){0, 0, (float)renderTextureForGameTable[turnHandler].texture.width, (float)-renderTextureForGameTable[turnHandler].texture.height}, Vector2{0, 0}, WHITE);

    EndDrawing();
    std::clog << "end of display game table" << std::endl;
    return;
}

void UI::setIfPlayerPassed(bool checkPassed, int playerIndex)
{
    ifPlayerPassed[playerIndex] = checkPassed;
}
bool UI::getIfPlayerPassed(int playerIndex)
{
    return ifPlayerPassed[playerIndex];
}
bool UI::renderTextureForCharacterOnGameTable(int turnHandler)
{
    UITurnHandler = turnHandler;
    // std::cout << "renderTextureForCharacterOnGameTable 1" << std::endl;
    initializePassButton(1100, 680, 200, 100);
    initializeCardsButtons(0, 0, 120, 50);
    // std::cout << "renderTextureForCharacterOnGameTable 2" << std::endl;
    while (/*!isCardSelected*/ 1)
    {
        // std::cout << "renderTextureForCharacterOnGameTable 3" << std::endl;
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        // std::cout << "renderTextureForCharacterOnGameTable 4" << std::endl;
        // std::cout << mousePressedIdentity << std::endl;

        // std::clog << this->playerCardForUI.size() << std::endl;

        // if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        // {
        //     std::cout << "too if " << std::endl;
        //     return true; // next button has been pressed
        // }
        // BeginTextureMode(renderTextureForGameTable);
        for (int i = 0; i < 10; i++)
        {
            // std::cout << "renderTextureForCharacterOnGameTable 5" << std::endl;
            if (cardsButtons[i].ifPressed(mousePssitionIdentity, mousePressedIdentity))
            {
                // UnloadTexture(playerCardForUI[0]);
                // std::cout << "UITurnHandler--------------too render" << UITurnHandler << std::endl;
                playedCardsHandler.at(UITurnHandler).emplace_back(playerCardsHandler.at(UITurnHandler)[i]);
                std::cout << "UITurnHandler--------------too render 2 " << std::endl;
                playedCardsFromUI.at(UITurnHandler).emplace_back(playerCardsFromUI.at(UITurnHandler)[i]);
                // std::cout <<"16.6 -> " << playedCardsFromUI.at(UITurnHandler)[i];
                playerCardsHandler.at(UITurnHandler).erase(playerCardsHandler.at(UITurnHandler).begin() + i);
                // playerCardForUI.erase(playerCardForUI.begin() + i);
                // firstCharacterPlayedCards.push_back(playerCardsHandler.at(UITurnHandler)[i]);
                // isCardSelected = true;

                std::cout << "warzone selected - > " << i << std::endl;
                // std::cout << "playedCardForUI - >>>>>>>>>>>>>> renderTextureForCharacterOnGameTable" << playedCardsHandler.at(UITurnHandler).size() << std::endl;
                return 0;
            }
        }
        if (passPosition.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            setIfPlayerPassed(true, turnHandler);
            return true; // the player has passed the turn
        }
        // if (isCardSelected)
        //     return 0;
        // if (!getIfPlayerPassed(UITurnHandler))
        // {
        BeginDrawing();
        ClearBackground(BLANK);
        DrawTexture(characterNumber.at(UITurnHandler), 0, 0, WHITE);
        for (int i = 0; i < playerCardsHandler.at(UITurnHandler).size() / 2; i++)

            DrawTexture(playerCardsHandler.at(UITurnHandler)[i], (i * 100) + 400, 610, WHITE);

        for (int i = playerCardsHandler.at(UITurnHandler).size() / 2; i < playerCardsHandler.at(UITurnHandler).size(); i++)

            DrawTexture(playerCardsHandler.at(UITurnHandler)[i], ((i - playerCardsHandler.at(UITurnHandler).size() / 2) * 100) + 400, 460, WHITE);

        // EndTextureMode();
        for (int idx = 0; idx < playerCardsHandler.at(UITurnHandler).size(); ++idx)
        {
            // std::cout << "to for " << std::endl;
            Color selectedColor = WHITE;
            if (CheckCollisionPointRec(mousePssitionIdentity, cardsButtons[idx].getRectangle()))
            {
                selectedColor = WHITE;
            }
            else
            {
                selectedColor = RED;
            }

            DrawTextEx(fontMenu, this->cardsButtons[idx].title, (Vector2){this->cardsButtons[idx].getRectangle().x + 10, this->cardsButtons[idx].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
            // std::cout << "tah for " << std::endl;
        }
        Color passColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionIdentity, passPosition.getRectangle()))
        {
            passColor = WHITE;
        }
        else
        {
            passColor = RED;
        }

        DrawTextEx(fontMenu, this->passPosition.title, (Vector2){this->passPosition.getRectangle().x + 10, this->passPosition.getRectangle().y + 10}, fontMenu.baseSize, 1, passColor);
        EndDrawing();
        // }

        // Color selectedColor = WHITE;
        // if (CheckCollisionPointRec(mousePssitionIdentity, next.getRectangle()))
        // {
        //     selectedColor = WHITE;
        // }
        // else
        // {
        //     selectedColor = RED;
        // }
        // std::cout << "displayGameTableAndCharacters2 - > " << std::endl;

        // DrawTextEx(fontMenu, this->next.title, (Vector2){this->next.getRectangle().x + 10, this->next.getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);

        // return 1;
        getPlayedCardsFromUI();
    }
    return false;
}

void UI::initializeCardsButtons(float x, float y, float width, float hight)
{
    std::cout << "UITurnHandler too initialize " << UITurnHandler << std::endl;
    for (int i = 0; i < playerCardsHandler.at(UITurnHandler).size() / 2; i++)
        cardsButtons[i] = (Button){(Rectangle){(i * 100) + 400 + x, 610 + y, width, hight}, "test", false};
    for (int i = playerCardsHandler.at(UITurnHandler).size() / 2; i < playerCardsHandler.at(UITurnHandler).size(); i++)
        cardsButtons[i] = (Button){(Rectangle){((i - playerCardsHandler.at(UITurnHandler).size() / 2) * 100) + 400 + x, 460 + y, width, hight}, "test", false};
}
bool UI::displayCardsButtons()
{

    initializeCardsButtons(0, 0, 120, 50);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        // std::cout << mousePressedIdentity << std::endl;
        std::cout << "yek" << std::endl;
        for (int i = 0; i < 10; i++)
        {
            if (cardsButtons[i].ifPressed(mousePssitionIdentity, mousePressedIdentity))
            {
                std::cout << "warzone selected - > " << i << std::endl;
                return i;
            }
        }

        BeginDrawing();
        // for (int i = 0; i < playerCardForUI.size(); i++)
        //     DrawTexture(playerCardForUI[i], 0, 0, WHITE);
        // displayMap(starterPlayer);
        ClearBackground(RAYWHITE);

        for (int idx = 0; idx < playerCardsHandler.at(UITurnHandler).size(); ++idx)
        {
            // std::cout << "to for " << std::endl;
            Color selectedColor = WHITE;
            if (CheckCollisionPointRec(mousePssitionIdentity, UIwarzone[idx].getRectangle()))
            {
                selectedColor = WHITE;
            }
            else
            {
                selectedColor = RED;
            }

            DrawTextEx(fontMenu, this->cardsButtons[idx].title, (Vector2){this->cardsButtons[idx].getRectangle().x + 10, this->cardsButtons[idx].getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
            // std::cout << "tah for " << std::endl;
        }

        // EndTextureMode(); // Stop drawing to the render texture

        // Draw the render texture to the screen
        // DrawTextureRec(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2){ 0, 0 }, WHITE);
        EndDrawing();
    }
    return -1;

    return false;
}
bool UI::displayGameTableAndCharacters(int turnHandlerForDisplay)
{
    initializeNextButton(1100, 680, 120, 50);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            std::cout << "too if " << std::endl;
            return true; // next button has been pressed
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(gameTable, 0, 0, WHITE);

        // std::cout << "playedCardsHandler.at(k).size() - >........................displayGameTableAndCharacters" << playedCardsHandler.at(0).size() << std::endl;
        for (int q = 0; q < turnHandlerForDisplay / 4; q++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int j = 0; j < playedCardsHandler.at(k).size() / 3; j++)
                {
                    for (int i = 0; i < 3; i++)
                        DrawTexture(playedCardsHandler.at(k)[i], (k * 200) + (i * 65) + 5, (j * 100) + 290, WHITE);
                }
                for (int i = 0; i < playedCardsHandler.at(k).size() % 3; i++)
                    DrawTexture(playedCardsHandler.at(k)[i], (k * 200) + (i * 65) + 5, (playedCardsHandler.at(k).size() / 3 * 100) + 290, WHITE);
            }
        }
        for (int k = 0; k < turnHandlerForDisplay % 4; k++)
        {

            for (int j = 0; j < playedCardsHandler.at(k).size() / 3; j++)
            {
                for (int i = 0; i < 3; i++)
                    DrawTexture(playedCardsHandler.at(k)[i], (k * 200) + (i * 65) + 5, (j * 100) + 290, WHITE);
            }
            for (int i = 0; i < playedCardsHandler.at(k).size() % 3; i++)
                DrawTexture(playedCardsHandler.at(k)[i], (k * 200) + (i * 65) + 5, (playedCardsHandler.at(k).size() / 3 * 100) + 290, WHITE);
        }

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
void UI::getPlayedCardsFromUI()
{
    
    // for (int i=0 ; i < playedCardsFromUI.at(UITurnHandler).size(); i++) 
    // {
    //     std::cout << playedCardsFromUI.at(UITurnHandler)[i]<< "player aziz " << UITurnHandler << std::endl;
    // }
}
// std::string UI::findCard(Texture2D value)
// {

//         // std::cout << value << std::endl;
//         std::cout << "inja" << std::endl;
//         std::string_view key;
//         auto it = UIcardName.begin();
//         // auto it = std::find_if(states.begin(),states.end(),[&key](const auto& value){return value.first == key;});
//         std::cout << "inja2" << std::endl;
//         // std::cout << it->second << std::endl;
//         while (it != UIcardName.end())
//         {

//             std::cout << "inja3" << std::endl;
//             // std::cout << it->second << std::endl;
//             if (it->second == value)
//             {
//                 std::cout << "inja4" << std::endl;
//                 std::cout << "mohem - >>>>> " << it->first << std::endl;
//                 return it->first;
//             }
//             std::cout << "inja5" << std::endl;
//             // std::cout << value << std::endl;
//             it++;
//         }
//         std::cout << "inja6" << std::endl;

// }
void UI::renderTextureForCharacterAndGameTable()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // DrawTexture(character1, 0, 0, WHITE);
    DrawTextureRec(renderTextureForGameTableAndCharacters.texture, (Rectangle){0, 0, (float)renderTextureForGameTableAndCharacters.texture.width, (float)-renderTextureForGameTableAndCharacters.texture.height}, Vector2{0, 0}, WHITE);

    EndDrawing();
    std::clog << "end of display game table" << std::endl;
    return;
}
void UI::initializePlayerCardsHandler()
{
    playerCardsHandler =
        {
            {0, firstCharacterplayerCards},
            {1, secondCharacterplayerCards},
            {2, thirdCharacterplayerCards},
            {3, fourthCharacterplayerCards},
        };
}
void UI::initializePlayedCardsHandler()
{
    playedCardsHandler =
        {
            {0, firstCharacterPlayedCards},
            {1, secondCharacterPlayedCards},
            {2, thirdCharacterPlayedCards},
            {3, fourthCharacterPlayedCards},
        };
}
void UI::initializePlayedCardsFromUI()
{
    playedCardsFromUI =
        {
            {0, firstPlayedCardsFromUI},
            {1, secondPlayedCardsFromUI},
            {2, thirdPlayedCardsFromUI},
            {3, forthPlayedCardsFromUI},
        };
}
void UI::initializePlayerCardsFromUI()
{
    playerCardsFromUI =
        {
            {0, firstPlayerCardsFromUI},
            {1, secondPlayerCardsFromUI},
            {2, thirdPlayerCardsFromUI},
            {3, forthPlayerCardsFromUI},
        };
}
void UI::initializePlayedStringCard()
{
    // playedStringCard =
        // {
        //     {baharCards, "bahar"},
        //     {zemestanCards, "zemestan"},
        //     {matarsakCards, "matarsak"},
        //     {tablzanCards, "tabl_zan"},
        //     {shahDokhtCards, "shah_dokht"},
        //     {shirzanCards, "shirzan"},
        //     {rishSefidCards, "rish_sefid"},
        //     {parchamDarCards, "parcham_dar"},
        //     {sarbazOneCards, "sarbaz_1"},
        //     {sarbazTwoCards, "sarbaz_2"},
        //     {sarbazThreeCards, "sarbaz_3"},
        //     {sarbazFourCards, "sarbaz_4"},
        //     {sarbazFiveCards, "sarbaz_5"},
        //     {sarbazSixCards, "sarbaz_6"},
        //     {sarbazTenCards, "sarbaz_10"},
        // };
}
void UI::initializeCardTextureAndName()
{
    UIcardName =
        {
            {"bahar", cards[0]},
            {"zemestan", cards[1]},
            {"matarsak", cards[2]},
            {"tabl_zan", cards[3]},
            {"shah_dokht", cards[4]},
            {"shirzan", cards[5]},
            {"rish_sefid", cards[6]},
            {"parcham_dar", cards[7]},
            {"sarbaz_1", cards[8]},
            {"sarbaz_2", cards[9]},
            {"sarbaz_3", cards[10]},
            {"sarbaz_4", cards[11]},
            {"sarbaz_5", cards[12]},
            {"sarbaz_6", cards[13]},
            {"sarbaz_10", cards[14]},

        };
}
void UI::initializeCardTextureAndStrings()
{
    // UIStringName =
    //     {
    //         {cards[0] ,"bahar"},
    //         {cards[1] , "zemestan"},
    //         {cards[2] , "matarsak"},
    //         {cards[3] , "tabl_zan"},
    //         {cards[4] , "shah_dokht"},
    //         {cards[5] , "shirzan"},
    //         {cards[6] , "rish_sefid"},
    //         {cards[7] , "parcham_dar"},
    //         {cards[8] , "sarbaz_1"},
    //         {cards[9] , "sarbaz_2"},
    //         {cards[10] , "sarbaz_3"},
    //         {cards[11] , "sarbaz_4"},
    //         {cards[12] , "sarbaz_5"},
    //         {cards[13] , "sarbaz_6"},
    //         {cards[14] , "sarbaz_10"},

    //     };
}
void UI::findTexture(std::vector<Card> cardsForUI, int turnHandler)
{

    std::cout << "aval findTexture" << std::endl;
    std::cout << "cardsForUI.size " << cardsForUI.size() << std::endl;
    for (int i = 0; i < cardsForUI.size(); i++)
    {

        std::cout << "to for find" << std::endl;
        // std::cout << "cardsForUI[i].getName()" << cardsForUI[i].getName() << std::endl;
        std::cout << "playerCardForUI.size " << playerCardsHandler.at(turnHandler).size() << std::endl;

        playerCardsHandler.at(turnHandler).emplace_back(UIcardName.at(cardsForUI[i].getName()));
        playerCardsFromUI.at(turnHandler).emplace_back(cardsForUI[i].getName()); // player cards remain string for being used in played cards

        std::cout << "to for find2" << std::endl;
    }
    for (int i=0 ; i <playerCardsFromUI.at(turnHandler).size() ; i++)
    {
        std::cout << "cart jadid " << playerCardsFromUI.at(turnHandler)[i] << std::endl;
    }
    std::cout << "akhar findTexture" << std::endl;

    // return UIcardName.at(cardsForUI[cardIndex].getName());
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
        // std::cout << mousePressedIdentity << std::endl;

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
        DrawTexture(luckNumberBackground, 0, 0, WHITE);
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
