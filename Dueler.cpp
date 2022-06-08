#include "Dueler.h"


Dueler::Dueler(int hp): m_hp{hp}
{

}

Dueler::Dueler() // default constructor
{
    m_hp = 1;
}

int Dueler::attack(const int& attackDamage)
{
    return attackDamage;
}


int Dueler::showHP() const // const because getHP shouldn't alter hp
{
    return m_hp;
}

void Dueler::takeHP(int damage)
{
    m_hp = m_hp - damage;
}