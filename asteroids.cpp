/************************************************************************
* Asteroids.cpp
*   Implementation of functions found in asteroids.h
* Author
*   Weston Dransfield
***********************************************************************/
#include "bullet.h"
#include <iostream>
#include "asteroids.h"
#include "uiInteract.h"
#include "ship.h"
#include "point.h"
#include <cassert>
#include "uiDraw.h"
#include "rocks.h"
#include <list>
#include <iostream>

#define NUM_ROCKS 6
#define SPREAD 10

using namespace std;

/***********************************************************
************************************************************
***************Constructors & Destructors*******************
************************************************************
***********************************************************/

/***********************************************************
 * ASTEROIDS
 *  ADD new ship to the lsit
 *  FOR i = 0 to the number of rocks
 *    ADD rock to the list
 **********************************************************/
Asteroids :: Asteroids() : score(0), isHighScore(false)
{
  //add the ship
  addItem(new Ship);

  //add the rocks
  for(int i = 0; i < NUM_ROCKS; i++)
    {
      addItem(new BigRock);
    }
}

/************************************************************
 * ~Asteroids
 *  This function frees the memory
 *    FOR it = elements.begin() to elements.end()
 *      DELETE element
 ***********************************************************/
Asteroids :: ~Asteroids()
{
  //iterate throug elements and delete each object
  for(list<Inertia*>::iterator it = elements.begin();
      it != elements.end();
      it++)
    {
      delete *it;
    }
 
}

/***********************************************************
************************************************************
*******************Public Methods***************************
************************************************************
***********************************************************/

/***********************************************************
 * INCREMENT
 * This function advances all objects in the game
 * FOR it = elements.begin() to elements.end()
 *   it.increment();
 * FOR it = elements.begin() to elements.end()
 *   FOR iter = elements.begin() to elements.end()
 *     check for a hit
 * remove dead objects
 **********************************************************/
void Asteroids :: increment()
{
  //increment all elements in list
  for(list<Inertia*>::iterator it = elements.begin();
      it != elements.end();
      it++)
    (*it)->increment();

  //check for hits
 for(list<Inertia*>::iterator it = elements.begin();
      it != elements.end();
      it++)
   {
     //do hit test with it for each other element in list
     for(list<Inertia*>::iterator iter = elements.begin();
	 iter != elements.end();
	 iter++
	 )
       (*it)->hit(*iter, *this);
   }

 //remove the dead objects
 removeDead();
}

/*****************************************************
 * REMOVEDEAD
 * This function removes all elements flagged as dead
 * If it removes a large or medium rock, it replaces it
 * with the necessary smaller ones.
 * 
 * FOR it = elements.begin() to elements.end()
 *   IF it isDead
 *     IF it is a big rock
 *        NEW MedRock two times
 *        NEW SmallRock
 *        Randomize new rocks' velocities
 *        SET MedRock.v += bullet.v
 *        SET SmallRock.v += bullet.v
 *        SET correct x and y coord
 *        ADD new rocks to list
 *      IF it is a medium rock
 *        do same as above with two SmallRocks
 *      DELETE it
 *      
 *****************************************************/
void Asteroids:: removeDead()
{
  //remove dead objects
  for(list<Inertia*>::iterator it = elements.begin();
      it != elements.end();
      it++)
    {
      //if the object is flagged as dead, remove it from list
      if((*it)->getIsDead())
	{
	  if((*it)->getType() == 'R')    //if killing a BigRock
	    {
	      //create a new medium rock
	      Inertia *p = new MedRock;
	      Inertia *p2 = new MedRock;
	      Inertia *p3 = new SmallRock;

	      //randomize the rocks' velocity
	      p->v.setAngle(random(0,360));
	      p2->v.setAngle(random(0,360));
	      p3->v.setAngle(random(0,360));
	     	     
	      //add the physics
	      p->v = p->v + (*it)->v;
	      p2->v = p2->v + (*it)->v;

	      //set the correct x and y
	      //MedRock One
	      p->v.setX((*it)->v.getX() - SPREAD);
	      p->v.setY((*it)->v.getY() - SPREAD);
	      
	      //MedRock Two
	      p2->v.setX((*it)->v.getX());
	      p2->v.setY((*it)->v.getY());

	      //SmallRock
	      p3->v.setX((*it)->v.getX() + SPREAD);
	      p3->v.setY((*it)->v.getY() + SPREAD);

	      //add it to the list
	      elements.push_back(p);
	      elements.push_back(p2);
	      elements.push_back(p3);
	      
	      //update the score
	      score += 100;
	    }
	  if((*it)->getType() == 'M')  //if killing a MedRock
	    {
	      Inertia *p = new SmallRock;
	      Inertia *p2 = new SmallRock;
	      
	      //randomize the rocks' velocity
	      p->v.setAngle(random(0,360));
	      p2->v.setAngle(random(0,360));
	      	     	     
	      //add the physics
	      p->v = p->v + (*it)->v;
	      p2->v = p2->v + (*it)->v;

	      //set the correct x and y
	      //SmallRock One
	      p->v.setX((*it)->v.getX() - SPREAD);
	      p->v.setY((*it)->v.getY() - SPREAD);
	      
	      //smae as above for Small rock Two
	      p2->v.setX((*it)->v.getX());
	      p2->v.setY((*it)->v.getY());

	      //add it to the list
	      elements.push_back(p);
	      elements.push_back(p2);

	      //update the score
	      score += 200;
	    }

	   if((*it)->getType() == 'T')  //if killing a small rock
	     score += 300;
	  //delete the hit item
	  delete *it;
	  it = elements.erase(it);
  	}
    }
}

/********************************************************
 * ADDITEM(Inertia *p)
 * This function ads a new item to the elements list
 * SET elements += p
 *******************************************************/
inline void Asteroids :: addItem(Inertia * p)
{
  elements.push_back(p);
}

/********************************************************
 * INTERACT
 * this function checks for any user interaction with the
 * game
 * IF spacebar is pressed
 *   IF the ship is alive
 *     SET tVector.angle to ship.orientation
 *     SET new Bullet andle and point to tVector
 *     SET elements += Bullet
 ********************************************************/
void Asteroids :: interact()
{
   //check to add bullets
  Interface tempUI;
  if(tempUI.isSpace())
    {
      //var to access the ship
      list<Inertia*>::iterator pShip = elements.begin();
      if((*pShip)->getType() == 'S')   //make sure ship lives
	{
	  //make a vector of ships orientation
	  Vector tVector;
	  float angle = (*pShip)->event() + 180;

	  //make sure orientation is in bounds
	  while(angle > 360)
	    angle -= 360;
	  while(angle < 0)
	    angle += 360;
	   
	  tVector.setAngle(angle); //set temp vectors angle
	  
	  //set the x and y to match the ship's
	  tVector.setX((*pShip)->v.getX());
	  tVector.setY((*pShip)->v.getY());
	  
	  //create new bullet at ships x and y
	  Inertia *p = new Bullet(tVector);
	  
	  //add new bullet to the list	  
	  elements.push_back(p);
	}
    }
}


/*******************************************************
 * DRAW
 * simple function to draw all elements in the list
 * FOR it = elements.begin() to elements.end()
 *   it.draw()
 ******************************************************/
void Asteroids :: draw()const
{
  //iterate through elements and draw each one
  for(list<Inertia*>::const_iterator it = elements.begin();
      it != elements.end();
      it++)
    (*it)->draw();
  //draw the score
  Point tPoint(-295, 195);
  drawNumber(tPoint,score);
  if(isHighScore)
    {
      Point tPoint(-50,0);
    drawText(tPoint,"New high score!");
    }
}

