/**********************************************************
 * spinner.cpp
 *   implementation of functions found in spinner.h
 * Author
 *   Weston Dransfield
 *********************************************************/

#include <iostream>
#include "spinner.h"

using namespace std;

/*********************************************************
 * getOrient
 * simple function to get the orientation of spinner
 ********************************************************/
float Spinner :: getOrient() const
{
  return (orientation);
}

//void setOrient(const int newOrient)
//{
//int temp = newOrient;
// while(temp > 360)
//  temp -= 360;
//while(temp < 0)
//  temp += 360;
//}
