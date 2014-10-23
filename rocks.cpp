/***********************************************************
 * rocks.cpp
 *   Implementation of the functions found in rock.h
 * Author
 *   Weston Dransfield
 **********************************************************/
#include <iostream>
#include "uiInteract.h"
#include "ship.h"
#include "point.h"
#include "uiDraw.h"
#include "rocks.h"
#include "inertia.h"
#include "asteroids.h"

#include <list>

#define ROTATION_SPEED 1

using namespace std;

/***********************************************************
************************************************************
***************Constructors & Destructors*******************
************************************************************
***********************************************************/

/***********************************************************
 * BigRock
 * constructor gives the rock a random y, a x at x min,
 * and a random velocity
 **********************************************************/
BigRock :: BigRock() : Rock('R')
{
  v.setX(v.getXMin());             //set x to side of screen
  //set y to a raondom number
  v.setY(random(v.getYMin(),v.getYMax()));
  v.setAngle(random(0,360));       //set random velocity
}

/***********************************************************
************************************************************
*******************Public Methods***************************
************************************************************
***********************************************************/

/**********************************************************
 *incrmenet
 *This function is how rocks increment
 * SET rotation to orientation + rotSpeed
 * SET x to x + dx
 * SET y to y + dy
 * doWrap
 *********************************************************/
void Rock :: increment()
{
  //rotate the asteroid
  setOrient(getOrient() + rotSpeed);

  //move it along its vecotr
  v.setX(v.getX() + v.getDX());
  v.setY(v.getY() + v.getDY());

  //if it leaves the screen, wrap around
  doWrap();
}

/*********************************************************
 * hit
 * This function does a hit test for rocks
 * IF testing against a bullet
 *  IF v - p->v < getSize
 *    SET this to dead
 *    SET p to dead
 *    SET this v += p->v
 ********************************************************/
bool Rock :: hit(Inertia *p, Asteroids & aster)
{
  //make sure we are comparing to a bullet
  if(p->getType() == 'B')
    {
      if(v.getMinDist(p->v) < getSize()) //if we have a hit
	{
	  this->setIsDead(true);         //kill this
	  p->setIsDead(true);            //kill the bullet
	  this->v = this->v + p->v;      //add the physics
	}
    }
}

/**********************************************************
 * BigRock :: draw
 * This function draws a big rock
 *********************************************************/
void BigRock :: draw() const
{
  //make a point at current x and y, draw the rock
  Point temp(v.getX(), v.getY());
  drawCircle(temp, 40, 8, getOrient());
}

/**********************************************************
 * MedRock :: draw
 * This function draws a medium rock
 *********************************************************/
void MedRock :: draw() const
{
  //make a point at current x and y, draw the rock
  Point temp(v.getX(), v.getY());
  drawCircle(temp, 25, 5, getOrient());
}

/**********************************************************
 * SmallRock :: draw
 * This function draws a small rock
 *********************************************************/
void SmallRock :: draw() const
{
  //make a point at current x and y, draw the rock
  Point temp(v.getX(), v.getY());
  drawCircle(temp, 15, 5, -getOrient());
}
