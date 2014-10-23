/**********************************************************
 * rocks.h
 *   header file for the rock classes
 * Author
 *   Weston Dransfield
 *********************************************************/
#ifndef ROCKS_H
#define ROCKS_H

#include "uiDraw.h"
#include "inertia.h"
#include "spinner.h"
#include "ship.h"
#include "bullet.h"
#include "asteroids.h"
#include <list>

/******************************************************************
 * class Rock
 * This is the base class for all sizes of rocks
 *****************************************************************/
class Rock : public Spinner
{
 public:
  //constructors and destructors
 Rock() : rType('0'), rotSpeed(random(1,5)), Spinner() {};
 Rock(char type) : rType(type), rotSpeed(random(1,5)), Spinner() {};

  //public methods
  char getType() const                    {return rType;} //get the type
  bool hit(Inertia *p, Asteroids & aster);                //check hit
  virtual void draw() const               {/*nothing*/  };//draw rock
  virtual int event()                     {return 0;    } //do event
  virtual int getSize() const             {return 0;    } //get size
  void increment();                                       //increment
  float rotSpeed;                                         //rotation speed
 private: 
  char rType;                                             //holds type
};

/******************************************************************
 * class BigRock
 * This is the class for the largest rock
 *****************************************************************/
class BigRock : public Rock
{
 public:
  //constructor
  BigRock();   

  //public methods        
  int getSize() const {return 50;} //gets the size
  void draw() const;               //draws the rock
};

/******************************************************************
 * class MedRock
 * This is the class for the medium sized rock
 *****************************************************************/
class MedRock : public Rock
{
 public:
  //constructor
  MedRock() : Rock('M') {};

  //public methods
  int getSize() const {return 30;} //gets the size
  void draw() const;               //draws the rock
};

/******************************************************************
 * class SmallRock
 * This is the class for the smallest rock
 *****************************************************************/
class SmallRock : public Rock
{
 public:
  //constructor
 SmallRock() : Rock('T') {};

  //public methods
  int getSize() const {return 20;} //gets the size
  void draw() const;               //draws the rock
};
#endif
