//-----------------------------------------------------------
// Purpose: Header file for the CreatureList class.
//-----------------------------------------------------------
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "CreatureNode.h"
using namespace std;

#ifndef CREATURE_LIST_H
#define CREATURE_LIST_H

class CreatureList 
{
public:
   // Constructor methods
   CreatureList();
   ~CreatureList();

   // Other methods
   void spawn_creature(int &id,
                       float xposition,float yposition,
                       float xvelocity,float yvelocity,
                       int& health,int& strength,int & count);  // Add parameters
   void kill_creature(int &count ,int &total_killed , int id , int& min);   // Add parameters
   void blast_creatures(float xposition, float yposition, int& count,int&total_killed); // Add parameters
   void move_creatures();  
   void print_creatures() const ;

private:
   // Debugging flag
   static const bool DEBUG = false;
   int Count;
   
   float Xmin,Ymin;
   float Xmax,Ymax;
   
   CreatureNode * head;
  
};
#endif


#ifndef CREATURELIST_H
#define CREATURELIST_H



#endif /* CREATURELIST_H */

