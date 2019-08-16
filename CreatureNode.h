//-----------------------------------------------------------
// Purpose: Header file for the CreatureNode class.
//-----------------------------------------------------------
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#ifndef CREATURE_NODE_H
#define CREATURE_NODE_H

class CreatureNode
{
public:
   // Constructor methods
   CreatureNode();
   ~CreatureNode();
   // Set methods

   void setID(int id);
   void setXposition(float xposition);
   void setYposition(float yposition);
   void setXvelocity(float xvelocity);
   void setYvelocity(float yvelocity);
   void setHealth(int health);
   void setStrength(int strength); // Add parameters
   // TO BE ADDED
   // Get methods  
   int getID() const;
   float getXposition() const;
   float getYposition() const;
   float getXvelocity() const;
   float getYvelocity() const;
   int getHealth() const;
   int getStrength() const;  
 
   // Other methods
   void print() const;  
   void setNext(CreatureNode *next);
   CreatureNode * getNext();

private:
   // Debugging flag
   static const bool DEBUG = false;

   int ID;
   float Xposition, Yposition;
   float Xvelocity, Yvelocity;
   int Health;
   int Strength;   
   CreatureNode * Next;
   
};
#endif
