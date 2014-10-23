/******************************************************************************
 * Header File:
 *    Bullet: the representation of a bullet on the screen
 * Author:
 *    Weston Dransfield
 * Summary:
 *    Contains all necessary methods and vars to create a bullet
 *****************************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "inertia.h"
#include "point.h"
#include "vector.h"
#include "asteroids.h"

/*************************************************************
 * class Bullet
 *  This class contains all vars and methods needed to creat
 *  a representation for a bullet in a game
 ************************************************************/
class Bullet : public Inertia
{
 public:
  // constructors
  Bullet() {assert(false);}          //should never be called
  Bullet(int x, int y, float angle); //sets x,y, and angle
  Bullet(float newAngle);            //sets only angle
  Bullet(Vector vector);             //sets x,y,and angle from vector

  //public functions
  char getType() const {return 'B';}      //gets the type 
  int event()          {return 0;  } 
  bool hit(Inertia *p, Asteroids & aster);
  void draw() const;                      //draws the bullet  
  void increment();
  bool isDead()        {};
  void kill()          {};

  //getters and setters
  void setAngle(float angle2);            //sets the angle
  float getAngle()     {return angle;}    //getes the angle
  float getDistTraveled() const;          //gets the distance tgravled
  
 private:
  Point origin;  //remembers point of origin  
  float angle;   //angle of travel
};

#endif

