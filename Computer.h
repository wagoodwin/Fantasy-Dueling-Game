#ifndef COMPUTER_H
#define COMPUTER_H

#include "Dueler.h"
#include "Player.h"
#include <iostream>


class Computer: public Dueler 
{
private:
public:

    Computer(int hp);
    Computer(); // default constructor

    void heal(int healing) override;
    void dodge(Player& player, Computer& computer);

};




#endif