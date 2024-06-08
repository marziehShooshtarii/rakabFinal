#include <string>
class Player 
{
    public:
    Player(int Age, std::string Name, std::string COLOR);
    int getAge();
    std::string getName();
    std::string getColor();
    int getNumberOfPlayer();

private:
    int age;
    int numberOfPlayer;
    std::string name;
    std::string color;
};