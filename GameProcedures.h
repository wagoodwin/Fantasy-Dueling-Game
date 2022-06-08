#ifndef GAMEPROCEDURES_H
#define GAMEPROCEDURES_H

#include "Player.h"
#include "Computer.h"
#include <iostream>

// Basic attack commands here (will probably be phased out)
void playerTurn(Player& player, Computer& computer);
void computerTurn(Player& player, Computer& computer);

// Returns commands to continue or end the game based on dueler health
int healthCheck(Player& player, Computer& computer);
int gameStatus(int healthCheck, Player& player, Computer& computer);
bool checkGameStatus(Player& player, Computer& computer);

// Holds game flow, player options, etc
Player chooseAction(Player& player, Computer& computer);



#endif