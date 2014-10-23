/***********************************************************************
* Source File:
*    inertia.cpp contains implementation of functions found in 
*    inertia.h
* Author:
*    Weston Dransfield
* Summary:
*    Contains functions described in inertia.h 
************************************************************************/
#include "inertia.h"
#include "point.h"
#include <iostream>

#define BUFFER 30

using namespace std;

/***********************************************************
************************************************************
*******************Operator Overloading*********************
************************************************************
***********************************************************/

/***********************************************************
 * operator <<
 * this function overlaods the extractin operator for an 
 * inertia
 * PUT vector 
 * PUT isDead
 ***********************************************************/
ostream & operator<<(ostream & out, const Inertia & rhs)
{
  //output the vector and if it is dead
  out << "INERTIA\n"
      << rhs.getVector()
      << "\tisDead: " << rhs.getIsDead();
  
  return out;
}

/***********************************************************
************************************************************
*******************Public Methods***************************
************************************************************
***********************************************************/

/***********************************************************
 * isInBounds
 * this function checks to see if an inertia is in bounds
 * IF x is greater than x max or smaller than y min
 * 
 **********************************************************/
bool Inertia :: isInBounds() const
{
  if(v.getX() < v.getXMin() - BUFFER || v.getX() > v.getXMax() + BUFFER)
    return false;
  if(v.getY() < v.getYMin() - BUFFER || v.getY() > v.getYMax() + BUFFER)
    return false;
  return true;
}

/***********************************************************
 * doWrap
 * This function wraps the inirtial object around the screen
 * if the object leaves thes creen
 * IF x > x max
 *  SET x = x max + buffer
 * IF x < x min
 *  SET x = x min - buffer
 * IF y > y max + buffer
 *  SET y to y + buffer
 * IF y < y min 
 *  SET y to y - buffer
 ***********************************************************/
void Inertia :: doWrap() 
{
  if(v.getX() > v.getXMax() + BUFFER)    //off right hand side
    v.setX(v.getX() - 2 * v.getXMax() - 2 * BUFFER);
  if(v.getX() < v.getXMin() - BUFFER)    //off left hand side
    v.setX(v.getX() + 2 * v.getXMax() + 2 * BUFFER);
  if(v.getY() > v.getYMax() + BUFFER)    //off the top
    v.setY(v.getY() - 2 * v.getYMax() - 2 * BUFFER);  
  if(v.getY() < v.getYMin() - BUFFER)    //off the bottom
    v.setY(v.getY() + 2 * v.getYMax() + 2 * BUFFER);
}
