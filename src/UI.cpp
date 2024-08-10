#include <iostream>
#include "UI.hpp"

UI::UI()
{

    InitWindow(windowWidth, windowHeight, "game");

    fontMenu = LoadFont("../assets/KaushanScript-Regular.ttf");
    gameFont = LoadFont("../assets/Future-TimeSplitters.otf");
    inputFont = LoadFont("../assets/SF-Atarian-System-Bold-Italic.ttf");
    backgroundMenu = LoadTexture("../assets/blueMenu.png");
    backgroundIdentityMenu = LoadTexture("../assets/b_6.png");
    backgroundWarzoneMap = LoadTexture("../assets/warzone_map.png");
    warzoneMapWithSigns = LoadTexture("../assets/warzone_map2.png");

    charectersAndNames[0] = LoadTexture("../assets/charactersIntroForThree.png");
    charectersAndNames[1] = LoadTexture("../assets/charactersIntro4.png");

    luckNumberBackground = LoadTexture("../assets/luck2.png");
    selectedWarzoneBackground = LoadTexture("../assets/selected_warzone2.png");
    gameTableForThreePlayers = LoadTexture("../assets/dark_table.png");
    gameTableForFourPlayers = LoadTexture("../assets/dark_table_for_four.png");

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
    cards[8] = LoadTexture("../assets/fak_sefid.png");
    cards[9] = LoadTexture("../assets/rakhsh_sefid.png");
    cards[10] = LoadTexture("../assets/s1.png");
    cards[11] = LoadTexture("../assets/s2.png");
    cards[12] = LoadTexture("../assets/s3.png");
    cards[13] = LoadTexture("../assets/s4.png");
    cards[14] = LoadTexture("../assets/s5.png");
    cards[15] = LoadTexture("../assets/s6.png");
    cards[16] = LoadTexture("../assets/s10.png");

    warSigns[0] = LoadTexture("../assets/warSign1-2-Photoroom.png");
    warSigns[1] = LoadTexture("../assets/warSign2_2-Photoroom.png");
    warSigns[2] = LoadTexture("../assets/warSign3_2-Photoroom.png");
    warSigns[3] = LoadTexture("../assets/warSign4_2-Photoroom.png");

    peaceSignForUI = LoadTexture("../assets/peaceSign2_2-Photoroom.png");
    peaceSignBackground = LoadTexture("../assets/peaceSignMap.png");

    winnerBackgroundForEachWar[0] = LoadTexture("../assets/winner2.png");
    winnerBackgroundForEachWar[1] = LoadTexture("../assets/winner3.png");
    winnerBackgroundForEachWar[2] = LoadTexture("../assets/winner1.png");
    winnerBackgroundForEachWar[3] = LoadTexture("../assets/winner4.png");
    winnerBackgroundForEndOfGame[0] = LoadTexture("../assets/finalWinner1.png");
    winnerBackgroundForEndOfGame[1] = LoadTexture("../assets/finalWinner2.png");
    winnerBackgroundForEndOfGame[2] = LoadTexture("../assets/finalWinner3.png");
    winnerBackgroundForEndOfGame[3] = LoadTexture("../assets/finalWinner4.png");

    noWinner = LoadTexture("../assets/noWinner.png");

    matarsakAndCharacters[0] = LoadTexture("../assets/matarsak1.png");
    matarsakAndCharacters[1] = LoadTexture("../assets/matarsak2.png");
    matarsakAndCharacters[2] = LoadTexture("../assets/matarsak3.png");
    matarsakAndCharacters[3] = LoadTexture("../assets/matarsak4.png");

    // helpForEachCard = LoadTexture("../assets/helpForCards.png");
    // helpGeneral = LoadTexture("../assets/helpGeneral.png");

    renderTextureForGameTable[0] = LoadRenderTexture(character1.width, character1.height);
    renderTextureForGameTable[1] = LoadRenderTexture(character2.width, character2.height);
    renderTextureForGameTable[2] = LoadRenderTexture(character3.width, character3.height);

    renderTextureMatarsakCharacters[0] = LoadRenderTexture(matarsakAndCharacters[0].width, matarsakAndCharacters[0].height);
    renderTextureMatarsakCharacters[1] = LoadRenderTexture(matarsakAndCharacters[1].width, matarsakAndCharacters[1].height);
    renderTextureMatarsakCharacters[2] = LoadRenderTexture(matarsakAndCharacters[2].width, matarsakAndCharacters[2].height);
    renderTextureMatarsakCharacters[3] = LoadRenderTexture(matarsakAndCharacters[3].width, matarsakAndCharacters[3].height);

    renderTextureForGameTableAndCharacters = LoadRenderTexture(gameTableForThreePlayers.width, gameTableForThreePlayers.height);
    renderTextureForGameTableAndCharactersForFour = LoadRenderTexture(gameTableForFourPlayers.width, gameTableForFourPlayers.height);

    renderTextureForWarSigns = LoadRenderTexture(warzoneMapWithSigns.width, warzoneMapWithSigns.height);
    initializeCardTextureAndName();
    initializePlayerCardsHandler();
    initializePlayedCardsHandler();
    initializeCharacterNumber();
    initializePlayedCardsFromUI();
    initializePlayerCardsFromUI();
    initializeStatesCoordinates();
    initializeWarSignColors();
    initializeButtons();

    SetTargetFPS(60);
}
void UI::initializRec()
{
    rect = {(float)windowHeight / 2 - 100, (float)windowHeight / 2 - 50, 200, 100};
}

