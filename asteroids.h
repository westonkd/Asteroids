/**********************************************************
 * Asteroids.h
 *   Header file for the asteroids game class. 
 * Author
 *   Weston Dransfield
 *********************************************************/

#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include <list>
#include "inertia.h"

class Inertia;   //to resovle a dependancy loop

/**********************************************************
 *class Asteroids
 * This class holds all variables and functions needed to 
 * create and play a game of asteroids. Elements of the
 * game are stored in a standard list
 *********************************************************/
class Asteroids 
{
 public:
  //Constructors
  Asteroids();              //Populates elements list
  ~Asteroids();             //Frees memory in elements list 

  //Public Functions
  
  void addItem(Inertia *p); //adds an item to elements list
  void increment();         //increments the game
  void interact();          //checks and halds user interaction
  void draw() const;        //draws the elments in the list
  void removeDead();        //removes dead items from the list
  int getScore()           {return score;}
  int setScore(int nScore) {score = nScore;}
  bool setIsHighScore(bool isHigh) {isHighScore = isHigh;}
  
  
 private:
  std::list <Inertia *> elements; //holds all elements of game
  int score;
  bool isHighScore;
};

#endif
