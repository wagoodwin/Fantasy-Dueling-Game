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

    int showHP() const // const because getHP shouldn't alter hp
    {
        return m_hp;
    }

    void takeHP(int damage)
    {
        m_hp = m_hp - damage;
    }

    void heal(int healing)
    {
        std::cout << "oogabooga" << "\n";
        m_hp = m_hp + healing;
    }

};

// we want to inherit basic stuff like getters and setters, but we don't want to inherit 
// stuff like HP, as HP will be different between duelers.
class Player: public Dueler
{
private:
    int m_hp {};
    int m_action {};
public:

    Player(int hp = 5): m_hp{hp} 
    {

    }
    // very bizzarre scenes: when we include this function, the player doesn't actually heal.
    // The player does heal when we don't include it-- that is, player inherits heal() from 
    // Dealer and it works, but player's own heal function doesn't work. Big thing we gotta resolve. 

    void heal(int healing)
    {
        std::cout << "The player is casting a healing spell to add "
        << healing << " hp" << "\n"; 
        m_hp = m_hp + healing; // this line insn't working
    }


};


class Computer: public Dueler 
{
private:
    int m_hp {};
    int m_action {};
public:

    Computer(int hp = 5): m_hp{hp}
    {

    }

};


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

int main()
{
    // initialize player and computer
    Player player {};
    Computer computer {};
    char input;

    int gameCondition{1};

    // game should continue while the player is still alive
    while(gameStatus(gameCondition, player, computer) == 1)
    {
        std::cout << "Choose your action. Press 'a' to attack," 
        << " 'd' to dodge, or 'b' to block." << "\n";
        std::cin >> input;

        switch(input)
        {
            case 'a': playerTurn(player, computer);  break;
            case 'd': std::cout << "dodge";          break;
            case 'b': player.heal(5);                break; // for some reason, player's HP isn't increasing. Not an issue with switch()

            default: 
                std::cout << "That command isn't recognized. ";
                std::cout << "Your action defaults to attack.";
                playerTurn(player, computer);
            break;
        }

        // check the game status after each turn
        gameCondition = healthCheck(player,computer); 
        if(gameStatus(gameCondition, player, computer) != 1)
            break;

        std::cout << "Computer's turn:";
        computerTurn(player, computer);
        // gameCondition = healthCheck(player,computer);
        // gameStatus(gameCondition, player, computer);
    }

    std::cout << "The battle is over" << "\n";


    return 0;
}

//TODO: add in a turn component. The player should be prompted to attack, and then 
// stuff should continue. Also, you have some overridden functions, so implementing some
// virtual functions might be a good exercise. Also, shoehoern in const and constexpr for variable initializtion.
// other stuff to include: enums, arrays


// TODO: figure out why player.heal() doesn't add hp to the player. The turn aspect is integrated
// now, so the next step is to fold in these different abilities into each class. We need to figure out 
// a good way to have these methods (like attack) interact with the environment.

// After that, make multiple weapons. Make a class called Weapon. Then derive stuff (swords, maces)
// from Weapon.Also, using examples from learncpp.com, implement some sort of virtual function mechanic.