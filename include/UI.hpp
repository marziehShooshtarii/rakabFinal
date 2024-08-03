#ifndef UI_HPP
#define UI_HPP
#include <string>
#include <vector>
#include <unordered_map>
#include "raylib.h"
#include "Button.hpp"
#include "uiInput.hpp"
#include "Card.hpp"
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
    void unloadTextBox();
    // void initializeFontMenu();
    void initializeBackgroundMenu();
    void initializeButtons();
    void initializeIdentityMenu();
    int displayPlayerNumberButton();
    void initializePlayerNumberButton();
    void clearTextBox();
    // bool Textbox();
    void AddTextBox(float x, float y, float width, float height);
    void textBoxUpdate();
    void textBoxDraw(Font font, int framesCounter);
    bool thripleTextBoxDraw();
    // bool confirmButton();
    bool quadrupleTextBoxDraw();
    std::vector <char> getNamesFromUI(int index);
    void initializeConfirmPlayerDataButton(float x , float y , float width , float hight);
    void initializeQuadrupleConfirmPlayerDataButton();
    // bool displayConfirmPlayerDataButton();
    char * getFullNameFromUI(int index);
    std::vector <char> getAgeFromUI(int index);
    void controlTransitionVectors(int);
    std::string getPlayerNameAndColorFromUI(int playerTextBoxIndex);

    int getPlayerAgeAndLuckFromUI(int playerAgeIndex);
    int displayWarzoneButton(std::string);
    void initializeWarzoneButton(float x, float y, float width, float hight);
    void initializeWarzoneMap();
    bool displayMap(std::string);
    void renderTextureForWarzoneMap();
    bool displayCharectersAndNames(std::string, std::string,std::string);
    void initializeNextButton(float x, float y, float width, float hight);
    bool displaySelectedWarzone(std::string);
    
    void initializeCharacterNumber();
    bool getLuckNumbers(std::string);
    void displaycharactersCards();
    bool renderTextureForCharacterOnGameTable();
    //bool renderTextureForCharactertwo();
    void initializeCardTextureAndName();
    void findTexture(std::vector<Card>,int);
    void initializeCardsButtons(float x, float y, float width, float hight);
    bool displayCardsButtons();
    void displayGameTableAndCharacters();
    void renderTextureForCharacterAndGameTable();
    void initializePlayerCardsHandler();
private:
    const char* menuButtonsTitle[4];
    int windowWidth = 1200;
    int windowHeight = 800;
    // Vector2 mousePssition;//find the mouse position
    // bool mousePressed;//check if mouse is pressed
    Rectangle rect;
    Font fontMenu;//first menu font
    Font gameFont;//the game font
    Font inputFont;//font used for user input
    Texture2D backgroundMenu;//menu background
    Texture2D backgroundIdentityMenu;//identity menu background
    Button menuButtons[4];//buttons displayed in the menu
    Button playerNumberButtons[3];//buttons for selecting player number
    std::vector<uiInput> textBoxes;//multiple text boxes
    Button ConfirmPlayerData; //for confiming data by 3 players
    Button quadrupleConfirmPlayerData; //for confiming data by 4 players
    Rectangle rectConfirmPlayerData;
    Button UIwarzone[15];//according to states in Map.cpp
    Texture2D backgroundWarzoneMap;
    Texture2D foregroundWarzoneMap;
    Button next;// for moving to the next step of the game
    Texture2D charectersAndNames; // for introducing charecters with their names
    Texture2D selectedWarzoneBackground; // for announcing the selected warzone
    Texture2D gameTable;//table background during the game
    std::unordered_map <int,Texture2D> characterNumber;
    std::unordered_map <std::string,Texture2D> UIcardName;
    Texture2D character1;
    Texture2D character2;
    Texture2D character3;
    Texture2D character4;
    RenderTexture2D renderTextureForGameTable;
    RenderTexture2D renderTextureForGameTableAndCharacters;
    Texture2D cards[15];
    std::vector <Texture2D> firstCharacterplayerCards;
    std::vector <Texture2D> secondCharacterplayerCards;
    std::vector <Texture2D> thirdCharacterplayerCards;
    std::vector <Texture2D> fourthCharacterplayerCards;
    std::vector <Texture2D> firstCharacterPlayedCards;
    std::vector <Texture2D> secondCharacterPlayedCards;
    std::vector <Texture2D> thirdCharacterPlayedCards;
    std::vector <Texture2D> fourthCharacterPlayedCards;
    std::unordered_map <int,std::vector<Texture2D>> playerCardsHandler;
    Button cardsButtons[10];
    int UITurnHandler;

    // uiInput UILuckNumber;//needed to get the luckNumber 
    // std::string UIPlayerName;
    // std::vector <std::string> allUIPlayerNames;
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