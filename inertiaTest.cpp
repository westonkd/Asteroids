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
#include "inertia.h"
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
  Inertia a(2.3, 1.2);
  cout << a;
  return 0;
}
