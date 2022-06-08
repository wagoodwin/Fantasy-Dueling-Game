#include "Player.h"
#include "Dueler.h"
#include <iostream>


Player::Player(int hp): Dueler{hp} 
{

}

Player::Player() // default constructor
{
    m_hp = 1;
}


// note: syntax doesn't allow putting 'override' in a function outside the class
void Player::heal(int healing) 
{
    std::cout << "The player is casting a healing spell to add "
    << healing << " hp" << "\n"; 
    m_hp = m_hp + healing; // this line isn't working
    // Dueler::heal(healing); // this works, but I'm not sure if it's fixing the root problem
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

    // char inputDodge{};
    // std::cout << "Select 'a' to attack or 'h' to heal:" << "\n";

    // std::cin >> inputDodge;

    heal(2);


    // player.heal(2);

}
