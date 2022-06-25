
#include "Computer.h"
#include "Player.h"
#include "randutils/randUtils.h"
#include <iostream>


Computer::Computer(int hp): Dueler{hp}
{

}

Computer::Computer()
{
    m_hp = 50;
}

// override only goes in function declaration
void Computer::heal(int healing)
{
    std::cout <<  "\n" << "The computer is casting a healing spell to add "
    << healing << " hp" << "\n"; 
    m_hp = m_hp + healing; // this line insn't working
}


void Computer::attack(Dueler& dueler, int damage)
{
    int hit = randUtils::getRand(damage, 3);
    if (hit >= damage + 3)
        std::cout << "The monster connects with a powerful strike on the player, "
        << "doing " << hit << " hp of damage" << "\n";
    else if (hit <= damage - 3)
        std::cout << "The monster's attack knicks the player, doing only "
        << hit << " hp of damage" << "\n";
    else
        std::cout << "The monster delivers a strike of " << hit << " damage"
        << " on the player." << "\n";

    dueler.takeHP(hit);
    

}


void Computer::dodge(Player& player, Computer& computer) 
{

}