/**********************************************************
 * ship.h
 *   Header file for the ship class
 * Author
 *   Weston Dransfield
 *********************************************************/

#ifndef SHIP_H
#define SHIP_H

#include "inertia.h"
#include "asteroids.h"
#include "spinner.h"

/********************************************************
 * class Ship
 * representation of a ship for a game
 *******************************************************/
class Ship : public Spinner
{
 public:
  //constructor
 Ship() : Spinner() {v.setWrap(true);}

  //public methods
  char getType() const {return 'S';}  //tell what type  
  void draw() const;                  //draw the ship
  void increment();                   //increment ship
  void move(int thrust, int left, int right); //move ship
  int event();                        //handle events
  bool hit(Inertia *p, Asteroids & aster);    //check hit
  void checkScore(Asteroids & aster);
};

#endif
