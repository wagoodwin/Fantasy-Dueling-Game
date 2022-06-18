#include "Player.h"
#include "Dueler.h"
#include "randUtils.h"
#include <iostream>



Player::Player(int hp): Dueler{hp} 
{

}

Player::Player() // default constructor
{
    m_hp = 50;
}


// note: syntax doesn't allow putting 'override' in a function outside the class
void Player::heal(int healing) 
{
    std::cout << "The player is casting a healing spell to add "
    << healing << " hp" << "\n"; 
    Dueler::heal(healing);
    // Based on the input healing we get, we generate a normal distribution where
    // the mean is the healing that was input. Then, we randomly sample that 
    // distribution to get our healing value.
    // m_hp = m_hp + healing; 
}

void Player::attack(Dueler& dueler, int damage)
{
    int hit = randUtils::getRand(damage, 5);
    if (hit >= damage + 5)
        std::cout << "The player lands a brutal strike on the monster, "
        << "doing " << hit << " hp of damage" << "\n";
    else if (hit <= damage - 5)
        std::cout << "The player's attack grazes the monster, doing only "
        << hit << " hp of damage" << "\n";
    else
        std::cout << "The player delivers a strike of " << hit << " damage"
        << " on the monster." << "\n";

    dueler.takeHP(hit);
    

}


void Player::dodge(Dueler& dueler)
{
    // Idea: if you dodge successfully, you throw off your attacker,
    // giving you two moves consecutively. 
    // If you fail, the monster does extra damage. 

    // For now, we won't add the randomness aspect: we'll just have 
    // the player get two free moves. 

    std::cout << "You've dodged the monster's attack, leaving it open " <<
    "for a counter. With this extra time, you can deploy a boosted attack " <<
    "or heal." << "\n";

    //We'll also just assume the player healed.

    char inputDodge{};
    std::cout << "Select 'a' to attack or 'h' to heal:" << "\n";

    while(true)
    {
        std::cin >> inputDodge;
        if (inputDodge == 'a')
        {
            attack(dueler, 17);
            break;

        }
        else if (inputDodge == 'h')
        {
            heal(2);
            break;
        }
        else
        {
            std::cout << "Unrecognized input. Select 'a' to attack " <<
            "or 'h' to heal: " << "\n";
        }

    }

}


