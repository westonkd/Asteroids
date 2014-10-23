/***********************************************************************
* vector.h
*   contsins vector class
* Author
*    Weston Dransfield 
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cassert>

#define _USE_MATH_DEFINES
#include <cmath>
#include "point.h"


/**********************************************************************
 * Class Vector
 *    vector class is used as a base for anythig with a point, directin
 *    and a change in x and/or change in y
 ***********************************************************************/

class Vector : public Point
{
 public:
  //constructors
 Vector() : dx(0.0), dy(0.0), Point()                {/*empty*/};
 Vector(float dx, float dy) : dx(dx), dy(dy),Point() {/*empty*/};
 Vector(float dx, float dy, int x, int y) : dx(dx), dy(dy), Point(x,y) {};

  //getters...self explanitory
  float getDX()const    {return dx;                           }
  float getDY()const    {return dy;                           }
  float getMag()const   {return sqrt(pow(dx, 2) + pow(dy, 2));}        
  float getAngle()const ;

  //overloaded operators
  Vector operator+(const Vector & rhs) const; //vector addition
  Vector operator-(const Vector & rhs) const; //vector subtraction
  void operator=(const Vector & rhs);         //assignment
  //output info of vector for debugging or testing
  friend std::ostream & operator<<(std::ostream & out, const Vector & rhs);

  //setters...also self explanitory
  void setAngle(const float angle);
  void setDX(const float newDX)  {dx = newDX;}
  void setDY(const float newDY)  {dy = newDY;}
  void addDX(const float aDX)    {dx += aDX; }
  void addDY(const float aDY)    {dy += aDY; }
  float getMinDist(Vector & b);
  
 private:
  float dx;  //change in x
  float dy;  //change in y
};
#endif 