std::string UI::menuGameLoop()
{
    while (1)
    {
        Vector2 mousePssition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (menuButtons[0].ifPressed(mousePssition, mousePressed))
        {
            return "n"; // new game
        }
        if (menuButtons[1].ifPressed(mousePssition, mousePressed))
        {
            return "c"; // continue previous game
        }
        if (menuButtons[2].ifPressed(mousePssition, mousePressed))
        {
            return "help";
        }
        if (menuButtons[3].ifPressed(mousePssition, mousePressed))
        {
            return "exit";
        }
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

        EndDrawing();
    }
    return "a"; // to avoid warning
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
    for (int i = 0; i < 2; i++)
        UnloadTexture(charectersAndNames[i]);
    UnloadTexture(luckNumberBackground);
    UnloadTexture(selectedWarzoneBackground);
    UnloadTexture(gameTableForThreePlayers);
    UnloadTexture(gameTableForFourPlayers);
    UnloadTexture(character1);
    UnloadTexture(character2);
    UnloadTexture(character3);
    UnloadTexture(character4);
    for (int i = 0; i < 15; i++)
    {
        UnloadTexture(cards[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        UnloadTexture(winnerBackgroundForEachWar[i]);
        UnloadTexture(winnerBackgroundForEndOfGame[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        UnloadRenderTexture(renderTextureForGameTable[i]);
    }
    UnloadRenderTexture(renderTextureForGameTableAndCharacters);
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

        if (playerNumberButtons[1].ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            setNumberOfPlayers(3);
            return 3; // number of players
        }
        if (playerNumberButtons[2].ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            setNumberOfPlayers(4);
            return 4; // number of players
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);

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
    UIwarzone[0] = (Button){(Rectangle){820 + x, 115 + y, width, hight}, "", false};  // bella
    UIwarzone[1] = (Button){(Rectangle){832 + x, 260 + y, width, hight}, "", false};  // calline
    UIwarzone[2] = (Button){(Rectangle){768 + x, 360 + y, width, hight}, "", false};  // lia
    UIwarzone[3] = (Button){(Rectangle){824 + x, 510 + y, width, hight}, "", false};  // atela
    UIwarzone[4] = (Button){(Rectangle){654 + x, 467 + y, width, hight}, "", false};  // dimase
    UIwarzone[5] = (Button){(Rectangle){541 + x, 474 + y, width, hight}, "", false};  // olivadi
    UIwarzone[6] = (Button){(Rectangle){443 + x, 572 + y, width, hight}, "", false};  // enna
    UIwarzone[7] = (Button){(Rectangle){428 + x, 420 + y, width, hight}, "", false};  // armento
    UIwarzone[8] = (Button){(Rectangle){489 + x, 237 + y, width, hight}, "", false};  // morina
    UIwarzone[9] = (Button){(Rectangle){293 + x, 175 + y, width, hight}, "", false};  // talmone
    UIwarzone[10] = (Button){(Rectangle){150 + x, 135 + y, width, hight}, "", false}; // elinia
    UIwarzone[11] = (Button){(Rectangle){370 + x, 84 + y, width, hight}, "", false};  // rollo
    UIwarzone[12] = (Button){(Rectangle){619 + x, 108 + y, width, hight}, "", false}; // pladaci
    UIwarzone[13] = (Button){(Rectangle){651 + x, 298 + y, width, hight}, "", false}; // borge
    UIwarzone[14] = (Button){(Rectangle){719 + x, 550 + y, width, hight}, "", false}; // alora
}

int UI::displayWarzoneButton(std::string starterPlayer)
{
    initializeWarzoneButton(50, 50, 120, 50);
    const char *starterPlayerInUI = starterPlayer.c_str();
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        for (int i = 0; i < 15; i++)
        {
            if (UIwarzone[i].ifPressed(mousePssitionIdentity, mousePressedIdentity))
            {

                return i; // number of the selected warzone according to states in Map.cpp
            }
        }

        BeginDrawing();
        DrawTexture(backgroundWarzoneMap, 0, 0, WHITE);

        ClearBackground(RAYWHITE);
        for (int idx = 0; idx < 15; ++idx)
        {
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
        }
        DrawTextPro(gameFont, starterPlayerInUI, (Vector2){40, 40}, (Vector2){1}, 1, 40, 1, {50, 180, 220, 255});
        DrawTextPro(gameFont, "choose the selected warzon", (Vector2){80, 40}, (Vector2){1}, 1, 40, 1, {50, 180, 220, 255});

        EndDrawing();
    }
    return -1;
}
int UI::displayWarzoneForPeacsignButtons(std::string lastPlayerPlayedRishSefid)
{
    initializeWarzoneButton(50, 50, 120, 50);
    const char *lastPlayerPlayedRishSefidInUI = lastPlayerPlayedRishSefid.c_str();
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        for (int i = 0; i < 15; i++)
        {
            if (UIwarzone[i].ifPressed(mousePssitionIdentity, mousePressedIdentity))
            {

                return i; // number of the selected warzone according to states in Map.cpp
            }
        }

        BeginDrawing();
        DrawTexture(peaceSignBackground, 0, 0, WHITE);
        ClearBackground(RAYWHITE);
        for (int idx = 0; idx < 15; ++idx)
        {
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
        }
        DrawTextPro(gameFont, lastPlayerPlayedRishSefidInUI, (Vector2){40, 40}, (Vector2){1}, 1, 40, 1, {50, 180, 220, 255});
        DrawTextPro(gameFont, "choose the state you want to put your peace sign on:", (Vector2){80, 40}, (Vector2){1}, 1, 40, 1, {50, 180, 220, 255});

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
    ConfirmPlayerData = (Button){(Rectangle){x, y, width, hight}, "confirm", false};
}

void UI::initializeIdentityMenu()
{
    backgroundIdentityMenu = LoadTexture("../assets/b_6.png");
}
void UI::initializeWarzoneMap()
{
    backgroundWarzoneMap = LoadTexture("../assets/map2.png");
}
void UI::displayRenderWarSigns()
{

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTextureRec(renderTextureForWarSigns.texture, (Rectangle){0, 0, (float)renderTextureForWarSigns.texture.width, (float)-renderTextureForWarSigns.texture.height}, Vector2{0, 0}, WHITE);
    EndDrawing();
    return;
}

bool UI::displayMap(std::string str)
{
    const char *playerWhoChoosesWarzone = str.c_str();
    while (1)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
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
void UI::initializeHelpButton(float x, float y, float width, float hight)
{
    help = (Button){(Rectangle){x, y, width, hight}, "help", false};
}
void UI::initializeSaveGameButton(float x, float y, float width, float hight)
{
    saveGame = (Button){(Rectangle){x, y, width, hight}, "save", false};
}
void UI::initializeExitGameButton(float x, float y, float width, float hight)
{
    exitGame = (Button){(Rectangle){x, y, width, hight}, "Exit", false};
}
bool UI::displaySelectedWarzone(std::string UIWarzone)
{
    initializeNextButton(40, 680, 120, 50);
    const char *selectedUIWarzone = UIWarzone.c_str();
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            std::cout << "too if " << std::endl;
            next.setStatus(false);
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
    DrawTextureRec(renderTextureForGameTable[turnHandler].texture, (Rectangle){0, 0, (float)renderTextureForGameTable[turnHandler].texture.width, (float)-renderTextureForGameTable[turnHandler].texture.height}, Vector2{0, 0}, WHITE);
    EndDrawing();

    return;
}
void UI::displaycharactersCardsForMatarsak(int turnHandler)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTextureRec(renderTextureMatarsakCharacters[turnHandler].texture, (Rectangle){0, 0, (float)renderTextureMatarsakCharacters[turnHandler].texture.width, (float)-renderTextureMatarsakCharacters[turnHandler].texture.height}, Vector2{0, 0}, WHITE);

    EndDrawing();

    return;
}

bool UI::renderTextureForCharacterOnGameTable(int starterPlayer)
{
    UIstarterPlayer = starterPlayer;

    initializePassButton(1100, 680, 200, 100);
    initializeCardsButtons(0, 0, 120, 50);

    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        for (int i = 0; i < 10; i++)
        {

            if (cardsButtons[i].ifPressed(mousePssitionIdentity, mousePressedIdentity))
            {
                playedCardsHandler.at(UIstarterPlayer).emplace_back(playerCardsHandler.at(UIstarterPlayer)[i]);

                playedCardsFromUI.at(UIstarterPlayer).emplace_back(playerCardsFromUI.at(UIstarterPlayer)[i]);
                playerCardsHandler.at(UIstarterPlayer).erase(playerCardsHandler.at(UIstarterPlayer).begin() + i);
                playerCardsFromUI.at(UIstarterPlayer).erase(playerCardsFromUI.at(UIstarterPlayer).begin() + i);
                return false;
            }
        }
        if (passPosition.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            return true; // the player has passed the turn
        }
        BeginDrawing();
        ClearBackground(BLANK);
        DrawTexture(characterNumber.at(UIstarterPlayer), 0, 0, WHITE);
        for (int i = 0; i < playerCardsHandler.at(UIstarterPlayer).size() / 2; i++)

            DrawTexture(playerCardsHandler.at(UIstarterPlayer)[i], (i * 100) + 400, 610, WHITE);

        for (int i = playerCardsHandler.at(UIstarterPlayer).size() / 2; i < playerCardsHandler.at(UIstarterPlayer).size(); i++)

            DrawTexture(playerCardsHandler.at(UIstarterPlayer)[i], ((i - playerCardsHandler.at(UIstarterPlayer).size() / 2) * 100) + 400, 460, WHITE);

        for (int idx = 0; idx < playerCardsHandler.at(UIstarterPlayer).size(); ++idx)
        {
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
    }
    return false;
}
bool UI::validCardsForMatarsak()
{

    initializeCardsButtonsForMatarsak(0, 0, 120, 50);
    initializeNextButton(1100, 680, 120, 50);
    while (1)
    {

        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return 1; // next button has been pressed
        }

        for (int i = 0; i < (playedCardsHandler.at(UIstarterPlayer).size() - numberOfInvalidCardsForMatarsak()); i++)
        {

            if (cardsButtons[i].ifPressed(mousePssitionIdentity, mousePressedIdentity))
            {

                playerCardsFromUI.at(UIstarterPlayer).emplace_back(playedCardsFromUI.at(UIstarterPlayer)[i]);
                playerCardsHandler.at(UIstarterPlayer).emplace_back(playedCardsHandler.at(UIstarterPlayer)[i]);
                playedCardsFromUI.at(UIstarterPlayer).erase(playedCardsFromUI.at(UIstarterPlayer).begin() + i);
                playedCardsHandler.at(UIstarterPlayer).erase(playedCardsHandler.at(UIstarterPlayer).begin() + i);

                return true;
            }
        }

        BeginDrawing();
        ClearBackground(BLANK);
        DrawTexture(matarsakAndCharacters[UIstarterPlayer], 0, 0, WHITE);

        for (int i = 0; i < playedCardsHandler.at(UIstarterPlayer).size() / 2; i++)
        {

            if (validateCardsForMatarsakInUI(i))
                DrawTexture(playedCardsHandler.at(UIstarterPlayer)[i], (i * 100) + 400, 610, WHITE);
        }

        for (int i = playedCardsHandler.at(UIstarterPlayer).size() / 2; i < playedCardsHandler.at(UIstarterPlayer).size(); i++)
        {

            if (validateCardsForMatarsakInUI(i))
                DrawTexture(playedCardsHandler.at(UIstarterPlayer)[i], ((i - playedCardsHandler.at(UIstarterPlayer).size() / 2) * 100) + 400, 460, WHITE);
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

        for (int idx = 0; idx < (playedCardsHandler.at(UIstarterPlayer).size() - numberOfInvalidCardsForMatarsak()); ++idx)
        {

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
        }

        EndDrawing();
    }
    return false;
}
bool UI::validateCardsForMatarsakInUI(int cardIndex)
{
    if (playedCardsFromUI.at(UIstarterPlayer)[cardIndex] == "bahar" || playedCardsFromUI.at(UIstarterPlayer)[cardIndex] == "zemestan" || playedCardsFromUI.at(UIstarterPlayer)[cardIndex] == "rish_sefid" || playedCardsFromUI.at(UIstarterPlayer)[cardIndex] == "parcham_dar" || playedCardsFromUI.at(UIstarterPlayer)[cardIndex] == "tabl_zan" || playedCardsFromUI.at(UIstarterPlayer)[cardIndex] == "shirzan" || playedCardsFromUI.at(UIstarterPlayer)[cardIndex] == "shah_dokht")
        return false;

    return true;
}
int UI::numberOfInvalidCardsForMatarsak()
{
    int counterInvalidCards = 0;
    for (int i = 0; i < playedCardsFromUI.at(UIstarterPlayer).size(); i++)
    {
        if (playedCardsFromUI.at(UIstarterPlayer)[i] == "bahar" || playedCardsFromUI.at(UIstarterPlayer)[i] == "zemestan" || playedCardsFromUI.at(UIstarterPlayer)[i] == "rish_sefid" || playedCardsFromUI.at(UIstarterPlayer)[i] == "parcham_dar" || playedCardsFromUI.at(UIstarterPlayer)[i] == "tabl_zan" || playedCardsFromUI.at(UIstarterPlayer)[i] == "shirzan" || playedCardsFromUI.at(UIstarterPlayer)[i] == "shah_dokht" || playedCardsFromUI.at(UIstarterPlayer)[i] == "matarsak")
            counterInvalidCards++;
    }
    return counterInvalidCards;
}

void UI::eraseAllCardsAfterWar()
{
    for (int i = 0; i < 4; i++)
    {
        playedCardsHandler.at(i).clear();
        playedCardsFromUI.at(i).clear();
    }
}

void UI::initializeCardsButtons(float x, float y, float width, float hight)
{

    for (int i = 0; i < playerCardsHandler.at(UIstarterPlayer).size() / 2; i++)
        cardsButtons[i] = (Button){(Rectangle){(i * 100) + 400 + x, 610 + y, width, hight}, "", false};

    for (int i = playerCardsHandler.at(UIstarterPlayer).size() / 2; i < 10; i++)
        cardsButtons[i] = (Button){(Rectangle){((i - playerCardsHandler.at(UIstarterPlayer).size() / 2) * 100) + 400 + x, 460 + y, width, hight}, "", false};
}
void UI::initializeCardsButtonsForMatarsak(float x, float y, float width, float hight)
{

    for (int i = 0; i < playedCardsHandler.at(UIstarterPlayer).size() / 2; i++)
        cardsButtons[i] = (Button){(Rectangle){(i * 100) + 400 + x, 610 + y, width, hight}, "", false};
    for (int i = playedCardsHandler.at(UIstarterPlayer).size() / 2; i < playedCardsHandler.at(UIstarterPlayer).size(); i++)
        cardsButtons[i] = (Button){(Rectangle){((i - playedCardsHandler.at(UIstarterPlayer).size() / 2) * 100) + 400 + x, 460 + y, width, hight}, "", false};
}
bool UI::displayCardsButtons()
{

    initializeCardsButtons(0, 0, 120, 50);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        for (int i = 0; i < 10; i++)
        {
            if (cardsButtons[i].ifPressed(mousePssitionIdentity, mousePressedIdentity))
            {

                return i;
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int idx = 0; idx < playerCardsHandler.at(UIstarterPlayer).size(); ++idx)
        {
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
        }

        EndDrawing();
    }
    return -1;

    return false;
}
int UI::displayGameTableAndCharactersForThree(int turnHandlerForDisplay, int TurnControler)
{
    initializeNextButton(1100, 680, 120, 50);
    initializeExitGameButton(10, 10, 120, 50);
    initializeHelpButton(150, 10, 120, 50);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return 1; // next button has been pressed
        }
        if (exitGame.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            return 0; // exit button has been pressed
        }
        if (help.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            return 2; // help button has been pressed
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(gameTableForThreePlayers, 0, 0, WHITE);

        for (int q = 0; q < turnHandlerForDisplay / 3; q++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int j = 0; j < playedCardsHandler.at(k).size() / 3; j++)
                {
                    for (int i = (j * 3); i < (j * 3) + 3; i++)
                        DrawTexture(playedCardsHandler.at(k)[i], (k * 400) + (i * 65) + 50, (j * 100) + 290, WHITE);
                }
                for (int i = playedCardsHandler.at(k).size() - (playedCardsHandler.at(k).size() % 3); i < playedCardsHandler.at(k).size(); i++)
                    DrawTexture(playedCardsHandler.at(k)[i], (k * 400) + ((i - playedCardsHandler.at(k).size() + playedCardsHandler.at(k).size() % 3) * 65) + 50, (playedCardsHandler.at(k).size() / 3 * 100) + 290, WHITE);
            }
        }

        if (turnHandlerForDisplay / 3 < 1)
        {

            for (int k = 0; k < (((turnHandlerForDisplay - 1) % 3 + TurnControler) % 4) + 1; k++)
            {

                for (int j = 0; j < playedCardsHandler.at(k).size() / 3; j++)
                {
                    for (int i = 0; i < 3; i++)
                        DrawTexture(playedCardsHandler.at(k)[i], (k * 400) + (i * 65) + 50, (j * 100) + 290, WHITE);
                }

                for (int i = playedCardsHandler.at(k).size() - (playedCardsHandler.at(k).size() % 3); i < playedCardsHandler.at(k).size() % 3; i++)
                    DrawTexture(playedCardsHandler.at(k)[i], (k * 400) + (i * 65) + 50, (playedCardsHandler.at(k).size() / 3 * 100) + 290, WHITE);
            }
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

        Color exitColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionIdentity, exitGame.getRectangle()))
        {
            exitColor = WHITE;
        }
        else
        {
            exitColor = RED;
        }

        DrawTextEx(fontMenu, this->exitGame.title, (Vector2){this->exitGame.getRectangle().x + 10, this->exitGame.getRectangle().y + 10}, fontMenu.baseSize, 1, exitColor);

        Color helpColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionIdentity, help.getRectangle()))
        {
            helpColor = WHITE;
        }
        else
        {
            helpColor = RED;
        }

        DrawTextEx(fontMenu, this->help.title, (Vector2){this->help.getRectangle().x + 10, this->help.getRectangle().y + 10}, fontMenu.baseSize, 1, helpColor);

        EndDrawing();
    }
}
int UI::displayGameTableAndCharactersForFour(int turnHandlerForDisplay, int TurnControler)
{
    initializeNextButton(1100, 680, 120, 50);
    initializeExitGameButton(10, 10, 120, 50);
    initializeHelpButton(150, 10, 120, 50);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return 1; // next button has been pressed
        }
        if (exitGame.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            return 0; // exit button has been pressed
        }
        if (help.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            return 2; // help button has been pressed
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(gameTableForFourPlayers, 0, 0, WHITE);

        if (turnHandlerForDisplay / 4 >= 1)
        {
            for (int q = 0; q < turnHandlerForDisplay / 4; q++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (k == 3)
                    {
                        continue;
                    }

                    for (int j = 0; j < playedCardsHandler.at(k).size() / 3; j++)
                    {
                        for (int i = (j * 3); i < (j * 3) + 3; i++)
                            DrawTexture(playedCardsHandler.at(k)[i], (k * 400) + (i * 65) + 65, (j * 70) + 250, WHITE);
                    }
                    for (int i = playedCardsHandler.at(k).size() - (playedCardsHandler.at(k).size() % 3); i < playedCardsHandler.at(k).size(); i++)
                        DrawTexture(playedCardsHandler.at(k)[i], (k * 400) + ((i - playedCardsHandler.at(k).size() + (playedCardsHandler.at(k).size() % 3)) * 65) + 65, (playedCardsHandler.at(k).size() / 3 * 70) + 250, WHITE);
                }
            }

            for (int j = 0; j < playedCardsHandler.at(3).size() / 3; j++)
            {
                for (int i = (j * 3); i < (j * 3) + 3; i++)
                    DrawTexture(playedCardsHandler.at(3)[i], (i * 65) + 65, (j * 70) + 500, WHITE);
            }
            for (int i = playedCardsHandler.at(3).size() - (playedCardsHandler.at(3).size() % 3); i < playedCardsHandler.at(3).size(); i++)
                DrawTexture(playedCardsHandler.at(3)[i], ((i - playedCardsHandler.at(3).size() + (playedCardsHandler.at(3).size() % 3)) * 65) + 65, (playedCardsHandler.at(3).size() / 3 * 70) + 500, WHITE);
        }

        else
        {
            for (int k = 0; k < (((turnHandlerForDisplay - 1) % 4 + TurnControler) % 4) + 1; k++)
            {
                if (k == 3)
                {
                    continue;
                }

                for (int j = 0; j < playedCardsHandler.at(k).size() / 3; j++)
                {

                    for (int i = 0; i < 3; i++)
                        DrawTexture(playedCardsHandler.at(k)[i], (k * 400) + (i * 65) + 65, (j * 70) + 250, WHITE);
                }

                for (int i = playedCardsHandler.at(k).size() - (playedCardsHandler.at(k).size() % 3); i < playedCardsHandler.at(k).size() % 3 /*% 3*/; i++)
                    DrawTexture(playedCardsHandler.at(k)[i], (k * 400) + (i * 65) + 65, (playedCardsHandler.at(k).size() / 3 * 70) + 250, WHITE);
            }
            for (int j = 0; j < playedCardsHandler.at(3).size() / 3; j++)
            {
                for (int i = (j * 3); i < (j * 3) + 3; i++)
                    DrawTexture(playedCardsHandler.at(3)[i], (i * 65) + 65, (j * 70) + 500, WHITE);
            }
            for (int i = playedCardsHandler.at(3).size() - (playedCardsHandler.at(3).size() % 3); i < playedCardsHandler.at(3).size() % 3; i++)
                DrawTexture(playedCardsHandler.at(3)[i], 1200 + (i * 65) + 65, (playedCardsHandler.at(3).size() / 3 * 70) + 500, WHITE);
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

        Color exitColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionIdentity, exitGame.getRectangle()))
        {
            exitColor = WHITE;
        }
        else
        {
            exitColor = RED;
        }

        DrawTextEx(fontMenu, this->exitGame.title, (Vector2){this->exitGame.getRectangle().x + 10, this->exitGame.getRectangle().y + 10}, fontMenu.baseSize, 1, exitColor);

        EndDrawing();
    }
}
std::vector<std::string> UI::getPlayedCardsFromUI()
{
    return playedCardsFromUI.at(UIstarterPlayer);
}
int UI::ExitGameControl()
{
    initializeSaveGameButton(200, 100, 120, 50);
    initializeExitGameButton(200, 200, 120, 50);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if (saveGame.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return 1; // save button has been pressed
        }
        if (exitGame.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return 2; // exit button has been pressed
        }
        BeginDrawing();
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);
        Color exitColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionIdentity, exitGame.getRectangle()))
        {
            exitColor = WHITE;
        }
        else
        {
            exitColor = RED;
        }

        DrawTextPro(fontMenu, this->exitGame.title, (Vector2){this->exitGame.getRectangle().x + 10, this->exitGame.getRectangle().y + 10}, (Vector2){1}, 1, 100, 1, exitColor);

        Color saveColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionIdentity, saveGame.getRectangle()))
        {
            saveColor = WHITE;
        }
        else
        {
            saveColor = RED;
        }

        DrawTextPro(fontMenu, this->saveGame.title, (Vector2){this->saveGame.getRectangle().x + 10, this->saveGame.getRectangle().y + 10}, (Vector2){1}, 1, 100, 1, saveColor);

        EndDrawing();
    }
}

