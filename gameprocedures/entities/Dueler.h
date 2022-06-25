#ifndef DUELER_H
#define DUELER_H



// For PRNG. See .cpp file for more details.

class Dueler
{
protected:
    int m_hp;
    int m_action;
public: 
    Dueler(int hp);
    Dueler();
    void takeHP(int damage);
    virtual void attack(Dueler& dueler, int damage);
    int showHP() const; // const because getHP shouldn't alter hp
  
    // pure virtual function. A virtual function is a function defined in a 
    // base class with the intention of being redefined in a derived class. 
    // A pure virtual function demands to be redefined in all derived classes, and
    // you'll get errors if you don't. 
    // We'll never make an object called "Dueler:" it's simply a 'template' on which
    // we define other stuff. As such, this function is a pure and virtual.
    virtual void heal(int healing);

    //virtual void dodge(Player& player, Computer& computer) = 0;

    // overloaded assignment operator:
    // Dueler& operator=(const Dueler& dueler)
    // {
    //     m_hp = dueler.m_hp;
    //     return *this;
    // }

};


#endif