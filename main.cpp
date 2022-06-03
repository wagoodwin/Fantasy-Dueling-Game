 #include <iostream>

// // main idea: human vs computer. take turns doing attacks and see who wins
// // in int main or somewhere, have a big switch statement that has all of the 
// // player's options. For now, we'll have attack or defend.

// // We need to structure the game on a per-round basis. In a round, the player 
// // chooses an action, and then the computer chooses an action. The player's and 
// // and the computer's actions should have an effect on each other's hps.

// // After each turn, we need to check everyone's hp. A turn is defined as an
// // action by one dueler. We'll have these options:

// // computer and player hp > 0
// // computer hp > 0, player hp <= 0
// // computer hp <= 0, player hp >= 0
// // computer and player hp <= 0

// // We could make a function that takes in hps and returns one of these options as different ints.
// // From there, we could build a function with a switch statement that takes in these ints and executes different
// // functions as a result. i.e., case 1 returns true and continues the game, case 2 
// // ends the game and gives the player money or something, etc




// // could use ineritance later on to make Player and Computer derived from some sort of generic "dueler" class

// class Player
// {
// private:
//     int m_hp {};
//     int m_action {};

// public:

//     Player(int hp = 5): m_hp{hp} 
//     {

//     }

//     int attack(const int& attackDamage)
//     {
//         return attackDamage;
//     }

//     int getHP() const // const because getHP shouldn't alter hp
//     {
//         return m_hp;
//     }

//     void takeHP(int damage)
//     {
//         m_hp = m_hp - damage;
//     }

//     void giveHP(int healing)
//     {
//         m_hp = m_hp + healing;
//     }


// };



// class Computer
// {
// private:
//     int m_hp {};
// public:

//     Computer(int hp = 5): m_hp{hp}
//     {

//     }

//     // int attack(const int& attackDamage)
//     // {
//     //     return attackDamage;
//     // }

//     int attack(const int& attackDamage)
//     {
//         return attackDamage;
//     }

//     int getHP() const // const because getHP shouldn't alter hp
//     {
//         return m_hp;
//     }

//     void takeHP(int damage)
//     {
//         m_hp = m_hp - damage;
//     }

//     void giveHP(int healing)
//     {
//         m_hp = m_hp + healing;
//     }
 



// // void action(int m_action)
// // {
// //     switch (m_action)
// //     {
// //         case 1: std::cout << "attack"; 
// //         break;
// //         case 2: std::cout << "defend";
// //         break;

// //         default:
// //         std::cout << "ooga";
// //         break;
// //     }
// // }

// };



// int healthCheck(Player& player, Computer& computer)
// {

//     if (player.getHP() > 0 && computer.getHP() > 0)
//     {
//         return 1;
//     }
//     else if (player.getHP() > 0 && computer.getHP() <= 0)
//     {
//         return 2;
//     }
//     else if (player.getHP() <= 0 && computer.getHP() > 0)
//     {
//         return 3;
//     }
//     else if (player.getHP() <= 0 && computer.getHP() <= 0)
//     {
//         return 4;
//     }

// }


// int gameStatus(int healthCheck, Player& player, Computer& computer)
// {
//     switch(healthCheck)
//     {
//         case 1:
//             std::cout << "The battle continues." << "\n";
//             std::cout << "Player HP: " << player.getHP() << "\n";
//             std::cout << "Computer HP: " << computer.getHP() << "\n";
//             return 1;
//         break;
//         case 2:
//             std::cout << "The monster has been slain";
//             // add looting function here in future 
//             // Will add money to player object here with addmoney()
//             return 2;
//         break;
//         case 3:
//             std::cout << "The player has been slain";
//             return 3;
//         break;
//         case 4:
//             std::cout << "Both duelers have been slain";
//             return 4;
//         break;

//         default:
//             std::cout << "error: received an int not 1,2,3,4";
//             return 5;
//         break;
//     }

// }


// int exchangeAttack(Computer& computer, Player& player)
// {

//     return 0;
// }

// void playerTurn(Player& player, Computer& computer)
// {
//     computer.takeHP(1);

// }

// void computerTurn(Player& player, Computer& computer)
// {
//     player.takeHP(1);
// }




// // so maybe make this a bool and make it return true or false based on the result of the HP check.
// // it should go (human turn - hpCheck - computer turn - hpCheck) as a pattern
// int playDuelingGame(Player& player, Computer& computer) 
// {

//     // if (player.getHP() <= 0)
//     // {
//     //     return false;
//     // }

