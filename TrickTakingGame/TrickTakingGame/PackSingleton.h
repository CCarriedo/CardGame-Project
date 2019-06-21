#ifndef PACKSINGLETON_H
#define PACKSINGLETON_H
#include <vector>
#include <deque>
#include "Card.h"
#include "TTG_Player.h"

class PackSingleton
{
    static PackSingleton* instance;

public:
    static PackSingleton* Instance();
    static void Release();
    void display();
    void shuffle(int howManyTimes=1);
    bool deal(std::vector<Player *> players, unsigned int howManyCards);
    unsigned int how_many_dealt();
private:
    PackSingleton();
    ~PackSingleton();
    std::deque <Card *> cards;
    unsigned int cardsDealt;
};

#endif // PACKSINGLETON_H
