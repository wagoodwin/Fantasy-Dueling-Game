#include "Player.h"
#include "Dueler.h"
#include <iostream>


Player::Player(int hp): Dueler{hp} 
{

}

Player::Player() // default constructor
{
    m_hp = 100;
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

void Player::dodge(Player& player, Computer& computer)
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

void Player::attack(Dueler& dueler)
{
    dueler.takeHP(2);
    std::cout << "its morbin time" << "\n";

}

