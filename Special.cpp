#include "Special.hpp"
Special::Special(std::string name) : Card (name)
{
    if (name == "bahar")
        bahar();
    else if (name == "shirDokht")
        shirDokht();
    else if (name == "zemestan")
        zemestan();
    else if (name == "matarsak")
        matarsak();
    else if (name == "tablZan")
        tablZan();
}
void Special::setName(std::string name)
{
    Card::setName(name);
}
void Special::setCharacter(int value)
{
    Card::setCharacter(value);
}
void Special::setNumberOfCard(int numberOfCard)
{
    Card::setNumberOfCard(numberOfCard);
}
int Special::getPriority()
{
    return getCharacter();
}
int Special::shirDokht()
{
    setNumberOfCard(3);
}
int Special::zemestan()
{
    setNumberOfCard(3);
}
int Special::bahar()
{
    setNumberOfCard(3);
}
int Special::matarsak()
{
    setNumberOfCard(16);
}
int Special::tablZan()
{
    setNumberOfCard(6);
}