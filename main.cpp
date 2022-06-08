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


class Dueler
{
protected:
    int m_hp {};
    int m_action {};
public: 

    Dueler(int hp = 1): m_hp{hp} 
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

    // void heal(int healing)
    // {
    //     m_hp = m_hp + healing;
    // }

    // pure virtual function. A virtual function is a function defined in a 
    // base class with the intention of being redefined in a derived class. 
    // A pure virtual function demands to be redefined in all derived classes, and
    // you'll get errors if you don't. 
    // We'll never make an object called "Dueler:" it's simply a template on which
    // we define other stuff. As such, this function is a pure and virtual.
    virtual void heal(int healing) = 0;

    //virtual void dodge(Player& player, Computer& computer) = 0;


    // overloaded assignment operator:
    // Dueler& operator=(const Dueler& dueler)
    // {
    //     m_hp = dueler.m_hp;
    //     return *this;
    // }

};

// class Player: public Dueler
// {

// };

// class Computer: public Dueler
// {

// };


// if we have stufff from Computer we want to use in Player, we need to 
// forward declare both classes.
class Player;
class Computer;


class Player: public Dueler
{
private:
    // PSA: doing int m_hp{} here will result in heal() not doing anything 
    // (i.e., not increasing player.m_hp). Honestly, I'm not completely sure why,
    // but just don't do it. The whole point of inheritance is to INHERIT members
    // from parent classes, so it doesn't make sense to just redefine the same 
    // data member here.

    // As such, the better solution is to use 'protected' in the base class for 
    // the members you want to be inherited and leave it at that.
public:

    Player(int hp = 1): Dueler{hp} 
    {

    }

    void heal(int healing) override
    {
        std::cout << "The player is casting a healing spell to add "
        << healing << " hp" << "\n"; 
        m_hp = m_hp + healing; // this line isn't working
        // Dueler::heal(healing); // this works, but I'm not sure if it's fixing the root problem
    }

    void dodge(Player& player, Computer& computer)
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


  



};





class Computer: public Dueler 
{
private:
public:

    Computer(int hp = 1): Dueler{hp}
    {

    }

    void heal(int healing) override
    {
        std::cout <<  "\n" << "The computer is casting a healing spell to add "
        << healing << " hp" << "\n"; 
        m_hp = m_hp + healing; // this line insn't working
    }


    void dodge(Player& player, Computer& computer) 
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
        case 'a': playerTurn(player, computer);     break;
        case 'd': std::cout << "dodge";
                  player.dodge(player, computer); 
                break;
        case 'h': player.heal(2);                   break; 

        default: 
            std::cout << "That command isn't recognized. ";
            std::cout << "Your action defaults to attack.";
            playerTurn(player, computer);
        break;
    }

    return player;

}


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




//TODO: add in a turn component. The player should be prompted to attack, and then 
// stuff should continue. Also, you have some overridden functions, so implementing some
// virtual functions might be a good exercise. Also, shoehoern in const and constexpr for variable initializtion.
// other stuff to include: enums, arrays


// TODO: figure out why player.heal() doesn't add hp to the player. The turn aspect is integrated
// now, so the next step is to fold in these different abilities into each class. We need to figure out 
// a good way to have these methods (like attack) interact with the environment.

// After that, make multiple weapons. Make a class called Weapon. Then derive stuff (swords, maces)
// from Weapon.Also, using examples from learncpp.com, implement some sort of virtual function mechanic.





