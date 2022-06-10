#include "GameProcedures.h"
#include "Player.h"
#include "Computer.h"
#include <iostream>

void playerTurn(Player& player, Computer& computer)
{
    computer.takeHP(1);

}

void computerTurn(Player& player, Computer& computer)
{
    player.takeHP(1);
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
            std::cout << "The monster has been slain" << "\n";
            // add looting function here in future 
            // Will add money to player object here with addmoney()
            return 2;
            break;
        case 3:
            std::cout << "The player has been slain" << "\n";
            return 3;
            break;
        case 4:
            std::cout << "Both duelers have been slain" << "\n";
            return 4;
            break;
        default:
            std::cout << "error: received an int not 1,2,3,4" << "\n";
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
    std::cout << "Choose your action. Press 'a' to attack," 
    << " 'd' to dodge, or 'h' to heal." << "\n";
    std::cin >> input;

    switch(input)
    {
        case 'a': player.attack(computer);     break;
        case 'd': std::cout << "dodge";
                  player.dodge(player, computer); 
                break;
        case 'h': player.heal(5);                   break; 

        default: 
            std::cout << "That command isn't recognized. ";
            std::cout << "Your action defaults to attack.";
            playerTurn(player, computer);
        break;
    }

    return player;

}