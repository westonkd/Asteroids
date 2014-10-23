###############################################################
#   _____            __                      .__    .___      
#  /  _  \   _______/  |_  ___________  ____ |__| __| _/______
# /  /_\  \ /  ___/\   __\/ __ \_  __ \/  _ \|  |/ __ |/  ___/
#/    |    \\___ \  |  | \  ___/|  | \(  <_> )  / /_/ |\___ \ 
#\____|__  /____  > |__|  \___  >__|   \____/|__\____ /____  >
#        \/     \/            \/                     \/    \/  
# Program:
#     Project 04, Asteroids
#     Brother Helfrich, CS165
# Author:
#     Weston Dransfield - 100%
# Summary:
#     This program allows players to engage in the very fun 
#     game of asteroids. I'm not sure if this was extra 
#     credit or just part of the assignment, but
#     when asteroids break from a bullet hit, the 
#     velocity of the bullet is taken into the account
#     of the way the rocks spread. For other extra credit
#     I added a score system. If you beat the high score
#     a message appears letting you know
#
#     Estimated:  15.0 hrs
#     Actual:     14.0 hrs
#       Please describe briefly what was the most difficult part:
#       managing time! I would have liked to spend much more
#       time adding extra features
###############################################################

###############################################################
# Programs:
#    pong:         The playable game
#    shipTest:     Test for ship class
#    inertiaTest:  test for inertia class
#    vectorTest:   test for vector class
#    bulletTest:   test for bullet 
###############################################################
a.out :asteroids.o vector.o inertia.o spinner.o rocks.o prj4.o uiDraw.o uiInteract.o ship.o point.o bullet.o
	g++ -o a.out asteroids.o vector.o inertia.o prj4.o rocks.o uiDraw.o uiInteract.o spinner.o ship.o point.o bullet.o -lglut -lGL -lGLU

shipTest : vector.o inertia.o spinner.o ship.o shipTest.o uiDraw.o point.o uiInteract.o
	g++ -o sTest vector.o inertia.o shipTest.o ship.o uiDraw.o point.o uiInteract.o spinner.o -lglut -lGL -lGLU

inertiaTest : inertia.o point.o inertiaTest.o vector.o 
	g++ -o iTest inertia.o point.o inertiaTest.o vector.o

vectorTest : vector.o point.o vectorTest.o
	g++ -o vTest vector.o point.o vectorTest.o

bulletTest : vector.o bulletTest.o uiDraw.o uiInteract.o point.o bullet.o inertia.o
	g++ -o bTest vector.o bulletTest.o bullet.o uiDraw.o uiInteract.o point.o inertia.o -lglut -lGL -lGLU

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    asteroids.o   the game class
#    bullet.o      bullet class
#    spinner.o     spinner class
#    shipTest.o    test for ship class
#    ship.o        ship class
#    rockTest.o    test for rock class
#    rocks.o       rock classes
#    inertiaTest.o test for inirtia class
#    inertia.o     inertia class
#    vectorTest.o  test for vector class
#    vector.o      vector class
###############################################################
prj4.o : prj4.cpp
	g++ -c prj4.cpp

asteroids.o : asteroids.h asteroids.cpp
	g++ -c asteroids.cpp

bullet.o : bullet.h bullet.cpp
	g++ -c bullet.cpp

bulletTest.o : bulletTest.cpp
	g++ -c bulletTest.cpp

spinner.o : spinner.cpp spinner.h
	g++ -c spinner.cpp

shipTest.o : shipTest.cpp
	g++ -c shipTest.cpp

ship.o : ship.h ship.cpp
	g++ -c ship.cpp

rockTest.o : rockTest.cpp
	g++ -c rockTest.cpp	

rocks.o : rocks.h rocks.cpp
	g++ -c rocks.cpp

inertiaTest.o : inertiaTest.cpp
	g++ -c inertiaTest.cpp

inertia.o : inertia.h inertia.cpp
	g++ -c inertia.cpp

vectorTest.o : vectorTest.cpp 
	g++ -c vectorTest.cpp

vector.o : vector.h vector.cpp
	g++ -c vector.cpp

uiInteract.o : uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

uiDraw.o : uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

point.o : point.cpp point.h
	g++ -c point.cpp

###############################################################
# General rules
###############################################################
clean :
	rm a.out aScore.txt uiTest pong *.o *.tar *# dTest iTest rTest vTest bTest sTest fTest
tar : 
	tar -cf prj4.tar *.cpp *.h makefile	

all :  uiTest pong

