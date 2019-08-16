//-----------------------------------------------------------
// Purpose: Main program to test the methods in the 
//          CreatureNode and CreatureList classes.
//-----------------------------------------------------------
#include <cstdlib>
#include "CreatureNode.h"
#include "CreatureList.h"

int main()
{
   // Variables
   int NUMBER = 0;
   CreatureList list;
 
   int id = 0;
   int count=0;
   int strength = 0;
   int health=100;
   float xposition,yposition,
         xvelocity,yvelocity;
   
   time_t s;
   time(&s);
   srand(s);
   
 //////////// Spawn some random creatures///////////////////
   /////////////////////////////////////////////////////////
 cout << "\nTesting spawn_creature method\n";
 cout << "Enter number of creatures to spawn: ";
 cin >> NUMBER;
 id = NUMBER;
   for (int i=0; i<NUMBER; i++)
   {
   count ++;
   
   xposition = (rand()%200)+(-100);
   yposition = (rand()%200)+(-100);
   xvelocity = (rand()%20 + (-10));
   yvelocity = (rand()%20 + (-10));
   strength = rand()%49 +1;
   
      list.spawn_creature(id,xposition,yposition,xvelocity,yvelocity,health,strength,count); 
   }
   list.print_creatures();
   cout << "COUNT = " << count << endl;
 
  
   
   int total_killed = 0;
  
   ///////////////Blast some random creatures   /////////////
   //////////////////////////////////////////////////////////
   cout << "\nTesting blast_creatures method\n";  
   cout << "Enter number of blasts to simulate: ";
   cin >> NUMBER;
   for (int i=0; i<NUMBER; i++)
   {
      xposition = (rand()%199)+(-99);
      yposition = (rand()%199)+(-99);
      cout<< " BLAST = ( " << setw(4)<< xposition <<" . " << setw(4) <<yposition <<"  ) "<<  endl;
      list.blast_creatures(xposition,yposition,count,total_killed); 
      
      //if blast kills more creatures than it spawned, 
      //it finishes the program.
      if(count <= 0)
      {  
          cout << "Total Killed = " << total_killed << endl;
          cout << " You have killed all the creatures!! " << endl;
          return 0;
      }
   }
   list.print_creatures(); 
   cout << "Total Killed = " << total_killed << endl;
   cout << "COUNT = " << count << endl;
  
   
    ///////////////Kill some random creatures   /////////////
   //////////////////////////////////////////////////////////
   int min;
   cout << "\nTesting kill_creatures method\n";
   cout << "Enter number of creatures to kill: ";
   cin >> NUMBER;
   for (int i=0; i<NUMBER; i++)
   {
      int kill_object = rand()%count+min; // To have a range from head ID down to count number
      cout << "KILLING ATTEMPTED CREATURE ID = " << kill_object << endl;
      
      list.kill_creature(count,total_killed,kill_object,min); 
    
      //if kills more creatures than it spawned, 
      //it finishes the program.  
      if(count <= 0)
      {  
          cout << "Total Killed = " << total_killed << endl;
          cout << " You have killed all the creatures!! " << endl;
          return 0;
      }
   
   }
   list.print_creatures();
   cout << "Total Killed = " << total_killed << endl;
   cout << "COUNT = " << count << endl;
   
   
   ///////////////Move some random creatures   /////////////
   //////////////////////////////////////////////////////////
   cout << "\nTesting move_creatures method\n";
   cout << "Enter number of movements to simulate: ";
   cin >> NUMBER;
   for (int i=0; i<NUMBER; i++)
   {
      list.move_creatures(); // Add parameters
      
   }
   list.print_creatures();    
    cout << "COUNT = " << count << endl;
   
 
   return 0;
}
