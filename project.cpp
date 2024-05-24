#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Map
{
public:
    int setMapFromFile()
    {
        mapFile.open("map.txt", ios::in);
        if (!mapFile.is_open())
        {
            cerr << "Error opening the file!" << endl;
            return 1;
        }
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 5; j++)
            {

                mapFile >> map[i][j];
                cout << map[i][j] << endl;
            }
        }

        return 0;
    }
    void printMap()
    {
        for (int i = 0; i < 7; i++)
        {

            for (int j = 0; j < 5; j++)
            {
                cout << map[i][j];
            }
        }
    }

private:
    string map[7][5];
    ifstream mapFile;
    struct mapStates
    {
    };
};
class Player
{
public:
    Player(int Age, string Name, string COLOR)
    {
        age = Age;
        name = Name;
        color = COLOR;
    }
    int getAge()
    {
        return age;
    }
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return color;
    }
    int getNumberOfPlayer()
    {
        return numberOfPlayer;
    }

private:
    int age;
    int numberOfPlayer;
    string name;
    string color;
};
class card
{
public:
    int getNumberOfCard()
    {
        return numberOfCard;
    }
    void setScore(int value)
    {
        controlscore += value;
    }
    int getScore()
    {
        return controlscore;
    }

private:
    string typeOfCard;
    int numberOfCard;
    int controlscore = 0;
};
class map
{
public:
private:
};
class armyCard : public card
{
public:
    armyCard(int score)
    {
        setScore(score);
    }

private:
    int armyScore;
};
class specialCard : public card
{
public:
    int getPriority()
    {
        return priority;
    }
    void setNameOfSpecialCard(string nameOfSpecialCard)
    {
        name = nameOfSpecialCard;
    }
    string getNameOfSpecialCard()
    {
        return name;
    }

private:
    string name;
    int priority;
};
class shirDokht : public specialCard
{
public:
    shirDokht()
    {
        setScore(10);
        setNameOfSpecialCard("shirDokht");
    }

private:
    int score;
};
class Matarsak : public specialCard
{
public:
    Matarsak()
    {
        setNameOfSpecialCard("MaTarsak");
    }

private:
};
class tablZan : specialCard
{
public:
    tablZan()
    {
        setNameOfSpecialCard("tablZan");
    }
};
class Bahar : public specialCard
{
public:
    Bahar()
    {
        setNameOfSpecialCard("Bahar");
    }
};
class Zemestan : public specialCard
{
public:
    Zemestan()
    {
        setNameOfSpecialCard("Zemestan");
        setScore(1);
    }
};
class getData
{
public:
    int setPlayerNumber()
    {
        int playerAge;
        string PlayerName;
        string playerColor;
        cin >> playerNumber;
        if (playerNumber >= 3 && playerNumber <= 6)
        {
            for (int i = 0; i < playerNumber; i++)
            {
                cout << "Enter the " << i + 1 << " player name: ";
                cin >> PlayerName;
                cout << "Enter the " << i + 1 << " player age: ";
                cin >> playerAge;
                cout << "Enter the " << i + 1 << " player chosen color: ";
                cin >> playerColor;
                players.push_back(Player(playerAge, PlayerName, playerColor));
                // cout << endl << players[i].getAge() << endl;
            }
        }
        else
        {
            cout << "wrong number!!\n\tTry again: ";
            setPlayerNumber();
        }
    }

private:
    vector<Player> players;
    int playerNumber;
};
int main()
{
    Map M;
    M.setMapFromFile();
    M.printMap();
    Zemestan m;
    // m.setName ();
    shirDokht s;
    cout << m.getNameOfSpecialCard();
    cout << m.getScore();
    cout << endl
         << s.getScore();
    getData j;
    j.setPlayerNumber();
    return 0;
}