//     int gameCondition{};

//     playerTurn(player, computer);

//     gameCondition = healthCheck(player,computer);
//     gameStatus(gameCondition, player, computer);

//     computerTurn(player, computer);

//     gameCondition = healthCheck(player,computer);
//     gameStatus(gameCondition, player, computer);

//     // computerTurn(player, computer);

//     // gameCondition = healthCheck(player,computer);
//     // gameStatus(gameCondition, player, computer);


// }


// int main()
// {
//     // initialize player and computer
//     Player player {};
//     Computer computer {};

//     int gameCondition{1};

//     // game should continue while the player is still alive
//     while(gameStatus(gameCondition, player, computer) == 1)
//     {
//         playerTurn(player, computer);
//         // attempt at checking the game status after each turn
//         gameCondition = healthCheck(player,computer); 
//         gameStatus(gameCondition, player, computer);

//         computerTurn(player, computer);
//         gameCondition = healthCheck(player,computer);
//         gameStatus(gameCondition, player, computer);
//     }

//     std::cout << "The battle is over" << "\n";


//     return 0;
// }

class Dueler
{
private:
    int m_hp {};
    int m_action {};

public:

    Dueler(int hp = 5): m_hp{hp} 
    {

    }

    int attack(const int& attackDamage)
    {
        return attackDamage;
    }

    int getHP() const // const because getHP shouldn't alter hp
    {
        return m_hp;
    }

    void takeHP(int damage)
    {
        m_hp = m_hp - damage;
    }

    void giveHP(int healing)
    {
        m_hp = m_hp + healing;
    }


};

class Player
{
private:
    int m_hp {};
    int m_action {};

public:

    Player(int hp = 5): m_hp{hp} 
    {

    }

    int attack(const int& attackDamage)
    {
        return attackDamage;
    }

    int getHP() const // const because getHP shouldn't alter hp
    {
        return m_hp;
    }

    void takeHP(int damage)
    {
        m_hp = m_hp - damage;
    }

    void giveHP(int healing)
    {
        m_hp = m_hp + healing;
    }


};



class Computer
{
private:
    int m_hp {};
public:

    Computer(int hp = 5): m_hp{hp}
    {

    }

    int attack(const int& attackDamage)
    {
        return attackDamage;
    }

    int getHP() const // const because getHP shouldn't alter hp
    {
        return m_hp;
    }

    void takeHP(int damage)
    {
        m_hp = m_hp - damage;
    }

    void giveHP(int healing)
    {
        m_hp = m_hp + healing;
    }


};





int healthCheck(Player& player, Computer& computer)
{

    if (player.getHP() > 0 && computer.getHP() > 0)
    {
        return 1;
    }
    else if (player.getHP() > 0 && computer.getHP() <= 0)
    {
        return 2;
    }
    else if (player.getHP() <= 0 && computer.getHP() > 0)
    {
        return 3;
    }
    else if (player.getHP() <= 0 && computer.getHP() <= 0)
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
            std::cout << "The battle continues." << "\n";
            std::cout << "Player HP: " << player.getHP() << "\n";
            std::cout << "Computer HP: " << computer.getHP() << "\n";
            return 1;
        break;
        case 2:
            std::cout << "The monster has been slain";
            // add looting function here in future 
            // Will add money to player object here with addmoney()
            return 2;
        break;
        case 3:
            std::cout << "The player has been slain";
            return 3;
        break;
        case 4:
            std::cout << "Both duelers have been slain";
            return 4;
        break;

        default:
            std::cout << "error: received an int not 1,2,3,4";
            return 5;
        break;
    }

}

void playerTurn(Player& player, Computer& computer)
{
    computer.takeHP(1);

}

void computerTurn(Player& player, Computer& computer)
{
    player.takeHP(1);
}

int main()
{
    // initialize player and computer
    Player player {};
    Computer computer {};

    int gameCondition{1};

    // game should continue while the player is still alive
    while(gameStatus(gameCondition, player, computer) == 1)
    {
        playerTurn(player, computer);
        // attempt at checking the game status after each turn
        gameCondition = healthCheck(player,computer); 
        gameStatus(gameCondition, player, computer);

        if(gameStatus(gameCondition, player, computer) != 1)
            break;

        computerTurn(player, computer);
        // gameCondition = healthCheck(player,computer);
        // gameStatus(gameCondition, player, computer);
    }

    std::cout << "The battle is over" << "\n";


    return 0;
}