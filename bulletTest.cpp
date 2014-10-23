/****************************************
 * UI TEST
 * Just a simple program to test the user
 * interface consisting of uiDraw and uiInteract
 ****************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "bullet.h"
#include <iostream>


using namespace std;

void callBack(const Interface *pUI, void *p)
{
  Bullet *pBullet = (Bullet *)p;
  pBullet->increment();
  pBullet->draw();
}

// set the bounds of the drawing rectangle
float Point::xMin = -300.0;
float Point::xMax =  300.0;
float Point::yMin =  -200.0;
float Point::yMax =  200.0;

int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "Bullet Test");
   Bullet bullet(0);
   ui.run(callBack, &bullet);

   return 0;
}



