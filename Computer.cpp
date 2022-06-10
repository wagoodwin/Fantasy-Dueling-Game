
#include "Computer.h"
#include "Player.h"
#include <iostream>


Computer::Computer(int hp): Dueler{hp}
{

}

Computer::Computer()
{
    m_hp = 100;
}

// override only goes in function declaration
void Computer::heal(int healing)
{
    std::cout <<  "\n" << "The computer is casting a healing spell to add "
    << healing << " hp" << "\n"; 
    m_hp = m_hp + healing; // this line insn't working
}


void Computer::dodge(Player& player, Computer& computer) 
{

}