/************************************************************************
* ship.cpp
*   Implementation of functions found in ship.cpp
* Author
*   Weston Dransfield
***********************************************************************/
#include <fstream>
#include <iostream>
#include "point.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "ship.h"
#include "vector.h"

#define SPIN_LIM  18
#define SPEED_LIM 25 //unless otherwise marked

using namespace std;

/***********************************************************
************************************************************
*******************Public Methods***************************
************************************************************
***********************************************************/

/***********************************************************
 * draw
 * This is a simple function to draw a ship
 **********************************************************/
void Ship :: draw() const 
{
  //create point and current x and y, draw the ship there
  Point temp(getVector().getX(),getVector().getY());
  drawShip(temp, getOrient());
}

/***********************************************************
 * hit
 * This function checks if the ship hit a rock
 *    IF p == bullet
 *      return false
 *    IF p == rock and we hit it
 *      SET this to dead
 *      SET rock to dead    
 **********************************************************/
bool Ship :: hit(Inertia *p, Asteroids & aster)
{
  //if it's not a rock, don't worry
  if(p->getType() == 'B' || p->getType() == 'S')
    return false;
  
  //if we have a Rock, kill the ship and rock
  if(p->getType() == 'R' && v.getMinDist(p->v) < 50) //big rock
    {
      this->setIsDead(true); //kill the ship
      //this just makes dying a little more epic
      p->setIsDead(true);
      checkScore(aster);
    }
  if(p->getType() == 'M' && v.getMinDist(p->v) < 30) //med rock
    {
      this->setIsDead(true); //kill the ship
      //this just makes dying a little more epic
      p->setIsDead(true);
      checkScore(aster);
    }
  if(p->getType() == 'T' && v.getMinDist(p->v) < 20) //small rock
    {
      this->setIsDead(true); //kill the ship
      //this just makes dying a little more epic
      p->setIsDead(true);
      checkScore(aster);
    }

}
 
void Ship :: checkScore(Asteroids & aster)
{
//check high score
  ofstream fout("aScore.txt");
  
  //read the file
  ifstream fin("aScore.txt");
  if(fin.fail())
    cout << "Error reading file";
  int highScore;
  fin >> highScore;
  if(highScore < aster.getScore())
        {
	  Point tPoint(0,0);
	  aster.setIsHighScore(true);
	  fout << aster.getScore();
	}
  fin.close();
  fout.close();
}

/*****************************************************
 * increment
 * This function incrmenets the ship
 ****************************************************/
void Ship :: increment()
{
  Interface ui;
  move(ui.isUp(), ui.isLeft(), ui.isRight());
}

/******************************************************
 * move
 * This function moves the ship
 * IF pressing right
 *  SET orientation -= right * 2
 * IF pressing left
 *  SET orientation += left * 2
 * IF we have thrust
 *  SET temp.angle to ship orientatin
 *  SET ship.v -= temp
 * SET x += dx
 * SET y += dy
 * doWrap
 *****************************************************/
void Ship :: move(const int thrust,const int left,const int right)
{
  //if pressing right and spin is not too fast, spin right!
  if(right <= SPIN_LIM)             
    setOrient(getOrient() - right * 2);    //speed up until...  
  else
    setOrient(getOrient() - SPIN_LIM); //we hit the spin limit.
   
  //if pressing left and spin is not too fast, spin left
  if (left <= SPIN_LIM)
    setOrient(getOrient() + left * 2);     //speed up until...
  else
    setOrient(getOrient() + SPIN_LIM); //we hit the spin limit.

  //if we have thrust
  if (thrust <= SPEED_LIM && thrust)
    {
      Vector temp;
      temp.setAngle(getOrient());
      v = v - temp;
    }

  //move thhe ship
  v.setX(v.getX() + v.getDX() * .4);
  v.setY(v.getY() + v.getDY() * .4);

  //wrap
  doWrap();
}

/**************************************************
 * event
 * simple function to handle events in the game
 * by returning the orientation
 *************************************************/
inline int Ship :: event()
{
  //just get the orientatoin
  return getOrient();
}
