#ifndef DULER_H
#define DULER_H


class Dueler
{
protected:
    int m_hp;
    int m_action;
public: 


    Dueler(int hp);
    Dueler();
    int attack(const int& attackDamage);
    int showHP() const; // const because getHP shouldn't alter hp
    void takeHP(int damage);

    // pure virtual function. A virtual function is a function defined in a 
    // base class with the intention of being redefined in a derived class. 
    // A pure virtual function demands to be redefined in all derived classes, and
    // you'll get errors if you don't. 
    // We'll never make an object called "Dueler:" it's simply a 'template' on which
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


#endif