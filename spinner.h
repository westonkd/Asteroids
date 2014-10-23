/**********************************************************
 * spinner.h
 *   Header file for the spinner class
 * Author
 *   Weston Dransfield
 *********************************************************/

#ifndef SPINNER_H
#define SPINNER_H

#include "inertia.h"
#include "asteroids.h"

/*********************************************************
 * class Spinner
 * This class is the base class for rocks and ships
 ********************************************************/
class Spinner : public Inertia
{
 public:
  //constructor
 Spinner() : orientation(270.0), Inertia() {};

  // pure virtual functions
  virtual bool hit(Inertia *p, Asteroids & aster) = 0;
  virtual void draw() const = 0;
  virtual int event() = 0;
  virtual void increment() = 0; 

  //public methods
  float getOrient() const;            //get the orientation
  //set the orientation
  void setOrient(const int newOrient) {orientation = newOrient;}

 private:
  int orientation;                    //contains ship orientation      
 };

#endif