void UI::renderTextureForCharacterAndGameTable()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTextureRec(renderTextureForGameTableAndCharacters.texture, (Rectangle){0, 0, (float)renderTextureForGameTableAndCharacters.texture.width, (float)-renderTextureForGameTableAndCharacters.texture.height}, Vector2{0, 0}, WHITE);

    EndDrawing();

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
            {"fok_sefid", cards[8]},
            {"rakhsh_sefid", cards[9]},
            {"sarbaz_1", cards[10]},
            {"sarbaz_2", cards[11]},
            {"sarbaz_3", cards[12]},
            {"sarbaz_4", cards[13]},
            {"sarbaz_5", cards[14]},
            {"sarbaz_6", cards[15]},
            {"sarbaz_10", cards[16]},

        };
}

void UI::findTexture(std::vector<Card> cardsForUI, int starterPlayer)
{

    for (int i = 0; i < cardsForUI.size(); i++)
    {

        playerCardsHandler.at(starterPlayer).emplace_back(UIcardName.at(cardsForUI[i].getName()));
        playerCardsFromUI.at(starterPlayer).emplace_back(cardsForUI[i].getName()); // player cards remain string for being used in played cards
    }
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

bool UI::displayCharectersAndNamesForThree(std::string name1, std::string name2, std::string name3)
{
    initializeNextButton(1100, 680, 120, 50);
    const char *playerName1 = name1.c_str();
    const char *playerName2 = name2.c_str();
    const char *playerName3 = name3.c_str();

    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return true; // next button has been pressed
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(charectersAndNames[0], 0, 0, WHITE);
        DrawTextPro(gameFont, playerName1, (Vector2){200, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});
        DrawTextPro(gameFont, playerName2, (Vector2){600, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});
        DrawTextPro(gameFont, playerName3, (Vector2){980, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});

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
bool UI::displayCharectersAndNamesForFour(std::string name1, std::string name2, std::string name3, std::string name4)
{
    initializeNextButton(1100, 680, 120, 50);
    const char *playerName1 = name1.c_str();
    const char *playerName2 = name2.c_str();
    const char *playerName3 = name3.c_str();
    const char *playerName4 = name4.c_str();

    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return true; // next button has been pressed
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(charectersAndNames[1], 0, 0, WHITE);

        DrawTextPro(gameFont, playerName1, (Vector2){150, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});
        DrawTextPro(gameFont, playerName2, (Vector2){450, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});
        DrawTextPro(gameFont, playerName3, (Vector2){750, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});
        DrawTextPro(gameFont, playerName4, (Vector2){1050, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});

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
bool UI::displayNoWinner()
{
    initializeNextButton(1100, 680, 120, 50);

    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return true; // next button has been pressed
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(noWinner, 0, 0, WHITE);

        DrawTextPro(gameFont, "there is no winner in this war!!!", (Vector2){200, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});

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
bool UI::displayWinner(int winnerPlayer, std::string winnerName)
{
    initializeNextButton(250, 680, 120, 50);
    const char *winnerPlayerName = winnerName.c_str();

    firstCharacterPlayedCards.clear();
    secondCharacterPlayedCards.clear();
    thirdCharacterPlayedCards.clear();
    firstPlayedCardsFromUI.clear();
    secondPlayedCardsFromUI.clear();
    thirdCharacterPlayedCards.clear();

    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return true; // next button has been pressed
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(winnerBackgroundForEachWar[winnerPlayer], 0, 0, WHITE);

        DrawTextPro(gameFont, winnerPlayerName, (Vector2){350, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});
        DrawTextPro(gameFont, "is the winner.", (Vector2){420, 40}, (Vector2){1}, 1, 40, 1, {50, 190, 220, 225});
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
bool UI::displayFinalWinner(int winnerPlayer, std::string winnerName)
{
    initializeNextButton(250, 680, 120, 50);
    const char *winnerPlayerName = winnerName.c_str();

    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {

            next.setStatus(false);
            return true; // next button has been pressed
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(winnerBackgroundForEndOfGame[winnerPlayer], 0, 0, WHITE);

        DrawText(winnerPlayerName, 200, 40, 40, WHITE);

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
        DrawTextEx(gameFont, playerToStartWar, (Vector2){100, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "you are the starter.", (Vector2){145, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter the good luck number:", (Vector2){100, 100}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter your bad luck number:", (Vector2){450, 100}, gameFont.baseSize, 1, textColor);

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
bool UI::thripleTextBoxDraw()
{
    AddTextBox(100, 100, 200, 50);
    AddTextBox(100, 200, 200, 50);
    AddTextBox(100, 300, 200, 50); // three text boxes for player names
    AddTextBox(500, 100, 100, 50);
    AddTextBox(500, 200, 100, 50);
    AddTextBox(500, 300, 100, 50); // three text boxs for player ages
    int framesCounter = 0;
    initializeConfirmPlayerDataButton(950, 350, 180, 50);
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
        DrawTextEx(gameFont, "please enter your names:", (Vector2){100, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter your ages:", (Vector2){450, 50}, gameFont.baseSize, 1, textColor);
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

    int framesCounter = 0;
    initializeConfirmPlayerDataButton(950, 450, 180, 50);
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
        DrawTextEx(gameFont, "please enter your names:", (Vector2){100, 50}, gameFont.baseSize, 1, textColor);
        DrawTextEx(gameFont, "please enter your ages:", (Vector2){470, 50}, gameFont.baseSize, 1, textColor);
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

void UI::initializeOptionsForSavedGameNumber()
{
    options[0] = {"saved Game 1"};
    options[1] = {"saved Game 2"};
    options[2] = {"saved Game 3"};
    options[3] = {"saved Game 4"};
    options[4] = {"saved Game 5"};
    selectedOption = "select a saved game";
    isDropdownOpen = false;
}
void UI::initializeOptionsAndDropdownBoundsForSavedGameNumber()
{
    dropdownBounds = {350, 250, 350, 30};
    optionBounds[0] = {420, 250 + 30, 200, 50};
    optionBounds[1] = {420, 250 + 80, 200, 50};
    optionBounds[2] = {420, 250 + 130, 200, 50};
    optionBounds[3] = {420, 250 + 180, 200, 50};
    optionBounds[4] = {420, 250 + 230, 200, 50};
}
void UI::initializeOptionsColors()
{
    colorOptions[0] = {"red"};
    colorOptions[1] = {"purple"};
    colorOptions[2] = {"blue"};
    colorOptions[3] = {"green"};
    selectedOptionForColors = "select a color";
    isDropdownOpenForColor = false;
}
void UI::initializeOptionsAndDropdownBoundsForColors()
{
    dropdownBoundsForColors = {350, 250, 350, 30};
    colorOptionBounds[0] = {420, 250 + 30, 200, 50};
    colorOptionBounds[1] = {420, 250 + 80, 200, 50};
    colorOptionBounds[2] = {420, 250 + 130, 200, 50};
    colorOptionBounds[3] = {420, 250 + 180, 200, 50};
}
void UI::initializeDropDownMenuForColors()
{
    initializeOptionsColors();
    initializeOptionsAndDropdownBoundsForColors();
}
std::string UI::displayOpenDropDownMenuForColors(std::string playerName)
{
    initializeDropDownMenuForColors();
    while (1)
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, dropdownBoundsForColors))
            {
                isDropdownOpenForColor = !isDropdownOpenForColor;
            }
            else if (isDropdownOpenForColor)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (CheckCollisionPointRec(mousePos, colorOptionBounds[i]))
                    {
                        selectedOptionForColors = colorOptions[i];
                        isDropdownOpenForColor = false;
                        return selectedOptionForColors;
                    }
                }
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);

        DrawRectangleRec(dropdownBoundsForColors, LIGHTGRAY);
        DrawRectangleLinesEx(dropdownBoundsForColors, 2, DARKGRAY);
        DrawTextPro(inputFont, selectedOptionForColors.c_str(), (Vector2){dropdownBoundsForColors.x + 37, dropdownBoundsForColors.y - 11}, (Vector2){1}, 1, 40, 1, {225, 120, 80, 225});
        DrawTextPro(gameFont, playerName.c_str(), (Vector2){300, 100}, (Vector2){1}, 1, 50, 1, {80, 200, 220, 225});
        DrawTextPro(gameFont, "choose the color: ", (Vector2){380, 100}, (Vector2){1}, 1, 50, 1, {80, 200, 220, 225});

        if (isDropdownOpenForColor)
        {
            for (int i = 0; i < 4; i++)
            {
                DrawRectangleRec(colorOptionBounds[i], LIGHTGRAY);

                DrawRectangleLinesEx(colorOptionBounds[i], 1, DARKGRAY);
                DrawTextPro(inputFont, colorOptions[i].c_str(), (Vector2){colorOptionBounds[i].x + 10, colorOptionBounds[i].y + 5}, (Vector2){1}, 1, 40, 1, {225, 110, 80, 225});
            }
        }

        EndDrawing();
    }
}
void UI::initializeDropDownMenuForSavedGameNumber()
{
    initializeOptionsForSavedGameNumber();
    initializeOptionsAndDropdownBoundsForSavedGameNumber();
}
int UI::displayOpenDropDownMenuForSavedGameNumber()
{
    initializeDropDownMenuForSavedGameNumber();
    while (1)
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, dropdownBounds))
            {
                isDropdownOpen = !isDropdownOpen;
            }
            else if (isDropdownOpen)
            {

                for (int i = 0; i < 5; i++)
                {
                    if (CheckCollisionPointRec(mousePos, optionBounds[i]))
                    {
                        selectedOption = options[i];
                        isDropdownOpen = false;
                        savedGameNumber = i;
                        return savedGameNumber;
                    }
                }
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);
        DrawRectangleRec(dropdownBounds, LIGHTGRAY);
        DrawRectangleLinesEx(dropdownBounds, 2, DARKGRAY);
        DrawTextPro(inputFont, selectedOption.c_str(), (Vector2){dropdownBounds.x + 37, dropdownBounds.y - 11}, (Vector2){1}, 1, 40, 1, {225, 120, 80, 225});

        if (isDropdownOpen)
        {
            for (int i = 0; i < 5; i++)
            {
                DrawRectangleRec(optionBounds[i], LIGHTGRAY);
                DrawRectangleLinesEx(optionBounds[i], 1, DARKGRAY);
                DrawTextPro(inputFont, options[i].c_str(), (Vector2){optionBounds[i].x + 10, optionBounds[i].y + 5}, (Vector2){1}, 1, 40, 1, {225, 110, 80, 225});
            }
        }

        EndDrawing();
    }
}
void UI::initializeHelpOptions()
{
    helpOptions[0] = {"bahar"};
    helpOptions[1] = {"zemestan"};
    helpOptions[2] = {"tabl_zan"};
    helpOptions[3] = {"shah_dokht"};
    helpOptions[4] = {"matarsak"};
    helpOptions[5] = {"fok_sefid"};
    helpOptions[6] = {"raksh_sefid"};
    helpOptions[7] = {"parcham_dar"};
    helpOptions[8] = {"rish_sefid"};
    helpOptions[9] = {"shirzan"};
    selectedHelpOption = "select a card";
    isDropdownOpenForHelp = false;
}
void UI::initializeHelpDropdownBounds()
{
    dropdownHelpBounds = {350, 250, 350, 30};
    helpOptionBounds[0] = {420, 250 + 30, 200, 50};
    helpOptionBounds[1] = {420, 250 + 80, 200, 50};
    helpOptionBounds[2] = {420, 250 + 130, 200, 50};
    helpOptionBounds[3] = {420, 250 + 180, 200, 50};
    helpOptionBounds[4] = {420, 250 + 230, 200, 50};
    helpOptionBounds[5] = {420, 250 + 280, 200, 50};
    helpOptionBounds[6] = {420, 250 + 330, 200, 50};
    helpOptionBounds[7] = {420, 250 + 380, 200, 50};
    helpOptionBounds[8] = {420, 250 + 430, 200, 50};
    helpOptionBounds[9] = {420, 250 + 480, 200, 50};
}
void UI::initializeHelpOptionsAndDropdownBounds()
{
    initializeHelpOptions();
    initializeHelpDropdownBounds();
}
std::string UI::helpGameControl()
{
    initializeHelpOptionsAndDropdownBounds();
    while (1)
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, dropdownHelpBounds))
            {
                isDropdownOpenForHelp = !isDropdownOpenForHelp;
            }
            else if (isDropdownOpenForHelp)
            {

                for (int i = 0; i < 10; i++)
                {
                    if (CheckCollisionPointRec(mousePos, helpOptionBounds[i]))
                    {

                        selectedHelpOption = helpOptions[i];
                        isDropdownOpenForHelp = false;
                        return selectedHelpOption;
                    }
                }
            }
        }

        BeginDrawing();
        DrawTexture(backgroundMenu, 0, 0, WHITE);

        DrawRectangleRec(dropdownHelpBounds, LIGHTGRAY);
        DrawRectangleLinesEx(dropdownHelpBounds, 2, DARKGRAY);
        DrawTextPro(inputFont, selectedHelpOption.c_str(), (Vector2){dropdownHelpBounds.x + 37, dropdownHelpBounds.y - 11}, (Vector2){1}, 1, 40, 1, {225, 120, 80, 225});

        if (isDropdownOpenForHelp)
        {
            for (int i = 0; i < 10; i++)
            {
                DrawRectangleRec(helpOptionBounds[i], LIGHTGRAY);
                DrawRectangleLinesEx(helpOptionBounds[i], 1, DARKGRAY);
                DrawTextPro(inputFont, helpOptions[i].c_str(), (Vector2){helpOptionBounds[i].x + 37, helpOptionBounds[i].y - 11}, (Vector2){1}, 1, 40, 1, {225, 120, 80, 225});
            }
        }

        EndDrawing();
    }
}

