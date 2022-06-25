#ifndef COMPUTER_H
#define COMPUTER_H

#include "Dueler.h"
#include "Player.h"
#include <iostream>

// NEED TO IMPLEMENT ATTACK COMMAND FOR COMPUTER
class Computer: public Dueler 
{
private:
public:

    Computer(int hp);
    Computer(); // default constructor

    void heal(int healing) override;


    void attack(Dueler& dueler, int damage) override;

    void dodge(Player& player, Computer& computer);

};




#endif