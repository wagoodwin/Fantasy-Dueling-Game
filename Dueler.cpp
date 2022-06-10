#include "Dueler.h"
#include <iostream>


// std::mt19937 mt: creates a Mersenne Twister PRNG
// std::random_device{}(): creates seed for PRNG
// use "static" so we don't reseed every time mt is called
static std::mt19937 mt{std::random_device{}()};

double getRand(double mean, double stdev)
{
    // creates a uniform dist of numbers between two numbers
    // creates a normal distribution with a mean and variance
    std::normal_distribution<> distribution{mean, stdev};
    // mt picks out a number from d10, giving us our number (I think)
    return distribution(mt);
}



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


void Dueler::attack(Dueler& dueler)
{
    dueler.takeHP(1);
}

int Dueler::showHP() const // const because getHP shouldn't alter hp
{
    return m_hp;
}

void Dueler::heal(int healing)
{

    std::cout << "From Dueler" << "\n";
    healing = getRand(healing, 5);
    m_hp = m_hp + healing;

}



