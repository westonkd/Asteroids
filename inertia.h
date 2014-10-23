/***********************************************************************
* Header File:
*    Inertia
*    Brother Helfrich, CS165
* Author:
*    Weston Dransfield
* Summary: 
*    HEADER FILE for Intertia class
************************************************************************/

#ifndef INERTIA_H
#define INERTIA_H

#include <iostream>
#include "vector.h"
#include "inertia.h"
#include "asteroids.h"

class Asteroids;

/**********************************************************************
 * Class Inertia
 *    Access and mutate vector quantities that make up the direction and
 *    magnitude of the bullet and bird drawings
 ***********************************************************************/
class Inertia
{
 public:
 Inertia() : isDead(false) {/*empty*/};  //default constructor
 Inertia(int x, int y) : isDead(false)   //constructer that sets x and y
    {
      v.setX(x);
      v.setY(y);
    }
  virtual bool hit(Inertia *p, Asteroids & aster) {return false;} //hittest
  virtual void draw()const = 0;              //draw the inirtia
  virtual int event() = 0;                   //do inirtial event
  virtual void increment() = 0;              //incriment the inirtial object 

  virtual char getType() const {return ' ';          } //get type of inirtia
  void setIsDead(bool isDead) {this->isDead = isDead;} //set to dead
  bool getIsDead() const      {return isDead;        } //check if dead
  Vector getVector()const     {return v;             } //get the vecor
  bool isInBounds() const;                             //see if in bounds
  void doWrap();                                       //wrap the inirita  
  Vector v;

  //operator overloading
  friend std::ostream & operator<<(std::ostream & out, const Inertia & rhs);
 private:
  bool isDead;
};

#endif 
