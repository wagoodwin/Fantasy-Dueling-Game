#include "GameProcedures.h"
#include "entities/Player.h"
#include "entities/Computer.h"
#include <iostream>





void playerTurn(Player& player, Computer& computer)
{
    computer.takeHP(1);

}

void computerTurn(Player& player, Computer& computer)
{
    computer.attack(player, 10);
}



int healthCheck(Player& player, Computer& computer)
{

    if (player.showHP() > 0 && computer.showHP() > 0)
    {
        return 1;
    }
    else if (player.showHP() > 0 && computer.showHP() <= 0)
    {
        return 2;
    }
    else if (player.showHP() <= 0 && computer.showHP() > 0)
    {
        return 3;
    }
    else if (player.showHP() <= 0 && computer.showHP() <= 0)
    {
        return 4;
    }
    else
    {
        return 0;
    }

}


int gameStatus(int healthCheck, Player& player, Computer& computer)
{
    switch(healthCheck)
    {
        case 1:
            std::cout << "\n";
            std::cout << "Player HP: " << player.showHP() << "\n";
            std::cout << "Computer HP: " << computer.showHP() << "\n";
            std::cout << "\n";
            return 1;
            break;
        case 2:
            std::cout << "\n" << "The monster has been slain";
            // add looting function here in future 
            // Will add money to player object here with addmoney()
            return 2;
            break;
        case 3:
            std::cout << "\n" << "The player has been slain";
            return 3;
            break;
        case 4:
            std::cout << "\n" << "Both duelers have been slain";
            return 4;
            break;
        default:
            std::cout << "\n"<< "error: received an int not 1,2,3,4";
            return 5;
            break;
    }

}


bool checkGameStatus(Player& player, Computer& computer)
{
    int gameCondition = healthCheck(player,computer); 
    if(gameStatus(gameCondition, player, computer) != 1)
        return false;
    else
        return true;

}


Player chooseAction(Player& player, Computer& computer)
{

    char input{};
    std::cout << "\n" << "PLAYER TURN. Press 'a' to attack," 
    << " 'd' to dodge, or 'h' to heal. ";

    // using a while loop instead of a switch statement so we can loop back to the 
    // beginning if the user mis-inputs. Switch statements aren't iterative, so 
    // we can't implement this feature with them.
    while(true)
    {
        std::cin >> input;
        if (input == 'a')
        {
            player.attack(computer,10);
            break;
        }
        else if (input == 'd')
        {
            player.dodge(computer);
            break;
        }
        else if (input == 'h')
        {
            player.heal(10);
            break;
        }
        else
        {
            std::cout << "That command isn't recognized. Please reselect:" << "\n";
        }

    }
    // Weird "bug" (?): you can buffer your inputs. That is, if you press 'a'
    // n times in the command line, the n engagements will happen at once. 
    // It's not cheating, as both duelers are still taking turns, and you
    // can scroll back and still see those turns. However, it's not ideal 
    // in terms of quality of life.


    return player;

}