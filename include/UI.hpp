#ifndef UI_HPP
#define UI_HPP
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <array>
#include <utility>
#include "raylib.h"
#include "Button.hpp"
#include "uiInput.hpp"
#include "Card.hpp"

class UI
{
public:
    UI();
    ~UI();
    void initializRec();

    void drawRectUI();
    void displayMenuBackground();
    std::string menuGameLoop();
    void unloadingTexture();
    void initializeBackgroundMenu();
    void initializeButtons();
    void initializeIdentityMenu();
    int displayPlayerNumberButton();
    void initializePlayerNumberButton();
    void clearTextBox();
 
    void AddTextBox(float x, float y, float width, float height);
    void textBoxUpdate();
    void textBoxDraw(Font font, int framesCounter);
    bool thripleTextBoxDraw();

    bool quadrupleTextBoxDraw();
    std::vector<char> getNamesFromUI(int index);
    void initializeConfirmPlayerDataButton(float x, float y, float width, float hight);

    std::vector<char> getAgeFromUI(int index);
    void controlTransitionVectors(int);
    std::string getPlayerNameAndColorFromUI(int playerTextBoxIndex);

    int getPlayerAgeAndLuckFromUI(int playerAgeIndex);
    int displayWarzoneButton(std::string);
    void initializeWarzoneButton(float x, float y, float width, float hight);
    void initializeWarzoneMap();
    bool displayMap(std::string);
    void renderTextureForWarzoneMap();
    bool displayCharectersAndNamesForThree(std::string, std::string, std::string);
    bool displayCharectersAndNamesForFour(std::string, std::string, std::string,std::string);
    void initializeNextButton(float x, float y, float width, float hight);
    bool displaySelectedWarzone(std::string);

    void initializeCharacterNumber();
    bool getLuckNumbers(std::string);
    void displaycharactersCards(int);
    bool renderTextureForCharacterOnGameTable(int);
  
    void initializeCardTextureAndName();
    void initializeCardTextureAndStrings();
    void findTexture(std::vector<Card>, int);
    void initializeCardsButtons(float x, float y, float width, float hight);
    bool displayCardsButtons();
    int displayGameTableAndCharactersForThree(int, int);
    int displayGameTableAndCharactersForFour(int, int);
    void renderTextureForCharacterAndGameTable();
    void initializePlayerCardsHandler();
    void initializePlayedCardsHandler();
    void initializePlayedCardsFromUI();
    void initializePlayerCardsFromUI();
    void initializePlayedStringCard();
    bool validCardsForMatarsak();
    bool validateCardsForMatarsakInUI(int);
    void eraseAllCardsAfterWar();
    bool displayFinalWinner(int, std::string);
    void initializeSaveGameButton(float x, float y, float width, float hight);
    void initializeExitGameButton(float x, float y, float width, float hight);
    void initializePassButton(float x, float y, float width, float hight);
    void initializeHelpButton(float x, float y, float width, float hight);
    int ExitGameControl();
    std::string helpGameControl();
    std::vector<std::string> getPlayedCardsFromUI();
    bool displayWinner(int, std::string);
    bool displayNoWinner();
    void initializeCardsButtonsForMatarsak(float x, float y, float width, float hight);
    int numberOfInvalidCardsForMatarsak();
    void displaycharactersCardsForMatarsak(int turnHandler);
    void initializeOptionsForSavedGameNumber();
    void initializeOptionsAndDropdownBoundsForSavedGameNumber();
    void initializeDropDownMenuForSavedGameNumber();
    int displayOpenDropDownMenuForSavedGameNumber();
    void initializeHelpOptions();
    void initializeHelpOptionsAndDropdownBounds();
    void initializeHelpDropdownBounds();
    bool displayHelp(std::string);
    void displayRenderWarSigns();
    bool displayWarSigns(std::vector<int>, std::vector<std::string>, std::vector<int>, int, std::vector<std::string>,std::string);
    void setNumberOfPlayers(int);
    void initializeStatesCoordinates();
    void initializeWarSignColors();
    void initializeOptionsAndDropdownBoundsForColors();
    void initializeOptionsColors();
    void initializeDropDownMenuForColors();
    std::string displayOpenDropDownMenuForColors(std::string);
    int displayWarzoneForPeacsignButtons(std::string);

private:
    const char *menuButtonsTitle[4];
    int windowWidth = 1200;
    int windowHeight = 800;