bool UI::displayHelp(std::string SpecialChoosedHelp)
{
    initializeNextButton(1100, 680, 120, 50);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            next.setStatus(false);
            return true; // next button has been pressed
        }
        BeginDrawing();
        DrawTexture(backgroundIdentityMenu, 0, 0, WHITE);
        DrawTextEx(gameFont, SpecialChoosedHelp.c_str(), (Vector2){200, 400}, gameFont.baseSize, 1, BLACK);
        Color selectedColor = WHITE;
        if (CheckCollisionPointRec(mousePssitionIdentity, next.getRectangle()))
        {
            selectedColor = WHITE;
        }
        else
        {
            selectedColor = {242, 120, 75, 225}; // Crusta color created
        }

        DrawTextEx(gameFont, this->next.title, (Vector2){this->next.getRectangle().x + 10, this->next.getRectangle().y + 10}, fontMenu.baseSize, 1, selectedColor);
        EndDrawing();
    }
}
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

bool UI::displayWarSigns(std::vector<int> numberOfstates, std::vector<std::string> nameOfstates, std::vector<int> winners, int numberOfwinnersInUI, std::vector<std::string> colors, std::string UIPeaceSign)
{

    initializeNextButton(1100, 680, 200, 100);
    while (1)
    {
        Vector2 mousePssitionIdentity = GetMousePosition();
        bool mousePressedIdentity = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (next.ifPressed(mousePssitionIdentity, mousePressedIdentity))
        {
            return true; // the player has passed the turn
        }
        BeginDrawing();
        ClearBackground(BLANK);
        DrawTexture(warzoneMapWithSigns, 0, 0, WHITE);
        for (statesCoordinatesItr = statesCoordinates.begin(); statesCoordinatesItr != statesCoordinates.end(); statesCoordinatesItr++)
        {

            if (statesCoordinatesItr->first == UIPeaceSign)
            {

                statesCoordinatesPtr = statesCoordinatesItr->second.begin();

                DrawTexture(peaceSignForUI, statesCoordinatesPtr->first, statesCoordinatesPtr->second, WHITE);
            }
        }
        for (int i = 0; i < winners.size(); i++)
        {

            if (i == 0)
            {
                for (int j = 0; j < 1; j++)
                {
                    for (statesCoordinatesItr = statesCoordinates.begin(); statesCoordinatesItr != statesCoordinates.end(); statesCoordinatesItr++)
                    {

                        if (statesCoordinatesItr->first == nameOfstates[j])
                        {

                            statesCoordinatesPtr = statesCoordinatesItr->second.begin();

                            DrawTexture(warSignColors.at(colors[winners[i]]), statesCoordinatesPtr->first, statesCoordinatesPtr->second, WHITE);
                        }
                    }
                }
            }
            else if (i > 0)
            {

                for (int j = i; j < (i + 1); j++)
                {

                    for (statesCoordinatesItr = statesCoordinates.begin(); statesCoordinatesItr != statesCoordinates.end(); statesCoordinatesItr++)
                    {

                        if (statesCoordinatesItr->first == nameOfstates[j])
                        {

                            statesCoordinatesPtr = statesCoordinatesItr->second.begin();

                            DrawTexture(warSignColors.at(colors[winners[i]]), statesCoordinatesPtr->first, statesCoordinatesPtr->second, WHITE);
                        }
                    }
                }
            }
        }

        Color color = WHITE;
        if (CheckCollisionPointRec(mousePssitionIdentity, next.getRectangle()))
        {
            color = WHITE;
        }
        else
        {
            color = RED;
        }

        DrawTextEx(fontMenu, this->next.title, (Vector2){this->next.getRectangle().x + 10, this->next.getRectangle().y + 10}, fontMenu.baseSize, 1, color);
        EndDrawing();
    }
}

