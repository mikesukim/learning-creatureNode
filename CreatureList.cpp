//-----------------------------------------------------------
// Purpose: Implementation of the CreatureList class.
//          This class is designed to store a linked
//          list of video game creature objects.
//-----------------------------------------------------------
#include "CreatureList.h"


//-----------------------------------------------------------
CreatureList::CreatureList()
{ 
   if (DEBUG) cout << "list constructor\n";
   
   head = NULL;
}

//-----------------------------------------------------------
CreatureList::~CreatureList()
{
   // Walk list to delete nodes
   if (DEBUG) cout << "list destructor\n";
}

//-----------------------------------------------------------
void CreatureList::spawn_creature( int &id,
                float xposition,float yposition,
                float xvelocity,float yvelocity,
                int & health, int& strength, int & count) // Add parameters
{
   // Insert new node at head of list
   if (DEBUG) cout << "spawn creature\n";
     
   Count = count;     
    
   CreatureNode *temp;
   temp = new CreatureNode();
   temp ->setID(id);
   temp ->setXposition(xposition);
   temp ->setYposition(yposition);
   temp ->setXvelocity(xvelocity);
   temp ->setYvelocity(yvelocity);
   temp ->setHealth(health);
   temp ->setStrength(strength);
   temp ->setNext(head);
   head = temp;
  
   id --;
}

//-----------------------------------------------------------
void CreatureList::kill_creature(int & count,int &total_killed ,int id, int& min) 
{
   // Walk list to find node
   if (DEBUG) cout << "kill creature\n";
   
   min = head->getID();
   int killed = 0;
   
   
   CreatureNode * temp;
   CreatureNode * prev;
   temp = head;
   prev = NULL;
   
   while(temp != NULL)
   {
          
       if(temp -> getID() == id)
       {      
           if((temp != NULL)&&(temp == head))
           {
               cout << "killed creature ID = " << temp -> getID() << endl;
               head = temp -> getNext();
               delete temp;
               count --;
               killed ++;
             
           }
           else if (temp != NULL)   
           { 
               cout << "killed creature ID = " << temp -> getID() << endl;
               prev->setNext(temp->getNext());
               prev = temp;
               delete temp;
               count --;
               killed ++;                       
           }  
           cout << "KILLED = " << killed << endl;
       }  
       prev = temp;
       temp = temp -> getNext();
   }   
   total_killed += killed;
  
}

//-----------------------------------------------------------
void CreatureList::blast_creatures(float xposition, float yposition, int& count , int&total_killed) 
{
   // Walk list to blast creatures
   if (DEBUG) cout << "blast creatures\n";
   
   CreatureNode * temp;
   temp = head;
  
   //range of blasting
   float dead = 10.0;
   float fatal = 15.0;
   float injured = 20.0;
   float hurt = 30.0;

   while(temp != NULL)
   {
    if(( xposition - dead < (temp -> getXposition()) && xposition + dead > (temp -> getXposition()) ) &&
       ( yposition - dead < (temp -> getYposition()) && yposition + dead > (temp -> getYposition()) ))
        {
            temp->setHealth(temp->getHealth()-100);
        }
    else if(( xposition - fatal < (temp -> getXposition()) && xposition + fatal > (temp -> getXposition()) ) &&
            ( yposition - fatal < (temp -> getYposition()) && yposition + fatal > (temp -> getYposition()) ))
        {
            temp->setHealth(temp->getHealth()-50);
        }
    else if(( xposition - injured < (temp -> getXposition()) && xposition + injured > (temp -> getXposition()) ) &&
            ( yposition - injured < (temp -> getYposition()) && yposition + injured > (temp -> getYposition()) ))
        {
            temp->setHealth(temp->getHealth()-20);
        }
    else if(( xposition - hurt < (temp -> getXposition()) && xposition + hurt > (temp -> getXposition()) ) &&
            ( yposition - hurt < (temp -> getYposition()) && yposition + hurt > (temp -> getYposition()) ))
        {
            temp->setHealth(temp->getHealth()-10);
        }
    temp = temp -> getNext();
   }
   
   //       Kill creature if health goes 0 after blasting.   //
   temp = head;
   int id = 0;
   int min = 0;
   
   while(temp != NULL)
   {
       if(temp -> getHealth() <= 0)
       {
           id = temp -> getID();
           kill_creature(count , total_killed,id, min);
       }
       temp = temp->getNext();
   
   }
   
}

//-----------------------------------------------------------
void CreatureList::move_creatures() 
{
   // Walk list to move creatures
   if (DEBUG) cout << "move creatures\n";
   
   Xmin = -100;
   Xmax = 100;
   Ymin = -100;
   Ymax = 100;
   
   CreatureNode * temp;
   float xposition,yposition;
   
   temp = head;
     
   while(temp != NULL)
   {
        xposition = (temp -> getXposition())+(temp ->getXvelocity());
        yposition = (temp -> getYposition())+(temp ->getYvelocity());  
        
        // if creature go above max and min, 
        //  it stops at max and min.
        if(xposition > Xmax)
        {
            temp -> setXposition(Xmax);
        }
        else if(xposition < Xmin)
        {
            temp -> setXposition(Xmin);
        }
        else if(yposition > Ymax)
        {
            temp -> setYposition(Ymax);
        }
        else if(yposition < Ymin)
        {
            temp -> setYposition(Ymin);
        } 
        else{
        temp -> setXposition(xposition);
        temp -> setYposition(yposition);
        }
       
        temp = temp -> getNext();        
   }
   
}

//-----------------------------------------------------------
void CreatureList::print_creatures() const
{
   // Walk list to print creatures
   if (DEBUG) cout << "print creatures\n";
 
   CreatureNode * p = head;
   
   while(p != NULL)
   {
   p->print();
   p = p->getNext();
   }
}
