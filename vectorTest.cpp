/***********************************************************************
* Program:
*    Project 2, Vector Test
*    Brother Helfrich, CS165
* Author:
*    Jason Cooper Smith
* Summary: 
*
*
*    Estimated:  3.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include "vector.h"
#include "point.h"
using namespace std;


float Point::xMin = -128;
float Point::xMax = 128;
float Point::yMin = -128;
float Point::yMax = 128;
   

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOOSE POINTS.
 ***********************************************************************/
int main()
{
  float dx;
  float dy;

  cout << "Enter two vectors.\n" << ">";
  cin >> dx >> dy;
  Vector a(dx,dy);
  cout << "Enter another.\n" << ">";
  cin >> dx >> dy;
  Vector b(dx,dy);

  //test them out
  cout << a << endl;
  cout << b << endl;

  //test assignment addition and subtraction
  Vector c;
  c = a + b;
  cout << "A + B\n"
       << c << endl;

  c = a - b;
  cout << "A - B\n"
       << c << endl;
  //check the set angle function
  float angle;
  while(angle != -1)
    {
      cout << "set angle test:\n";
      cout << "Enter an angle in degrees: ";
      cin >> angle;
      a.setAngle(angle);
      
      cout << a << endl;
    }
  //cout << "MINIMUM DISTANCE\n"
  //   << a.getMinDist(b);
  return 0;
}