void UI::setNumberOfPlayers(int players)
{
    numberOfPlayers = players;
}

void UI::initializeStatesCoordinates()
{
    statesCoordinates.insert(std::make_pair("bella", std::map<int, int>()));
    statesCoordinates["bella"].insert(std::make_pair(870, 165));
    statesCoordinates.insert(std::make_pair("caline", std::map<int, int>()));
    statesCoordinates["caline"].insert(std::make_pair(882, 310));
    statesCoordinates.insert(std::make_pair("bella", std::map<int, int>()));
    statesCoordinates["enna"].insert(std::make_pair(818, 410));
    statesCoordinates.insert(std::make_pair("enna", std::map<int, int>()));
    statesCoordinates["atela"].insert(std::make_pair(874, 560));
    statesCoordinates.insert(std::make_pair("atela", std::map<int, int>()));
    statesCoordinates["dimase"].insert(std::make_pair(704, 517));
    statesCoordinates.insert(std::make_pair("dimase", std::map<int, int>()));
    statesCoordinates["olivadi"].insert(std::make_pair(591, 524));
    statesCoordinates.insert(std::make_pair("olivadi", std::map<int, int>()));
    statesCoordinates["lia"].insert(std::make_pair(493, 622));
    statesCoordinates.insert(std::make_pair("lia", std::map<int, int>()));
    statesCoordinates["armento"].insert(std::make_pair(478, 470));
    statesCoordinates.insert(std::make_pair("armento", std::map<int, int>()));
    statesCoordinates["morina"].insert(std::make_pair(539, 287));
    statesCoordinates.insert(std::make_pair("morina", std::map<int, int>()));
    statesCoordinates["talmone"].insert(std::make_pair(343, 225));
    statesCoordinates.insert(std::make_pair("talmone", std::map<int, int>()));
    statesCoordinates["elinia"].insert(std::make_pair(200, 185));
    statesCoordinates.insert(std::make_pair("elinia", std::map<int, int>()));
    statesCoordinates["rollo"].insert(std::make_pair(420, 134));
    statesCoordinates.insert(std::make_pair("rollo", std::map<int, int>()));
    statesCoordinates["pladaci"].insert(std::make_pair(669, 158));
    statesCoordinates.insert(std::make_pair("pladaci", std::map<int, int>()));
    statesCoordinates["borge"].insert(std::make_pair(701, 348));
    statesCoordinates.insert(std::make_pair("borge", std::map<int, int>()));
    statesCoordinates["alora"].insert(std::make_pair(769, 600));
    statesCoordinates.insert(std::make_pair("alora", std::map<int, int>()));
}

void UI::initializeWarSignColors()
{
    warSignColors =
        {
            {"purple", warSigns[0]},
            {"blue", warSigns[1]},
            {"green", warSigns[2]},
            {"red", warSigns[3]},

        };
}
