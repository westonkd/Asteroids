/***********************************************************************
* vector.cpp
*    implementation of functions in vector.h    
* Author:
*    Wesotn Dransfield and Jason Cooper (modified from from prj2)
*************************************************************************/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>     //std::abs, std::sqrt, std::pow
#include <algorithm> //std::max
#include "vector.h"
#include "point.h"
using namespace std;

/***********************************************************
************************************************************
*******************Public Methods***************************
************************************************************
***********************************************************/

/**********************************************************************
 * getMinDist() will find minimum distance so that program knows if
 * the bird and bullet should die
 ***********************************************************************/
float Vector::getMinDist(Vector & b)
{
   //Find number of times the distance should be measured
   float slicePerc = (1 /(float) max(max(abs(this->dx), abs(this->dy)),
                                     max(abs(b.dx), abs(b.dy))));
                                 //divide 1 by the max of the max
   float minDist;

   //measure distance every slice
   for(float percent = 0.0; percent <= 1.0; percent += slicePerc)
   {
      //first part of the distance formula: (x1 - x0)^2 + (y1 - y0)^2
      float distanceSquared = (pow((this->getX() + (this->dx * percent))
                                   - (b.getX() + (b.dx * percent)), 2)
                               +                                
                               pow((this->getY() + (this->dy * percent))
                                   - (b.getY() + (b.dy * percent)), 2));
      minDist = distanceSquared;
   }
   return sqrt(minDist); //complete the distance formula
}

/**********************************************************************
 * getAngle
 * This function puts the angle into terms of 0 - 360 with 0 and
 * 360 being on positive x axis (like unit circle)
 * IF angle is in quadrant I
 *   return angle
 * IF angle is in quadrant II
 *   return -angle + 90
 * IF angle is in quadrant III
 *   return angle + 180
 * IF angle is in quadrant IV
 *   return - angle + 270
 ***********************************************************************/
float Vector :: getAngle()const 
{
  //calculate the angle
  float angle = (atan((dy) / (dx))) * (180 / M_PI);
 
  if (dx >= 0 && dy >= 0)     //quadrant I
    return angle;
  if (dy >= 0)               //quadrant II
    return -angle + 90.0;
  if (dx <= 0 && dy <= 0)     //quadrant III
    return angle + 180.0; 
  return -angle + 270.0;    //quadrant IV
}

/**********************************************************************
 * setAngle
 * This function simply changes the dx and dy to fit the new angle
 *********************************************************************/
void Vector :: setAngle(const float angle)
{
  //just change the dx and dy to fit the new angle
  dx = cos((angle * (M_PI / 180)));
  dy = sin((angle * (M_PI / 180)));
}

/***********************************************************
************************************************************
*******************Operator overloading*********************
************************************************************
***********************************************************/

/************************************************************
 * operator+
 * This function does vector addition. 
 * SET DX += rhs.dx
 * SET DY += rhs.dy
 ***********************************************************/
Vector Vector :: operator+(const Vector & rhs) const
{
  //divide by 3 otherwise rhs overpowers this.
  float newDX = dx + (rhs.getDX() / 3.0);  //add rhs.dx
  float newDY = dy + (rhs.getDY() / 3.0);  //add rhs.dy
  Vector newVector(newDX, newDY);          //create the new vecor
  return newVector;
}

/***********************************************************
 * operator -
 * This function does vector subraction
 **********************************************************/
Vector Vector :: operator-(const Vector & rhs) const
{
  float newDX = dx - rhs.getDX(); //subtract rhs.dx
  float newDY = dy - rhs.getDY(); //subtract rhs.cy
  Vector newVector(newDX, newDY); //create new vector
  return newVector;
}

/************************************************************
 * assignment operator
 * just needs to copy over the dx and dy
 ***********************************************************/
void Vector :: operator=(const Vector & rhs)
{
  dx = rhs.dx;
  dy = rhs.dy;
}

/**************************************************************
 * operator <<
 * mainly for testing and debugging, just outputs all the info
 * about the vector
 *************************************************************/
std::ostream & operator<<(std::ostream & out, const Vector & rhs)
{
  out << "VECTOR\n"
      << "\tdx: " << rhs.getDX() << endl        //dx
      << "\tdy: " << rhs.getDY() << endl        //dy 
      << "\tmag: " << rhs.getMag() << endl      //maginitude
      << "\tangle: " << rhs.getAngle() << endl; //angle
  
  return out;
}
