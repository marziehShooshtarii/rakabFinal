#ifndef ZEMESTAN_HPP
#define ZEMESTAN_HPP
#include "Special.hpp"
class Zemestan :public Special
{
    public:
    virtual int effectOfCard(std::vector<Card>,int score)override;
    //static void zemestanPlayed();
    int countAllSpecialCards(std::vector<Card>);
    int countZemestan(std::vector<Card>);
    int countTabl_zan(std::vector<Card>);
    int countBahar(std::vector<Card>);
    int countShir_dokht(std::vector<Card>);
    int countMatarsak(std::vector<Card>);
    int countShirzan(std::vector<Card>);
    int countRish_sefid(std::vector<Card>);
    int countParcham_dar(std::vector<Card>);
   // static void endOfZemestan();
    static void endOfZemestan()
{
    checkZemestanPlayed = false;
}
static void zemestanPlayed()
{
    checkZemestanPlayed = true;
}
    static bool checkZemestanPlayed;
    private:
};
bool Zemestan::checkZemestanPlayed  (false);
#endif 