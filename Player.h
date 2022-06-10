#ifndef PLAYER_H
#define PLAYER_H

#include "Dueler.h"
#include <iostream>

// Some methods use objects of type Computer, so forward declare the class here:
class Computer; 


class Player: public Dueler
{
private:
    // PSA: doing int m_hp{} here will result in heal() not doing anything 
    // (i.e., not increasing player.m_hp). Honestly, I'm not completely sure why,
    // but just don't do it. The whole point of inheritance is to INHERIT members
    // from parent classes, so it doesn't make sense to just redefine the same 
    // data member here.

    // As such, the better solution is to use 'protected' in the base class for 
    // the members you want to be inherited and leave it at that.
public:

    Player(int hp);
    Player();
    void heal(int healing) override;
    void dodge(Player& player, Computer& computer);

    void attack(Dueler& dueler) override;


};

#endif