    Rectangle rect;
    Font fontMenu;                     // first menu font
    Font gameFont;                     // the game font
    Font inputFont;                    // font used for user input
    Texture2D backgroundMenu;          // menu background
    Texture2D backgroundIdentityMenu;  // identity menu background
    Button menuButtons[4];             // buttons displayed in the menu
    Button playerNumberButtons[3];     // buttons for selecting player number
    std::vector<uiInput> textBoxes;    // multiple text boxes
    Button ConfirmPlayerData;          // for confiming data by 3 players
    Button quadrupleConfirmPlayerData; // for confiming data by 4 players
    Rectangle rectConfirmPlayerData;
    Button UIwarzone[15]; // according to states in Map.cpp
    Texture2D backgroundWarzoneMap;
    Texture2D foregroundWarzoneMap;
    Button next;                         // for moving to the next step of the game
    Texture2D charectersAndNames[2];        // for introducing charecters with their names
    Texture2D selectedWarzoneBackground; // for announcing the selected warzone
    Texture2D gameTableForThreePlayers;  // table background during the game for three players
    Texture2D gameTableForFourPlayers;   // table background during the game for four players
    std::unordered_map<int, Texture2D> characterNumber;
    std::unordered_map<std::string, Texture2D> UIcardName;

    std::unordered_map<int, std::string> playedStringCard;

    Texture2D character1;
    Texture2D character2;
    Texture2D character3;
    Texture2D character4;
    Texture2D matarsakAndCharacters[4];
    RenderTexture2D renderTextureForGameTable[3];
    RenderTexture2D renderTextureForGameTableAndCharacters;
    RenderTexture2D renderTextureForGameTableAndCharactersForFour;
    RenderTexture2D renderTextureMatarsakCharacters[4];
    RenderTexture2D renderTextureForWarSigns;
    Texture2D cards[17];
    Texture2D winnerBackgroundForEachWar[4];
    Texture2D winnerBackgroundForEndOfGame[4];
    Texture2D noWinner;
    Texture2D warzoneMapWithSigns;

    Button saveGame;
    Button exitGame;

    std::vector<Texture2D> firstCharacterplayerCards;
    std::vector<Texture2D> secondCharacterplayerCards;
    std::vector<Texture2D> thirdCharacterplayerCards;
    std::vector<Texture2D> fourthCharacterplayerCards;
    std::vector<Texture2D> firstCharacterPlayedCards;
    std::vector<Texture2D> secondCharacterPlayedCards;
    std::vector<Texture2D> thirdCharacterPlayedCards;
    std::vector<Texture2D> fourthCharacterPlayedCards;
    std::unordered_map<int, std::vector<Texture2D>> playerCardsHandler;
    std::unordered_map<int, std::vector<Texture2D>> playedCardsHandler;
    std::unordered_map<int, std::vector<std::string>> playedCardsFromUI;
    std::unordered_map<int, std::vector<std::string>> playerCardsFromUI;
    Button cardsButtons[10];
    int UITurnHandler;
    Texture2D luckNumberBackground;
    Texture2D warSigns[4];
    Texture2D peaceSignForUI;
    Texture2D peaceSignBackground;
    // Texture2D helpForEachCard;
    // Texture2D helpGeneral;

    Button passPosition;
    bool ifPlayerPassed[3]; // check the whole players position
    std::vector<std::string> firstPlayedCardsFromUI;
    std::vector<std::string> secondPlayedCardsFromUI;
    std::vector<std::string> thirdPlayedCardsFromUI;
    std::vector<std::string> forthPlayedCardsFromUI;
    std::vector<std::string> firstPlayerCardsFromUI;
    std::vector<std::string> secondPlayerCardsFromUI;
    std::vector<std::string> thirdPlayerCardsFromUI;
    std::vector<std::string> forthPlayerCardsFromUI;
    int UIstarterPlayer;
    std::vector<int> orderOfPlayedCardsForMatarsak;
    Button help;
    std::map<std::string, std::map<int, int>> statesCoordinates;
    std::map<std::string, std::map<int, int>>::iterator statesCoordinatesItr;
    std::map<int, int>::iterator statesCoordinatesPtr;
 
    std::string options[5];
    std::string selectedOption;
    bool isDropdownOpen;
    Rectangle dropdownBounds;
    Rectangle optionBounds[5];
    int savedGameNumber = -1; // no saved game selected
    std::string helpOptions[10];
    std::string selectedHelpOption;
    Rectangle dropdownHelpBounds;
    Rectangle helpOptionBounds[10];
    bool isDropdownOpenForHelp;
    std::string helpChoice;
    int numberOfPlayers;
    std::unordered_map<std::string, Texture2D> warSignColors;
    Rectangle colorOptionBounds [4];
    std::string colorOptions [4];
    bool isDropdownOpenForColor;
    Rectangle dropdownBoundsForColors;
    std::string selectedOptionForColors;
};
#endif