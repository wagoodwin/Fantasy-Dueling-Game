 #include "Dueler.h"
 #include "Player.h"
 #include "Computer.h"
 #include "GameProcedures.h"
 #include <iostream>
 

// main idea: human vs computer. take turns doing attacks and see who wins
// in int main or somewhere, have a big switch statement that has all of the 
// player's options. For now, we'll have attack or defend.

// We need to structure the game on a per-round basis. In a round, the player 
// chooses an action, and then the computer chooses an action. The player's and 
// and the computer's actions should have an effect on each other's hps.

// After each turn, we need to check everyone's hp. A turn is defined as an
// action by one dueler. We'll have these options:

// computer and player hp > 0
// computer hp > 0, player hp <= 0
// computer hp <= 0, player hp >= 0
// computer and player hp <= 0

// We could make a function that takes in hps and returns one of these options as different ints.
// From there, we could build a function with a switch statement that takes in these ints and executes different
// functions as a result. i.e., case 1 returns true and continues the game, case 2 
// ends the game and gives the player money or something, etc


int main()
{
    // initialize player and computer
    Player player {};
    Computer computer {};
    char input {};

    int gameCondition{1};

    // game should continue while the player is still alive
    while(true)
    {
        chooseAction(player, computer);
        if (checkGameStatus(player, computer) == false) break;

        std::cout << "Computer's turn:";
        computerTurn(player, computer);
        if (checkGameStatus(player, computer) == false) break;
        // Need to check game status after both turns. Otherwise,
        // it's possible for a player to still be able to act after
        // dying
    }

    std::cout << "The battle is over" << "\n";


    return 0;
}




// TODO: add in a turn component. The player should be prompted to attack, and then 
// stuff should continue. Also, you have some overridden functions, so implementing some
// virtual functions might be a good exercise. Also, shoehoern in const and constexpr for variable initializtion.
// other stuff to include: enums, arrays


// TODO: figure out why player.heal() doesn't add hp to the player. The turn aspect is integrated
// now, so the next step is to fold in these different abilities into each class. We need to figure out 
// a good way to have these methods (like attack) interact with the environment.

// After that, make multiple weapons. Make a class called Weapon. Then derive stuff (swords, maces)
// from Weapon.Also, using examples from learncpp.com, implement some sort of virtual function mechanic.


// TODO: FIRST THING: put everything in appropriate headers and definition files
// SECOND thing: start to add randomness to attacks-- now, attacks do damage within a range.
// That also means probably upping the hp and also switching hp values to doubles instead of ints.
// THIRD (or do this second) thing: finish the dodge mechanic so you can choose to dodge or heal


// TODO:
// FIRST THING: add randomness to attacks-- now, attacks occur on a distribution. Might need to, again, turn everything into floats
// SECOND THING: Add some logic to the computer-- like, if it's about to die, it tries to heal.
//               It should also be able to dodge and have the same rewards. 





