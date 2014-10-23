#include <iostream>
#include "asteroids.h"
#include "rocks.h"
#include "point.h"
#include "uiDraw.h"
#include "uiInteract.h"

using namespace std;

void callBack(const Interface *pUI, void *p)
{
  Asteroids *pAster = (Asteroids *)p;
    
  pAster->increment();
  pAster->interact();
  pAster->draw();
}

// set the bounds of the drawing rectangle
float Point::xMin = -300;
float Point::xMax =  300;
float Point::yMin =  -200;  
float Point::yMax =  200;

int main(int argc, char ** argv)
{
  Interface ui(argc, argv, "Rock Test");
   Asteroids asteroids;
   
   ui.run(callBack, &asteroids);

   return 0;
}
