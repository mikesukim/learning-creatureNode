//-----------------------------------------------------------
// Purpose: Implementation of the CreatureNode class.
//          This class is designed to store information
//          describing a creature in a video game.
//-----------------------------------------------------------
#include "CreatureNode.h"

//-----------------------------------------------------------
CreatureNode::CreatureNode()
{
   if (DEBUG) cout << "node constructor\n";
   
   ID = 0;
   Xposition = 0.0;
   Yposition = 0.0;
   Xvelocity = 0.0;     
   Yvelocity = 0.0;
   Health = 0;
   Strength = 0; 
   Next = NULL;
  
  
}

//-----------------------------------------------------------
CreatureNode::~CreatureNode()
{
   if (DEBUG) cout << "node destructor\n";
}

//-----------------------------------------------------------

void CreatureNode::setID(int id) 
{
    ID = id;
}
void  CreatureNode::setXposition(float xposition) 
{
    Xposition = xposition;
}
void  CreatureNode::setYposition(float yposition) 
{
    Yposition = yposition;
}
void  CreatureNode::setXvelocity(float xvelocity) 
{
    Xvelocity = xvelocity;
}
void  CreatureNode::setYvelocity(float yvelocity) 
{
    Yvelocity = yvelocity;
}
void CreatureNode::setHealth(int health) 
{
    Health = health;
}
void CreatureNode::setStrength(int strength) 
{
    Strength = strength;
}

//-----------------------------------------------------------

int CreatureNode::getID() const
{
   return ID; 
}
float CreatureNode::getXposition() const
{
   return Xposition;
}
float CreatureNode::getYposition() const
{
   return Yposition;
}
float CreatureNode::getXvelocity() const
{
   return Xvelocity;
}
float CreatureNode::getYvelocity() const
{
   return Yvelocity;
}
int CreatureNode::getHealth() const
{
   return Health;
}
int CreatureNode::getStrength() const
{
    return Strength;
}
void CreatureNode::print() const
{
   cout << " ID = "<< setw(2) << ID 
        << "   " << " Xposition = " << setw(4)<< Xposition 
        << "   " << " Yposition = " << setw(4)<< Yposition 
        << "   " << " Xvelocity = " << setw(4)<< Xvelocity 
        << "   " << " Yvelocity = " << setw(4)<< Yvelocity 
        << "   " <<  " Health = " << setw(4)<< Health 
        << "   " <<  " Strength = " << setw(2)<< Strength << endl;     
}

void CreatureNode::setNext(CreatureNode *next)
   {
       Next = next;
   }
CreatureNode* CreatureNode::getNext()
   {
       return Next;
   }
