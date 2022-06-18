#include "Dueler.h"
#include "randUtils.h"
#include <iostream>


Dueler::Dueler(int hp): m_hp{hp}
{

}

Dueler::Dueler() // default constructor
{
    m_hp = 100;
}

void Dueler::takeHP(int damage)
{
    m_hp = m_hp - damage;
}


void Dueler::attack(Dueler& dueler, int damage)
{
    // randomness included in derived implementations
    dueler.takeHP(damage); 
}

int Dueler::showHP() const // const because getHP shouldn't alter hp
{
    return m_hp;
}

void Dueler::heal(int healing)
{

    healing = randUtils::getRand(healing, 5);
    m_hp = m_hp + healing;

}
