/**************************************************************
 * bullet.cpp
 *   implementation of functions found in bullet.h
 * Author
 *   Weston Dransfield
 *************************************************************/
#include "bullet.h"
#include "point.h"
#include "uiDraw.h"
#include "vector.h"
#include "inertia.h"
#include "asteroids.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <stdio.h>

#define DISTANCE_LIMIT 300
#define BULLET_SPEED 20
#define _USE_MATH_DEFINES
#include <math.h>  

using namespace std;


/***********************************************************
************************************************************
***************Constructors & Destructors*******************
************************************************************
***********************************************************/
Bullet :: Bullet(Vector vector) : Inertia()
{
  angle = vector.getAngle();
  v = vector;
  v.setX(vector.getX());
  v.setY(vector.getY());

  //set origin
  origin.setX(v.getX());
  origin.setY(v.getY());
}

/***********************************************************
 * Bullet(angle)
 * this constructor creates a new bullet given an angle
 * SET angle to newAngle
 * SET origin to current x and y
 **********************************************************/
Bullet :: Bullet(float newAngle) : Inertia()
{
  angle = newAngle;

  //set origin
  origin.setX(v.getX());
  origin.setY(v.getY());
}

/*********************************************************
 * Bullet(x,y,angle)
 * SET angle to new angle
 * SET new x and y
 * SET orgin to current x and y
 *******************************************************/
Bullet :: Bullet(int x, int y, float angle) : Inertia()
{
  //set the angle,x, and y
  this->angle = angle;
  v.setX(x);
  v.setY(y);

  //set the origin
  origin.setX(v.getX());
  origin.setY(v.getY());
}

/***********************************************************
************************************************************
*******************Public Methods***************************
************************************************************
***********************************************************/

/***********************************************************
 * HIT
 * This function is no longer necessary
 **********************************************************/
bool Bullet :: hit(Inertia *p, Asteroids & aster)
{
  //not needed
}

/***********************************************************
 * DRAW
 * this function draws a bullet 
 *   drawDot(current x and y of bullet)
 **********************************************************/
void Bullet :: draw() const
{
  //draw a dot and currenht x and y
  Point point(v.getX(),v.getY());
  drawDot(point);
}
    
/************************************************************
 * increment
 * This function increments the bullet
 * SET v.DX = cos(angle) * speed of bullet
 * SET v.DY = sin(angle) * speed of bullet
 * SET v.x += DX
 * SET v.y += DY
 * IF bullet had travled past distance limit
 *   SET isDead to true
 ************************************************************/
void Bullet :: increment()
{
  
  float tempAngle = angle;
  
  //if in quad II we need to adjust...
  if(tempAngle > 90 && tempAngle <= 180)
    tempAngle = -tempAngle + 270;

  //same for quad III    
  if(tempAngle >= 270 && tempAngle <= 360)
    tempAngle = -tempAngle + 270;
  
  //set the correct dx and dy for given angle
  tempAngle *= (M_PI / 180);
  v.setDX(cos(tempAngle) * BULLET_SPEED);
  v.setDY(sin(tempAngle) * BULLET_SPEED);

  //add the dx and dy to current x and y
  v.setX(v.getX() + v.getDX());
  v.setY(v.getY() + v.getDY());
    

  //make sure the bullet has not travled past its limit
  if(getDistTraveled() > DISTANCE_LIMIT)
    this->setIsDead(true);
}

/*******************************************************
 * getDistTravled
 * this function calculates the distance the bullet
 * has travled
 * RETURN current point - origin
*******************************************************/
float Bullet :: getDistTraveled() const
{
  //overload - operator for point returns the distance
  Point tPoint(v.getX(),v.getY());
  return tPoint - origin;
}

